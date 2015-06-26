#ifndef ABSTRACTCLIENT_H
#define ABSTRACTCLIENT_H

#include <QObject>
#include <QByteArray>
#include <QTimer>
#include <QIODevice>
#include <QQueue>

#include "mcode.h"
#include "Config.h"

class AbstractClient : public QObject
{
    Q_OBJECT
public:
    explicit AbstractClient(QObject *parent = 0);


    int connectionUptime;
    QByteArray datas();
    virtual bool isConnected() const;

    virtual QIODevice* getConnector();

    /**
     * @brief sendMCode Send code value as M Code to the device connected.
     * @param code
     */
    void sendMCode(QString code);
    void sendMCode(int code);
    void sendCode(QString code);
    void startConnection();

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

protected:
    QByteArray _datas;
    QByteArray _rcp_datas;
    QTimer _uptimeTimer;

signals:
    void dataReady();
    void disconnected();
    void dataWritten( QString data);

public slots:
    void parseSerialDatas();
    void connectionUptimeProcess();
    void sendBufferedData();
    bool isSendBufferEmpty();

protected:
    QIODevice* _connector;
    QQueue<QString> _sendBuffer;
    QTimer _sendTimer;

    int _currentLineNumber;

};

#endif // ABSTRACTCLIENT_H
