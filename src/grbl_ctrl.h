#pragma once

#include <QApplication>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <iostream>

inline constexpr int maxBufferLength{ 127 };

class GrblCtrl final
{
public:
    GrblCtrl() = default;

    bool openPort();
    void grblReset();
    bool sendCommand(QString command);

private:
    int bufferLength();

    struct CommandAttribute
    {
        QString command;
        int length;
        int consoleIndex;
        int tableIndex;
    };
    QList<CommandAttribute> mCommands;
    QList<QString> mQueue;
    QSerialPort mSerialPort;
};