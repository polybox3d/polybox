#ifndef POLYPLEXER_H
#define POLYPLEXER_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QString>
#include <QProcess>

#include "Config.h"

#include "SerialPort.h"
#include "ClosedLoopTimer.h"

/***
 * Connection flowchart
 *
 * PolyboxModule::connectToPrinter()
 *          |
 *          +----> Polyplexer::start()   // Create pipes and multiplexer for packets
 *          |
 *          +----> SerialPort::connectToSerialPort()  // Create connection between this software and a given pipe (serial/Tcp connection)
 *
 * ====================== PingPong process =====================
 *
 * PolyboxModule::_pingPongTimer.start( PINGPONG_DELAY_MS )
 *                             Timer, periodically call PolyboxModule::pingPong() method.
 *
 * PolyboxModule::pingPong() : Send a ping to the server.
 *                             Server can be printer firmware or remote server software.
 *
 * PolyboxModule::parseMCode() : Parse incoming datas. If PONG_M_CODE, reset ping-pong counter.
 *
 * PingPong value :
 *                  idle, or new connection start :
 *                    PolyboxModule::_numberOfMissingPingPong = PINGPONG_NOT_CONNECTED
 *                  New pong parsed with PolyboxModule::parseMCode() :
 *                    PolyboxModule::_numberOfMissingPingPong = PINGPONG_OK
 *                  pingPong() : increment current value of _numberOfMissingPingPong
 ***/

class Polyplexer : public QObject
{
    Q_OBJECT
public:
#define DEAMON_POLY_POLYPLEXER "/dev/ttyDEAMONPOLY"
#define DEAMON_PRINTER_POLYPLEXER "/dev/ttyDEAMONPRINTER"

    enum PrinterSocketType {
        Serial, Tcp
    };

    static Polyplexer* getInstance()
    {
        if ( polyplexerInstance == NULL )
            polyplexerInstance = new Polyplexer();
        return polyplexerInstance;
    }

    ~Polyplexer();

    bool isRunning();
    bool start();
    bool start(QString path, QString port);
    bool restart();
    bool kill();
    void useWindowOutput(bool use_window );
    int error();

    QString portMachine() const { return _portMachine; }
    void setPortMachine( QString port ) { _portMachine = port ; }

    QString pathMachine() const { return _pathMachine; }
    void setPathMachine( QString path ) { _pathMachine = path ; }

    void setPrinterSocketType(PrinterSocketType type ) { _printerSocketType = type ; }
    PrinterSocketType printerSocketType( ) { return _printerSocketType ; }


signals:
public slots:
    bool stop();
    void finished(int exitCode, QProcess::ExitStatus exitStatus);

private:

    explicit Polyplexer(QObject *parent = 0);
    /** Link between Polybox Machine(board) and the PC    **/
    QString _portMachine;
    QString _pathMachine;


    /**  Link between Pc and PrinterDaemon. TCP or Serial ? **/
    PrinterSocketType _printerSocketType;

    /** Unique static instance of this Class (Polyplexer)**/
    static Polyplexer* polyplexerInstance;

    /** store and handle the external program as separate (Q)Process **/
    QProcess* _polyplexer;
    bool _useOutputWindow;

    void manageWindow();
};

#endif // POLYPLEXER_H
