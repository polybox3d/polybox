#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>
/**
 * @brief The Updater class Constructs a class to check and update PolyboxSoftware. Retreive value from a server and compile it.
 *
 * @todo
 */
class Updater : public QObject
{
    Q_OBJECT
public:
    explicit Updater(QObject *parent = 0);

signals:

public slots:

};

#endif // UPDATER_H
