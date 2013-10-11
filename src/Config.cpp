#include "Config.h"

Config::Config()
{
}

QString Config::pathToHomeDirectory="/home/poly/";
QString Config::pathToLinuxCNC=Config::pathToHomeDirectory+"linuxcnc/";
QString Config::pathToWebcamDevice="/dev/";
QString Config::webcamName="video0";
QString Config::linuxCNCCommand="linuxcnc";
QString Config::scannerLaserPath=Config::pathToHomeDirectory+"/fabscan100/qtTest/";
int Config::motherboardBaudrate=115200;
bool Config::bypassCheck = true ;
QColor Config::colorLabviewFaceSelected = QColor( 70, 230, 255 );
QString Config::ambiancePathFolder=":/xml/ambiances";

float Config::bedTempPla=60;
float Config::bedTempAbs=75;
float Config::bedTempNylon=70;
