#ifndef SCANNERMODULE_H
#define SCANNERMODULE_H

#include <QObject>


#include "AbstractModule.h"
#include "PolyboxModule.h"
#include "mcode.h"
/**
 * @brief The ScannerModule class Inherited QObject and AbstractModule. Provide a class to handle a Scanner.
 * Store data and update values receivedd from PolyboxModule.
 */
class ScannerModule : public QObject, public AbstractModule
{
    Q_OBJECT
public:
    /**
     * @brief ScannerModule Constructs a ScannerModule used to store and process Scanner datas.
     * @param polybox
     * @param parent
     */
    explicit ScannerModule(PolyboxModule* polybox, QObject *parent = 0);

    /**
     * @brief isReady Virtual function inherited from AbstractModule. Return the Scanner value. Is the Scanner ready to be used ?
     * @return
     */
    virtual bool isReady() const ;
    /**
     * @brief updateComponents Updates components stored based on datas received from PolyboxModule / SerialPort.
     */
    virtual void updateComponents();

    /**
     * @brief webcamPlugged Is the WebCam plugged to the Box ?
     * @return True if the webcam is correctly connected and detected by the Box
     */
    bool webcamPlugged() const ;
    /**
     * @brief primesensePlugged Is the Primesense plugged and detected ?
     * @return  True if the depth-sensor is detected. False otherwise.
     */
    bool primesensePlugged() const;
    /**
     * @brief turntablePlugged Is the turntable detected ?
     * @return Return true if the turntable is detected and plugged. False otherwise.
     */
    bool turntablePlugged() const;

protected:
    virtual void initAll();

private:

    bool _webcamPlugged;
    bool _primesencePlugged;
    bool _turntablePlugged;
};

#endif // SCANNERMODULE_H

