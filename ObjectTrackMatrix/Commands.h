#ifndef COMMANDS_H
#define COMMANDS_H

#include <QByteArray>

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

    // Using Commands
    QByteArray BuildCommand(uint8_t cmd, uint8_t id = 0, uint16_t data = 0);

    // TODO unpack command -- take command byts and return int of cmd id and data
    // TODO DoesCommand_Send/Recieve_ID/Data(int cmd) -- functions that interpret _commandArguments array

    // conversions
    QByteArray UintToHexBytes(uint value, uint nBytes);
    QString UintToHex(uint value);

    // byte characters
    QByteArray STX();
    QByteArray ETX();

    // getters
    int nObjects() const;
    int nBytes_STX() const;
    int nBytes_cmd() const;
    int nBytes_id() const;
    int nBytes_data() const;
    int nBytes_ETX() const;
    int nBytes_command();

    // setters
    void setNObjects(int nObjects);

private:
    // number of objects on matrix
    int _nObjects = 12;

    // number of bytes
    int _nBytes_STX  = 1;
    int _nBytes_cmd  = 1;
    int _nBytes_id   = 1;
    int _nBytes_data = 2;
    int _nBytes_ETX  = 1;

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
