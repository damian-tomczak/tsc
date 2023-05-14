#pragma once

#include "ui.h"
#include "gcode_tbl_model.h"
#include "gcode_parser.h"
#include "gcode_view_parser.h"
#include "gcode_drawer.h"
#include "tool_drawer.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTime>
#include <QTextStream>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

#include <iostream>

inline constexpr int maxBufferLength{ 127 };

struct CommandAttributes
{
    int length{};
    int tableIndex{ -1 };
    QString command;
};

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    void processFile(QString fileName);
    void updateControlsState();
    void sendNextFileCommands();
    int bufferLength();
    void sendCommand(QString command, int idx);
    bool openPort();
    void reset();
    void searchPorts();
    QString getPort() { return mUi.pConnPortCbo->currentText(); }
    QString getBaud() { return mUi.pConnBaudCbo->currentText(); }
    void sendConsole();

    QList<CommandAttributes> mCommands;
    GcodeViewParser mGcodeViewParser;
    Ui mUi{};
    int mFileCommandIndex{};
    QSerialPort mSerialPort;
    GcodeDrawer* mpGcodeDrawer;
    ToolDrawer mToolDrawer;
    GcodeTblModel mTblModel;
    QTimer mTimerConnection;
    QTimer mTimerStateQuery;
    bool mIsFileLoading{};
    bool mIsFileSending{};
    bool mIsStopped{};

private slots:
    void onSerialPortError(QSerialPort::SerialPortError e);
    void onSerialPortReadyRead();
    void onTimerConnection();
    void onTimerStateQuery();

    void on_Connect_clicked();
    void on_FileOpen_triggered();
    void on_About_triggered();
    void on_Constraints_triggered();
    void on_Send_clicked();
    void on_Refresh_clicked() { searchPorts(); }
    void on_Stop_clicked();
    void on_ConsoleSend_clicked() { sendConsole(); }

};