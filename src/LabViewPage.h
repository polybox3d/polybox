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

#include <iostream>

#include "LabViewModule.h"
#include "LabViewJPH.h"

using namespace std;

namespace Ui {
class LabViewPage;
}

class LabViewPage : public QWidget
{
    Q_OBJECT

public:
    explicit LabViewPage(LabViewModule* labview, QWidget *parent = 0);
    ~LabViewPage();

    void setSelectedFacesLight(int light, bool horizontale = true, bool verticale = true);
    void importFromXmlFile(QString filename );
    void loadDefaultAmbiances( QString folder_path );


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

    void on_intensite_2_valueChanged(int value);

    void on_intensite_3_valueChanged(int value);

    void on_intensiteSpin_2_valueChanged(int arg1);

    void on_intensiteSpin_3_valueChanged(int arg1);

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

private:
    void setLight(int light, bool horizontale=true, bool verticale=true);
    void processFaceClick(Face* face, QPushButton* face_button, QString base_name);
    void setActivateLightControl( bool activated );
    QStringList getAllCamera(QString path_directory);

    void parseFace( QXmlStreamReader* xml );

    Ui::LabViewPage *ui;
    LabViewModule* _labview;

    QFile* _currentProfile;

    QVector<Face*> _selectedFaces;
    LabViewJPH* _handler;
};

#endif // LABVIEW_H
