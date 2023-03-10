#include "Commands.h"

#include <QDebug>

Commands::Commands()
{
//    QByteArray c =  BuildCommand(TRIAL, 2, 1);
//    qDebug() << c;

//    qDebug() << c[0];
//    qDebug() << c[1];
//    qDebug() << c[2];
//    qDebug() << c[3];
//    qDebug() << c[4];
//    qDebug() << c[5];

//    QList<int> l = UnpackCommand(c);
//    qDebug() << l;
}

//QByteArray Commands::BuildCommand(uint8_t cmd, uint8_t id, uint16_t data)
//{
//    // check that command exists
//    if(!DoesCommandExist(cmd)){
//        throw std::invalid_argument("Command does not exist.");
//    }
//    // check that ID is valid
//    if(id > _nObjects) {
//        throw std::invalid_argument("ID of object does not exist.");
//    }
//    // check that id is provided if needed
//    if( DoesCommandSendID(cmd) ^ (id!=0) ) { // xor
//        throw std::invalid_argument("Command needs an ID.");
//    }
//    // check that data is provided if needed
//    if( DoesCommandSendData(cmd) ^ (data!=0)) {
//        throw std::invalid_argument("Command needs data.");
//    }

//    // add each part of command packet
//    QByteArray command;
//    command.append( STX() );
//    command.append( UintToHexBytes(cmd,  _nBytes_cmd)  ); // convert integers into hexidecimal, then to bytes
//    command.append( UintToHexBytes(id,   _nBytes_id)   ); // " "
//    command.append( UintToHexBytes(data, _nBytes_data) ); // " "
//    command.append( ETX() );

//    return command;
//}

//QList<int> Commands::UnpackCommand(QByteArray cmdPacket)
//{
//    // check for proper length
//    if(cmdPacket.length() != nBytes_command()){
//        throw std::invalid_argument("Command is incorrect size.");
//    }

////    int cmd  = HexBytesToInt(cmdPacket[1]);
////    int id   = HexBytesToInt(cmdPacket[2]);
////    int data = HexBytesToInt(cmdPacket[3] + cmdPacket[4]);


//    QList<int> commands;
////    commands.append(cmd);
////    commands.append(id);
////    commands.append(data);

//    return commands;
//}

bool Commands::DoesCommandSendID(int cmd)
{
    return _commandArguments[cmd][SENDSID];
}

bool Commands::DoesCommandSendData(int cmd)
{
    return _commandArguments[cmd][SENDSDATA];
}

bool Commands::DoesCommandRecieveID(int cmd)
{
    return _commandArguments[cmd][RECIEVESID];
}

bool Commands::DoesCommandRecieveData(int cmd)
{
    return _commandArguments[cmd][RECIEVESDATA];
}

bool Commands::DoesCommandExist(int cmd)
{
    // command must be 0-9
    if( cmd < NCOMMANDS && cmd >= 0){
        return true;
    }
    return false;
}

bool Commands::DoesIdExist(int id)
{
    // ID must be 1-12
    if(id > 0 && id <= _nObjects){
        return true;
    }
    return false;
}

//QByteArray Commands::UintToHexBytes(uint value, uint nBytes)
//{
//    // initialize
//    QByteArray final;

//    // convert number to bytes
//    QByteArray bValue = QByteArray::fromHex(UintToHex(value).toLatin1());
//    int add = nBytes - bValue.length();

//    // value is too small
//    if(add > 0){
//        for(int i=0; i<add; i++){
//            // add zeros to beginning
//            final.append(QByteArray::fromHex(QString("0").toLatin1()));
//        }
//        // add value to lsb
//        final.append(bValue);
//    }
//    // value is too large
//    else if(add < 0){
//        throw std::invalid_argument("value to large for byte allotment");
//    }
//    // value right size
//    else
//    {
//        final.append(bValue);
//    }

//    return final;
//}

//QString Commands::UintToHex(uint value)
//{
//    return QString::number(value, 16);
//}

//int Commands::HexBytesToInt(QByteArray ba)
//{

//}

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
    return (_nBytes_STX+_nBytes_cmd+_nBytes_id+_nBytes_data+_nBytes_ETX);
}

// ===== SETTER =====
void Commands::setNObjects(int nObjects)
{
    _nObjects = nObjects;
}
