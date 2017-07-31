#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = 0);

signals:

public slots:
};

#endif // NETWORK_H
