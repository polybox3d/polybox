#include "MaintenanceChecker.h"

MaintenanceChecker::MaintenanceChecker(QObject *parent) :
    QObject(parent)
{
}

bool MaintenanceChecker::check()
{
    /*QSettings().beginGroup( CHECKER_GROUP );

    QStringList keys = QSettings().allKeys();
    QString key;
    foreach (key, keys)
    {
        QSettings().value(key);
    }
    QSettings().endGroup();
*/
    if ( QSettings().value(QString(CHECKER_GROUP)+"/lastLevelingDate",000000).toDate() <= (QDate::currentDate().addDays( -15 ))  )
    {
        MainWindow::errorWindow( tr("It has been a long time since the last table leveling.\n\n You should level your table.") );
    }
    return true;
}
