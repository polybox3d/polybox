#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QProcess>
#include <QDir>
#include <QStringList>
#include <QTimer>

#include "qextserialport.h"
#include "Config.h"
/**
 * @brief The SerialPort class Constructs a classs based of QextSerialPort. Provides an overlay for Serial Communication through USB/COM
 */
class SerialPort : public QObject
{
    Q_OBJECT
public:
    static SerialPort* getSerial()
    {
        if ( serialPortInstance == NULL )
            serialPortInstance = new SerialPort();
        return serialPortInstance;
    }
    /**
     * @brief connectToSerialPort Connect the current serial with defautl value and setting (115200baudrate, 8b, no parity, 1 stop)
     * @return
     */
    bool connectToSerialPort();
    /**
     * @brief sendMCode Send code string added by a M letter at the beggining, to the device connected.
     * @param code
     */
    void sendMCode(QString code);
    /**
     * @brief sendMCode Send code value as M Code to the device connected.
     * @param code
     */
    void sendMCode(int code);

    void sendCode(QString code);

    QString path();
    QString name();

    QByteArray datas(){ return _datas; }

    static QStringList getDevicesNames( QString path, QString pattern="*" )
    {
        QDir device_dir( path );
        return device_dir.entryList(QStringList( pattern ),QDir::System, QDir::Name) ;
    }
    static long embeddedstr2l(QString str, int idx )
    {
        return strtol(&str.toStdString().c_str()[idx], NULL, 10);
    }
    static void nextField(QString &str, int &idx)
    {
        while( str[idx]!=' ' && str[idx]!='\0') idx++; // search next whitespace
        if ( str[idx]=='\0' )
            return;
        while(str[idx]==' ' && str[idx]!='\0') idx++; // skip leading whitespace
    }
    static void nextValue(QString &str, int &idx)
    {
        while( str[idx]!=':' && str[idx]!='\0') idx++; // search next whitespace
        if ( str[idx]=='\0' )
            return;
        else
            idx++;
    }
    static void parseTrueFalse( bool* item, QCharRef code ){
        if ( code == '1' ) *item= true;
        else if ( code == '0' ) *item = false;
        else *item = false;
    }

    void setName( QString name );
    void setPath( QString path );
    bool isConnected() const;
    void disconnectPort();

    int connectionUptime;

signals:
    void dataReady();
    void disconnected();

public slots:
    void parseSerialDatas();
    void connectionUptimeProcess();

private:
    explicit SerialPort(QObject *parent = 0);
    static SerialPort* serialPortInstance;
    QextSerialPort* _port;
    QString _path;
    QString _name;
    QByteArray _datas;
    QByteArray _rcp_datas;
    QTimer _uptimeTimer;

};

#endif // SERIALPORT_H
