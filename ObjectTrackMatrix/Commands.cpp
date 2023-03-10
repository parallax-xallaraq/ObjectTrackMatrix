#include "Commands.h"

#include <QDebug>

Commands::Commands()
{

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
    // get sublists
    QList<bool> cmd  = bits.mid(_nBits_STX, _nBits_cmd);
    QList<bool> id   = bits.mid(_nBits_STX+_nBits_cmd, _nBits_id);
    QList<bool> data = bits.mid(_nBits_STX+_nBits_cmd+_nBits_id, _nBits_data);

    // store value as integer
    QList<int> command;
    command.append(BitsToUint(cmd));
    command.append(BitsToUint(id));
    command.append(BitsToUint(data));

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
