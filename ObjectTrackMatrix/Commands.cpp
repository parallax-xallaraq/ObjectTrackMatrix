#include "Commands.h"

#include <QDebug>

Commands::Commands()
{

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

int Commands::nBytes_packet()
{
    return (_nBytes_STX+_nBytes_cmd+_nBytes_id+_nBytes_data);
}

// ===== SETTER =====
void Commands::setNObjects(int nObjects)
{
    _nObjects = nObjects;
}
