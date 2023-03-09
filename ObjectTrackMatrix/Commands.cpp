#include "Commands.h"

#include <QDebug>

Commands::Commands()
{
    qDebug() << BuildCommand(PING, 0, 256);

}

QByteArray Commands::BuildCommand(uint8_t cmd, uint8_t id, uint16_t data)
{
    // check that ID is valid
    if(id > _nObjects) {
        throw std::invalid_argument("ID of object does not exist.");
    }

    // add each part of command packet
    QByteArray command;
    command.append( STX() );
    command.append( UintToHexBytes(cmd,  _nBytes_cmd)  ); // convert integers into hexidecimal, then to bytes
    command.append( UintToHexBytes(id,   _nBytes_id)   ); // " "
    command.append( UintToHexBytes(data, _nBytes_data) ); // " "
    command.append( ETX() );

    return command;
}



QByteArray Commands::UintToHexBytes(uint value, uint nBytes)
{
    // initialize
    QByteArray final;

    // convert number to bytes
    QByteArray bValue = QByteArray::fromHex(UintToHex(value).toLatin1());
    int add = nBytes - bValue.length();

    // value is too small
    if(add > 0){
        for(int i=0; i<add; i++){
            // add zeros to beginning
            final.append(QByteArray::fromHex(QString("0").toLatin1()));
        }
        // add value to lsb
        final.append(bValue);
    }
    // value is too large
    else if(add < 0){
        throw std::invalid_argument("value to large for byte allotment");
    }
    // value right size
    else
    {
        final.append(bValue);
    }

    return final;
}

QString Commands::UintToHex(uint value)
{
    return QString::number(value, 16);
}

QByteArray Commands::STX()
{
    QByteArray stx;
    stx.append(0x02);
    return stx;
}

QByteArray Commands::ETX()
{
    QByteArray etx;
    etx.append(0x03);
    return etx;
}

// ===== GETTERS ======

int Commands::nObjects() const
{
    return _nObjects;
}

int Commands::nBytes_STX() const
{
    return _nBytes_STX;
}

int Commands::nBytes_cmd() const
{
    return _nBytes_cmd;
}

int Commands::nBytes_id() const
{
    return _nBytes_id;
}

int Commands::nBytes_data() const
{
    return _nBytes_data;
}

int Commands::nBytes_ETX() const
{
    return _nBytes_ETX;
}

int Commands::nBytes_command()
{
    return (_nBytes_STX+_nBytes_cmd+_nBytes_id+_nBytes_data);
}

// ===== SETTER =====
void Commands::setNObjects(int nObjects)
{
    _nObjects = nObjects;
}
