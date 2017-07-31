#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);

    QString getUserName() const;
    void setUserName(const QString &value);

private:
    QString userName;
signals:

public slots:
};

#endif // MODEL_H
