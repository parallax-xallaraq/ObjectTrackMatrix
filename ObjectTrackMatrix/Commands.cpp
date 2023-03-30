#include "Commands.h"

#include <QDebug>

Commands::Commands()
{
    QByteArray ba = BuildCommand(Commands::NTRIALS, 0, 50);
    qDebug() << ba;
//    qDebug() << ba.toHex();
    QList<uint> vals = UnpackCommand(ba);
    qDebug() << vals;

//    qDebug() << QString(ba[0]);
//    qDebug() << QString(ba[1]);
//    qDebug() << QString(ba[2]);
//    qDebug() << QString(ba[3]);
//    qDebug() << QString(ba[4]);
//    qDebug() << QString(ba[5]);
}

QByteArray Commands::BuildCommand(uint8_t cmd, uint8_t id, uint16_t data)
{
    ValidateCommand(cmd,id,data);

    QString cmd_s  = UintToHex(cmd);
    QString id_s   = UintToHex(id);
    QString data_s = UintToHex(data);

    QString packet = cmd_s + id_s;
    if(data_s.length()==1)
    {
        packet += "0";
    }
    packet += data_s;

    QByteArray command;
    command.append( STX() );
    command.append( packet.toUtf8() );
    command.append( ETX() );

    return(command);

//    // add each part of command packet
//    QByteArray command;
//    command.append( STX() );
//    command.append( UintToHexBytes(cmd,  _nBytes_cmd)  ); // convert integers into hexidecimal, then to bytes
//    command.append( UintToHexBytes(id,   _nBytes_id)   ); // " "
//    command.append( UintToHexBytes(data, _nBytes_data) ); // " "
//    command.append( ETX() );

//    return command;
}

QList<uint> Commands::UnpackCommand(QByteArray cmdPacket)
{
    // check for proper length
    if(cmdPacket.length() != nBytes_command()){
        throw std::invalid_argument("Command is incorrect size.");
    }

    QList<uint> commands;
    commands.append( HexToUint( QString(cmdPacket[1]) ) );
    commands.append( HexToUint( QString(cmdPacket[2]) ) );
    commands.append( HexToUint( QString(cmdPacket[3]) + QString(cmdPacket[4]) ) );

//    int cmd  = HexBytesToInt(&cmdPacket[1]);
//    int id   = HexBytesToInt(&cmdPacket[2]);
////    int data = HexBytesToInt(cmdPacket[3] + cmdPacket[4]);


//    commands.append(cmd);
//    commands.append(id);
////    commands.append(data);

    return commands;
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

uint Commands::HexToUint(QString value)
{
    bool ok;
    return value.toUInt(&ok,16);
}

int Commands::HexBytesToInt(QByteArray ba)
{
    return(0);
}

//QList<bool> Commands::BuildCommand(uint8_t cmd, uint8_t id, uint16_t data)
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
//      }

//    // build command packet
//    QList<bool> command;
//    command.append(STX());
//    command.append(UintToBits(cmd,_nBits_cmd));
//    command.append(UintToBits(id, _nBits_id));
//    command.append(UintToBits(data, _nBits_data));
//    command.append(ETX());

//    return command;
//}

//QList<int> Commands::UnpackCommand(QList<bool> bits)
//{
//    // get sublists
//    QList<bool> cmd  = bits.mid(_nBits_STX, _nBits_cmd);
//    QList<bool> id   = bits.mid(_nBits_STX+_nBits_cmd, _nBits_id);
//    QList<bool> data = bits.mid(_nBits_STX+_nBits_cmd+_nBits_id, _nBits_data);

//    // store value as integer
//    QList<int> command;
//    command.append(BitsToUint(cmd));
//    command.append(BitsToUint(id));
//    command.append(BitsToUint(data));

//    return command;
//}

//QList<bool> Commands::UintToBits(uint value, uint n)
//{
//    // check that value is in range
//    if( value > (qPow(2,n) - 1)){
//        throw std::invalid_argument("Out of range.");
//    }

//    // initialize variables
//    QList<bool> bits;
//    int temp = value;

//    // calculate binary numver
//    for(uint i=0; i<n; i++){
//        bits.prepend(bool(temp % 2));
//        temp = temp / 2;
//    }

//    return bits;
//}

//int Commands::BitsToUint(QList<bool> bits)
//{
//    // initialize
//    int value = 0;
//    int n = bits.length();

//    // calculate decimal
//    for(int i=0; i<n; i++){
//        value += int(bits.at(i)) * qPow(2, n-i-1);
//    }

//    return value;
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

//QList<bool> Commands::STX()
//{
//    return UintToBits(0x02, _nBits_STX);
//}

//QList<bool> Commands::ETX()
//{
//    return UintToBits(0x03, _nBits_ETX);
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

//int Commands::nObjects() const
//{
//    return _nObjects;
//}

//int Commands::nBits_STX() const
//{
//    return _nBits_STX;
//}

//int Commands::nBits_cmd() const
//{
//    return _nBits_cmd;
//}

//int Commands::nBits_id() const
//{
//    return _nBits_id;
//}

//int Commands::nBits_data() const
//{
//    return _nBits_data;
//}

//int Commands::nBits_ETX() const
//{
//    return _nBits_ETX;
//}

//int Commands::nBits_command()
//{
//    return (_nBits_STX+_nBits_cmd+_nBits_id+_nBits_data+_nBits_ETX);
//}

// ===== SETTER =====

void Commands::setNObjects(int nObjects)
{
    _nObjects = nObjects;
}

void Commands::ValidateCommand(uint8_t cmd, uint8_t id, uint16_t data)
{
    // check that command exists
    if(!DoesCommandExist(cmd)){
        throw std::invalid_argument("Command does not exist.");
    }
    // check that ID is valid
    if(id > _nObjects) {
        throw std::invalid_argument("ID of object does not exist.");
    }
    // check that id is provided if needed
    if( DoesCommandSendID(cmd) ^ (id!=0) ) { // xor
        throw std::invalid_argument("Command needs an ID.");
    }
    // check that data is provided if needed
    if( DoesCommandSendData(cmd) ^ (data!=0)) {
        throw std::invalid_argument("Command needs data.");
    }
}
