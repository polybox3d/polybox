#ifndef POLYPLEXER_H
#define POLYPLEXER_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QString>
#include <QProcess>

#include "Config.h"

#include "SerialPort.h"


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

    QString portMachine() const { return _portMachine; }
    void setPortMachine( QString port ) { _portMachine = port ; }

    QString pathMachine() const { return _pathMachine; }
    void setPathMachine( QString path ) { _pathMachine = path ; }

    void setPrinterSocketType(PrinterSocketType type ) { _printerSocketType = type ; }
    PrinterSocketType printerSocketType( ) { return _printerSocketType ; }

    QByteArray printerDatas();

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

    static Polyplexer* polyplexerInstance;

    bool _running;
    QProcess* _polyplexer;
    bool _useOutputWindow;

    void manageWindow();
};

#endif // POLYPLEXER_H
