#ifndef SERIALCONTROL_H
#define SERIALCONTROL_H

#include <QSerialPort>
#include <QIODevice>
#include <QByteArray>
#include <QString>
#include <QList>

#include "Commands.h"

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// ====================================

class SerialControl
{
public:
    // constructor and destructor
    SerialControl();
    ~SerialControl();

    // port control
    void OpenPort(QString portName);
    void ClosePort();

    // command packet communication
    void        WritePacket(uint8_t cmd, uint8_t id = 0, uint data = 0);
    QList<uint> ReadPacket(); // use Commands::UnpackedCommandKey for list indexing
    QList<uint> WriteAndReadPacket(uint8_t cmd, uint8_t id = 0, uint data = 0);
    bool        WriteAndReadPacket_CheckMatch(uint8_t cmd, uint8_t id = 0, uint data = 0);

    // general serial communication
    void        Write(QByteArray packet);
    QByteArray  Read(qint64 maxLength);

private:
    // class objects
    Commands * _commands;
    QSerialPort * _port;

    // useful constants
    qint64 _maxlength_readPacket;

    // port parameters
    QIODeviceBase::OpenMode  _mode        = QIODevice::ReadWrite;
    QSerialPort::BaudRate    _baudRate    = QSerialPort::Baud115200;
    QSerialPort::DataBits    _dataBits    = QSerialPort::Data8;
    QSerialPort::Parity      _parity      = QSerialPort::NoParity;
    QSerialPort::StopBits    _stopBits    = QSerialPort::OneStop;
    QSerialPort::FlowControl _flowControl = QSerialPort::NoFlowControl;
};

#endif // SERIALCONTROL_H
