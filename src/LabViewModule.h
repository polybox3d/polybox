#ifndef LABVIEWMODULE_H
#define LABVIEWMODULE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QFileDialog>


#include "AbstractModule.h"
#include "Face.h"

#define PATH_TO_DEVICE "/dev"
class LabViewModule : public QObject, public AbstractModule
{
    Q_OBJECT
public:
    explicit LabViewModule(PolyboxModule *polybox, QObject *parent = 0);
    ~LabViewModule(){}

    QStringList getConnectedCameraPath();

    /**
     * @brief isReady Informe if the LabViewModule is ready to be used. If everything is connected etc..
     * @return Return True if the moduel is ready, false otherwise.
     */
    virtual bool isReady() const;
    /**
     * @brief updateComponents Updates contents, like temps, tools's status. Retreive data from serial communication.
     */
    virtual void updateComponents();
    virtual void parseMCode(QByteArray stream);

    void setCamera( QString cam );
    void startCamera();
    void startRecording();
    static QProcess* startCamera(QProcess* process, QString camera);

    void initFaceClass();
    void setFaceLight(QString face_name, int horizontale, int verticale);
    void setFaceLight(int face_id, int horizontale, int verticale);

    void exportXmlAllFaces(QXmlStreamWriter *xml);
    void parseGlobalcolor(QXmlStreamReader *xml);
    void  saveToXmlFile(QString filename);
    QColor* currentColor(){ return &_currentColor;}
    void setAllFacesLight(int light, bool horizontale, bool verticale);

    int getGlobalIntensityH(){ return _top.h(); }
    int getGlobalIntensityV(){ return _top.v(); }

    QColor getGlobalColor(){ return _currentColor; }
    void setGlobalColor(QColor c);
    void sendGlobalColor();
    static QStringList getAllCamera(QString path_directory);

    Face _left;
    Face _right;
    Face _top;
    Face _bot;
    Face _front;
    Face _back;

signals:
    void updateUI();

public slots:

private:
    /**
     * @brief initAll Initilalize all components.
     */
    virtual void initAll();

    QColor _currentColor;


    QString _selectedCamera;
    QProcess* _mediaPlayer;

};

#endif // LABVIEWMODULE_H
