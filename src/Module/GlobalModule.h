#ifndef GLOBALMODULE_H
#define GLOBALMODULE_H

#include <QObject>

#include "MainWindow.h"
#include "AbstractModule.h"
#include "Temperature.h"
/**
 * @brief The GlobalModule class Inheriterd from AbstractModule. Handle all global i/o, like ATU, arudino connected etc...
 */
class GlobalModule : public QObject, public AbstractModule
{
    Q_OBJECT
public:

    enum PolyMode { PrinterMode, CNCMode };

    explicit GlobalModule(PolyboxModule* polybox, QObject *parent = 0);

    virtual bool isReady() const ;
    virtual void updateComponents();


    bool boxOpen() const;
    bool ATUok() const;
    bool icOpen() const;
    bool preasiATUok() const;
    bool toolATUok() const;
    bool arduinoMaitre() const;
    bool arduino1() const;
    bool arduino2() const;
    bool arduino3() const;
    bool arduino4() const;
    bool command() const;
    bool power() const;
    bool webcamPlugged() const;
    int ram() const;
    unsigned int error() const;
    PolyMode polyMode() const;
    void resetError();

    Temperature tempIC();
    void changePolyMode( PolyMode new_mode );

    virtual void parseMCode(QByteArray stream);

signals:
    void updateUI();

public slots:

protected:
    void initAll();
private:
    bool _icOpen;
    bool _toolATUok;
    bool _preasiATUok;
    bool _boxOpen;
    bool _ATUok;
    bool _arduinoMaitre;
    bool _arduino1;
    bool _arduino2;
    bool _arduino3;
    bool _arduino4;
    bool _command;
    bool _power;
    bool _webcamPlugged;
    int _ram;
    unsigned int _error;
    polyMode _polyMode;

    Temperature _tempIC;
    ///tempIC
};

#endif // GLOBALMODULE_H
