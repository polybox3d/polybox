#ifndef LABVIEWMODULE_H
#define LABVIEWMODULE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QProcess>

#define PATH_TO_DEVICE "/dev"
class LabViewModule : public QObject
{
    Q_OBJECT
public:
    explicit LabViewModule(QObject *parent = 0);
    QStringList getConnectedCameraPath();
signals:

public slots:

};

#endif // LABVIEWMODULE_H
