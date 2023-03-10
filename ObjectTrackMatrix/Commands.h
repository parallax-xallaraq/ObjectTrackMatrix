#ifndef COMMANDS_H
#define COMMANDS_H

#include <QByteArray>
#include <QBitArray>
#include <QList>
#include <QtMath>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
// Date: 3/8/2023
// ====================================

class Commands
{
public:
    // constructor
    Commands();

    // command numbers
    enum CommandNum {
        PING,       // 0
        TESTLED,    // 1
        BATTERY,    // 2
        CALIBRATE,  // 3
        NTRIALS,    // 4
        TRIAL,      // 5
        SEPARATION, // 6
        TIMEOUT,    // 7
        SAMPLERATE, // 8
        STREAM,     // 9
        NCOMMANDS   // number of commands
    };
    // array index key for unpacked commands
    enum UnpackedCommandKey {
        CMD,
        ID,
        DATA
    };

    // Using Commands
    QList<bool> BuildCommand(uint8_t cmd, uint8_t id = 0, uint16_t data = 0);
    QList<int> UnpackCommand(QList<bool> bits);

    // conversions
    QList<bool> UintToBits(uint value, uint n);
    int BitsToUint(QList<bool> bits);

    // check command parameters
    bool DoesCommandSendID(int cmd);
    bool DoesCommandSendData(int cmd);
    bool DoesCommandRecieveID(int cmd);
    bool DoesCommandRecieveData(int cmd);
    bool DoesCommandExist(int cmd);
    bool DoesIdExist(int id);

    // bit characters
    QList<bool> STX();
    QList<bool> ETX();

    // getters
    int nObjects()      const;
    int nBits_STX()    const;
    int nBits_cmd()    const;
    int nBits_id()     const;
    int nBits_data()   const;
    int nBits_ETX()    const;
    int nBits_command();

    // setters
    void setNObjects(int nObjects);

private:

    // number of objects on matrix
    int _nObjects = 12;

    // number of bytes
    int _nBits_STX  = 8;
    int _nBits_cmd  = 8;
    int _nBits_id   = 8;
    int _nBits_data = 16;
    int _nBits_ETX  = 8;

    // corresponds to array index in _commandArguments[]
    enum CommandArgRequirements {
        SENDSID,
        SENDSDATA,
        RECIEVESID,
        RECIEVESDATA
    };

    // structure of each command
    // // true if the command takes an argument,
    // // false otherwise.
    bool _commandArguments[NCOMMANDS][4] = {
        {false,false,false,false},  // PING
        {true ,true ,false,false},  // TESTLED
        {true ,false,true ,true },  // BATTERY
        {true ,false,false,false},  // CALIBRATE
        {false,true ,false,false},  // NTRIALS
        {true ,true ,false,false},  // TRIAL
        {false,true ,false,false},  // SEPARATION
        {false,true ,false,false},  // TIMEOUT
        {false,true ,false,false},  // SAMPLERATE
        {false,true ,true , true}   // STREAM
    };//{sends ID, sends data, recieves ID, recieves data}

};

#endif // COMMANDS_H
