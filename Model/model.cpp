#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{

}

QString Model::getUserName() const
{
    return userName;
}

void Model::setUserName(const QString &value)
{
    //TODO: make a regular expression to prevent wrong user name input
    userName = value;
}
