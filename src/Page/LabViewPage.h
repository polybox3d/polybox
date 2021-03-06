#ifndef LABVIEW_H
#define LABVIEW_H

#include <QWidget>

#include "MainWindow.h"
#include "HomeButton.h"
#include "Face.h"

#include <QProcess>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QColor>
#include <QFileDialog>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDataStream>
#include <QColorDialog>
#include <QRgb>

#include <iostream>

#include "LabViewModule.h"
#include "LabViewJPH.h"
#include "ATUButton.h"
#include "OnOffButton.h"
#include "DialogBroadcast.h"

using namespace std;

namespace Ui {
class LabViewPage;
}

class LabViewPage : public QWidget
{
    Q_OBJECT

public:
    explicit LabViewPage(LabViewModule* labview, QWidget *parent = 0, bool small_ui=false);
    ~LabViewPage();

    void setSelectedFacesLight(int light, bool horizontale = true, bool verticale = true);
    void importFromXmlFile(QString filename );
    void loadDefaultAmbiances( QString folder_path );
    void loadCameras();
    bool eventFilter(QObject* watched, QEvent* event);


#define BASE_STYLESHEET_FACE_BUTTON "background-image: url("
#define QRC_STYLESHEET_FACE_BUTTON ":/img/img/"



public slots:
    void updateUI();
    void setJoypad( QJoystick* joypad );
    void disableJoypad();


private slots:
    void on_startVisu_clicked();

    void on_loadProfil_clicked();

    void on_saveProfil_clicked();

    void on_r_valueChanged(int value);

    void on_g_valueChanged(int value);

    void on_b_valueChanged(int value);

    void on_rSpin_valueChanged(int arg1);

    void on_gSpin_valueChanged(int arg1);

    void on_bSpin_valueChanged(int arg1);

    void on_intensite_valueChanged(int value);

    void on_intensiteSpin_valueChanged(int arg1);

    void on_startRecording_clicked();

    void on_backFace_clicked();

    void on_rightFace_clicked();

    void on_leftFace_clicked();

    void on_topFace_clicked();

    void on_bottomFace_clicked();

    void on_frontFace_clicked();

    void on_globalLightRadio_clicked();

    void on_individualLightRadio_clicked();

    void on_selectAmb_currentIndexChanged(int index);

    void on_cameraSelector_currentIndexChanged(int index);

    void on_rgbLineEdit_editingFinished();

    void on_softwareRadio_clicked();

    void on_teleRadio_clicked();

    void on_intensityV_valueChanged(int value);

    void on_intensityHSpin_valueChanged(int arg1);

    void on_intensityVSpin_valueChanged(int arg1);

    void on_intensityH_valueChanged(int value);

    void on_showColor_clicked();

    void on_lockButton_clicked();

    void on_startBroadcast_clicked();

    void on_minimizeMaximize_clicked();

private:
    void setLight(int light, bool horizontale=true, bool verticale=true);
    void setRed(int value );
    void setBlue(int value );
    void setGreen(int value );
    void setAlpha( int value );
    void setColor( QColor color );
    void processFaceClick(Face* face, QPushButton* face_button, QString base_name);
    void setActivateLightControl( bool activated );

    void parseFace( QXmlStreamReader* xml );

    Ui::LabViewPage *ui;
    LabViewModule* _labview;

    QFile* _currentProfile;
    OnOffButton* _onoff;

    QVector<Face*> _selectedFaces;
    LabViewJPH* _handler;
    bool _update;
    bool _vhSliderLocked;
};

#endif // LABVIEW_H
