#include "grbl_ctrl.h"

bool GrblCtrl::openPort()
{
    if (mSerialPort.open(QIODevice::ReadWrite))
    {
        grblReset();
        return true;
    }

    return false;
}

void GrblCtrl::grblReset()
{
    mSerialPort.write(QByteArray(1, (char)24));
}

bool GrblCtrl::sendCommand(QString command)
{
    if (!mSerialPort.isOpen())
    {
        return false;
    }

    if ((bufferLength() + command.length() + 1) > maxBufferLength)
    {
        mQueue.append(command);
    }

    while ((bufferLength() + command.length() + 1) > maxBufferLength)
    {
        qApp->processEvents();
    }

    if (mQueue.length() > 0)
    {
        command = mQueue.takeFirst();
    }

    mSerialPort.write((command + "\r").toLatin1());
}

int GrblCtrl::bufferLength()
{
    int length{};

    for (const auto& ca : mCommands)
    {
        length += ca.length;
    }

    return length;
}