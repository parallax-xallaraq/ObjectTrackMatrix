#include "Commands.h"

#include <QDebug>

Commands::Commands()
{
    QList<bool> c =  BuildCommand(TESTLED, 12, 10);
//    qDebug() << c;

    QList<int> cc = UnpackCommand(c);
    qDebug() << cc.at(CMD);
    qDebug() << cc.at(ID);
    qDebug() << cc.at(DATA);


//    int num = 15;
//    QList<bool> t = UintToBits(num, 4);
//    qDebug() << num;
//    qDebug() << t;

//    int tt = BitsToUint(t);
//    qDebug() << tt;

}

QList<bool> Commands::BuildCommand(uint8_t cmd, uint8_t id, uint16_t data)
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

    // build command packet
    QList<bool> command;
    command.append(STX());
    command.append(UintToBits(cmd,_nBits_cmd));
    command.append(UintToBits(id, _nBits_id));
    command.append(UintToBits(data, _nBits_data));
    command.append(ETX());

    return command;
}

QList<int> Commands::UnpackCommand(QList<bool> bits)
{
    QList<bool> cmdB  = bits.mid(_nBits_STX, _nBits_cmd);
    QList<bool> idB   = bits.mid(_nBits_STX+_nBits_cmd, _nBits_id);
    QList<bool> dataB = bits.mid(_nBits_STX+_nBits_cmd+_nBits_id, _nBits_data);

    int cmdI  = BitsToUint(cmdB);
    int idI   = BitsToUint(idB);
    int dataI = BitsToUint(dataB);

    QList<int> command;
    command.append(cmdI);
    command.append(idI);
    command.append(dataI);

    return command;
}

QList<bool> Commands::UintToBits(uint value, uint n)
{
    // check that value is in range
    if( value > (qPow(2,n) - 1)){
        throw std::invalid_argument("Out of range.");
    }

    // initialize variables
    QList<bool> bits;
    int temp = value;

    // calculate binary numver
    for(uint i=0; i<n; i++){
        bits.prepend(bool(temp % 2));
        temp = temp / 2;
    }

    return bits;
}

int Commands::BitsToUint(QList<bool> bits)
{
    // initialize
    int value = 0;
    int n = bits.length();

    // calculate decimal
    for(int i=0; i<n; i++){
        value += int(bits.at(i)) * qPow(2, n-i-1);
    }

    return value;
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
//    command.append( UintToHexBytes(cmd,  _nBits_cmd)  ); // convert integers into hexidecimal, then to bytes
//    command.append( UintToHexBytes(id,   _nBits_id)   ); // " "
//    command.append( UintToHexBytes(data, _nBits_data) ); // " "
//    command.append( ETX() );

//    return command;
//}

//QList<int> Commands::UnpackCommand(QByteArray cmdPacket)
//{
//    // check for proper length
//    if(cmdPacket.length() != nBits_command()){
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

//QByteArray Commands::UintToHexBytes(uint value, uint nBits)
//{
//    // initialize
//    QByteArray final;

//    // convert number to bytes
//    QByteArray bValue = QByteArray::fromHex(UintToHex(value).toLatin1());
//    int add = nBits - bValue.length();

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

//QByteArray Commands::STX()
//{
//    QByteArray stx;
//    stx.append(0x02);
//    return stx;
//}

//QByteArray Commands::ETX()
//{
//    QByteArray etx;
//    etx.append(0x03);
//    return etx;
//}

QList<bool> Commands::STX()
{
    return UintToBits(0x02, _nBits_STX);
}

QList<bool> Commands::ETX()
{
    return UintToBits(0x03, _nBits_ETX);
}

// ===== GETTERS ======

int Commands::nObjects() const
{
    return _nObjects;
}

int Commands::nBits_STX() const
{
    return _nBits_STX;
}

int Commands::nBits_cmd() const
{
    return _nBits_cmd;
}

int Commands::nBits_id() const
{
    return _nBits_id;
}

int Commands::nBits_data() const
{
    return _nBits_data;
}

int Commands::nBits_ETX() const
{
    return _nBits_ETX;
}

int Commands::nBits_command()
{
    return (_nBits_STX+_nBits_cmd+_nBits_id+_nBits_data+_nBits_ETX);
}

// ===== SETTER =====

void Commands::setNObjects(int nObjects)
{
    _nObjects = nObjects;
}
