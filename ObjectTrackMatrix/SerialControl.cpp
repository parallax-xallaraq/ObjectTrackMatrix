#include "SerialControl.h"
#include <QDebug>

SerialControl::SerialControl()
{
    // initialize
    _commands = new Commands();
    _port     = new QSerialPort();
    _maxlength_readPacket = _commands->nBytes_command();
}

SerialControl::~SerialControl()
{
    ClosePort();

    delete _port;
    _port = nullptr;

    delete _commands;
    _commands = nullptr;
}

void SerialControl::OpenPort(QString portName)
{
    // close port if open
    ClosePort();

    // set port name
    _port->setPortName(portName);

    // open port for read and write
    _port->open(_mode);

    if(_port->isOpen())
    {
        // setup port
        _port->setBaudRate(_baudRate);
        _port->setDataBits(_dataBits);
        _port->setParity(_parity);
        _port->setStopBits(_stopBits);
        _port->setFlowControl(_flowControl);
    }
    else
    {
        throw std::invalid_argument("can't open the port");
    }
}

void SerialControl::ClosePort()
{
    if(_port->isOpen()){
        _port->close();
    }
}

void SerialControl::Write(QByteArray packet)
{
    if(_port->isOpen()){
        _port->write(packet);
    }
    else{
        throw std::invalid_argument("port is closed.");
    }
}

void SerialControl::WritePacket(uint8_t cmd, uint8_t id, uint data)
{
    // write command packet
    QByteArray ba = _commands->BuildCommand(cmd,id,data);
    qDebug() << "WRITE:\t" << ba;
    Write( ba );
}

QList<uint> SerialControl::ReadPacket()
{
    // read number of bytes equal to a full packet. Then unpack the packet into a list.
    QByteArray ba = Read(_maxlength_readPacket);
    qDebug() << "READ:\t" << ba;
    return( _commands->UnpackCommand( ba ) );
}

QList<uint> SerialControl::WriteAndReadPacket(uint8_t cmd, uint8_t id, uint data)
{
    WritePacket(cmd, id, data);
    return(ReadPacket());
}

bool SerialControl::WriteAndReadPacket_CheckMatch(uint8_t cmd, uint8_t id, uint data)
{
    // write
    QList<uint> writePkt = {cmd,id,data};
    WritePacket(cmd, id, data);
    // read
    QList<uint> readPkt = ReadPacket();

    // true if lists match, false otherwise
    return(writePkt==readPkt);
}

QByteArray SerialControl::Read(qint64 maxLength)
{
    // check for open port
    if(_port->isOpen() ){
        // wait for data
        if(_port->waitForReadyRead()){
            return(_port->read(maxLength));
        }
        else{
            throw std::invalid_argument("Timeout when reading data.");
        }
    }
    else{
        throw std::invalid_argument("port is closed.");
    }
}
