#include "Commands.h"

Commands::Commands()
{

}

QByteArray Commands::BuildCommand(uint8_t cmd, uint8_t id, uint data)
{
    // check that command has all required parameters
    ValidateCommand(cmd,id,data);

    // convert to hex
    QString cmd_s  = UintToHex(cmd);
    QString id_s   = UintToHex(id);
    QString data_s = UintToHex(data);

    // extend data to proper length
    while(data_s.length() < _nBytes_data ){
        data_s.prepend("0");
    }

    // build hex packet (size 4)
    QString packet = cmd_s + id_s + data_s;

    // build byte array
    QByteArray command;
    command.append( STX() );
    command.append( packet.toUtf8() );
    command.append( ETX() );

    return command;
}

QList<uint> Commands::UnpackCommand(QByteArray cmdPacket)
{
    // check for proper length
    if(cmdPacket.length() != nBytes_command()){
        throw std::invalid_argument("Command is incorrect size.");
    }

    // convert each part of packet into int
    QList<uint> commands;
    commands.append( HexToUint( QString(cmdPacket[1]) ) );
    commands.append( HexToUint( QString(cmdPacket[2]) ) );
    commands.append( HexToUint( QString(cmdPacket[3]) + QString(cmdPacket[4]) ) );

    // reference commands list using UnpackedCommandKey enum
    return commands;
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

// ===== SETTERS =====

void Commands::setNObjects(int nObjects)
{
    _nObjects = nObjects;
}

// ===== HELPER FUCNTIONS =====

void Commands::ValidateCommand(uint8_t cmd, uint8_t id, uint data)
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
    // check that data can be represented by 4 hex btyes
    if(UintToHex(data).length() > _nBytes_data){
        throw std::invalid_argument("Data packet overflow.");
    }
}
