#include "SerialControl.h"

SerialControl::SerialControl()
{
    // initialize
    _commands = new Commands();
    _port = new QSerialPort();
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
    Write(_commands->BuildCommand(cmd,id,data));
}

QList<uint> SerialControl::ReadPacket()
{
    return( _commands->UnpackCommand( Read(_maxlength_readPacket) ) );
}

QByteArray SerialControl::Read(qint64 maxLength)
{
    if(_port->isOpen()){
        return(_port->read(maxLength));
    }
    else{
        throw std::invalid_argument("port is closed.");
    }
}
