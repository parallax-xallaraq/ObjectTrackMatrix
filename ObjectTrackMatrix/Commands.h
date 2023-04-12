#ifndef COMMANDS_H
#define COMMANDS_H

#include <QList>
#include <QByteArray>

// ====================================
// Created by: Thresa Kelly
// Email: ThresaKelly133@gmail.com
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
    QByteArray BuildCommand(uint8_t cmd, uint8_t id = 0, uint data = 0);
    QList<uint> UnpackCommand(QByteArray ba);

    // conversions
    QString UintToHex(uint value);
    uint HexToUint(QString value);

    // check command parameters
    bool DoesCommandSendID(int cmd);
    bool DoesCommandSendData(int cmd);
    bool DoesCommandRecieveID(int cmd);
    bool DoesCommandRecieveData(int cmd);
    bool DoesCommandExist(int cmd);
    bool DoesIdExist(int id);

    // bit characters
    QByteArray STX();
    QByteArray ETX();

    // getters
    int nObjects()    const;
    int nBytes_STX()  const;
    int nBytes_cmd()  const;
    int nBytes_id()   const;
    int nBytes_data() const;
    int nBytes_ETX()  const;
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
    int _nBytes_data = 4;
    int _nBytes_ETX  = 1;

    // use as _commandArguments[CommandNum][ArgRequirements]
    enum ArgRequirements {
        SENDSID,
        SENDSDATA,
        RECIEVESID,
        RECIEVESDATA
    };

    // true if the command takes an argument, false otherwise.
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
    };

    void ValidateCommand(uint8_t cmd, uint8_t id, uint data);
};

#endif // COMMANDS_H
