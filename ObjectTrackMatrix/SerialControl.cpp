#include "SerialControl.h"

SerialControl::SerialControl()
{
    // initialize
    _port = new QSerialPort();
}

SerialControl::~SerialControl()
{
    ClosePort();

    delete _port;
    _port = nullptr;
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

void SerialControl::WritePacket(QByteArray packet)
{
    if(_port->isOpen()){
        _port->write(packet);
    }
    else{
        throw std::invalid_argument("port is closed.");
    }
}

QByteArray SerialControl::ReadPacket()
{
    return(Read(_maxlength_readPacket));
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

qint64 SerialControl::maxlength_readPacket() const
{
    return _maxlength_readPacket;
}

void SerialControl::setMaxlength_readPacket(qint64 newMaxlength_readPacket)
{
    _maxlength_readPacket = newMaxlength_readPacket;
}
