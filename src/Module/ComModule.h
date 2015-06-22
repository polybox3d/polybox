#ifndef COMMODULE_H
#define COMMODULE_H

#include <QObject>
#include <QByteArray>
#include <QMap>
#include <QQueue>


#include "polyplexer.h"


#define PINGPONG_NOT_CONNECTED     42
#define PINGPONG_MAX_TRIES         2
#define PINGPONG_OK                0
#define PINGPONG_DELAY_MS          4000


class ComModule : public QObject
{
    Q_OBJECT

public:
    static ComModule* getInstance(QObject *parent = 0);
    enum ConnectorType{ Serial, ServerTCP, CLientTCP, Abstract};
    enum ConnectionStatus{ Connected=0, ErrorPolyplexer=2, ErrorConnection=4, Permission=8, NotFound=16, TimeOut=32};
    static QMap<int, QString> connectionStatusMessage;

    int _connectionUptime;


    void initConnectionStatusMessage();

    static u_int16_t Fletcher16( const char* data, int count ) {
       u_int16_t sum1 = 0; u_int16_t sum2 = 0;
       int index;
       for( index = 0; index < count; ++index ) {
          sum1 = (sum1 + data[index]) % 255;
          sum2 = (sum2 + sum1) % 255;
       }
       return (sum2 << 8) | sum1;
    }
    static u_int8_t checksum( const char* data, int count ) {
       u_int8_t sum = 0;
       int index;
       for( index = 0; index < count; ++index ) {
          sum ^= data[index];
       }
       return sum;
    }

    /**
     * @brief sendMCode Send code value as M Code to the device connected.
     * @param code
     */
    void sendMCode(QString code);
    void sendMCode(int code);
    void sendCode(QString code);
    void parseMCode(QByteArray stream);

signals:
    void newData( QByteArray stream );
    void dataWritten( QString data );

public slots:
    void parseData();
    void pingPong();
    void sendBufferedData();


private:
    explicit ComModule(QObject *parent = 0);

    static ComModule* _instance;

    QQueue<QString> _sendBuffer;
    QTimer _sendTimer;
    int _currentLineNumber;
    u_int8_t _numberOfMissingPingPong;
    QTimer _pingPongTimer;

};

#endif // COMMODULE_H