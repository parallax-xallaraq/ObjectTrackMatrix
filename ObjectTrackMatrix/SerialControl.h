#ifndef SERIALCONTROL_H
#define SERIALCONTROL_H

#include <QSerialPort>
#include <QIODevice>
#include <QByteArray>
#include <QString>

class SerialControl
{
public:
    SerialControl();
    ~SerialControl();

    // port control
    void OpenPort(QString portName);
    void ClosePort();

    // serial communication
    void        WritePacket(QByteArray packet);
    QByteArray  ReadPacket();
    QByteArray  Read(qint64 maxLength);

    // getter and setter
    qint64 maxlength_readPacket() const;
    void setMaxlength_readPacket(qint64 newMaxlength_readPacket);

private:
    QSerialPort * _port;

    //
    qint64 _maxlength_readPacket = 8;

    // port parameters
    QIODeviceBase::OpenMode  _mode        = QIODevice::ReadWrite;
    QSerialPort::BaudRate    _baudRate    = QSerialPort::Baud115200;
    QSerialPort::DataBits    _dataBits    = QSerialPort::Data8;
    QSerialPort::Parity      _parity      = QSerialPort::NoParity;
    QSerialPort::StopBits    _stopBits    = QSerialPort::OneStop;
    QSerialPort::FlowControl _flowControl = QSerialPort::NoFlowControl;

};

#endif // SERIALCONTROL_H
