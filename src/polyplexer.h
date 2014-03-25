#ifndef POLYPLEXER_H
#define POLYPLEXER_H

#include <QObject>
#include <QString>

#include "SerialPort.h"

class Polyplexer : public QObject
{
    Q_OBJECT
public:

    static Polyplexer* getInstance()
    {
        if ( polyplexerInstance == NULL )
            polyplexerInstance = new Polyplexer();
        return polyplexerInstance;
    }

    explicit Polyplexer(QObject *parent = 0);

    bool isRunning();
    bool start();
    bool restart();
    bool stop();
    bool kill();
    QString name() const { return _name; }
    QString path() const { return _path; }

signals:


private:

    QString _path;
    QString _name;
    SerialPort* _serial;
    static Polyplexer* polyplexerInstance;

};

#endif // POLYPLEXER_H
