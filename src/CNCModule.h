#ifndef CNCMODULE_H
#define CNCMODULE_H

#include <QObject>

class CNCModule : public QObject
{
    Q_OBJECT
public:
    explicit CNCModule(QObject *parent = 0);

signals:

public slots:

};

#endif // CNCMODULE_H
