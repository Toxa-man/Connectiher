#include "user.h"

User::User()
{

}

User::User(QString name): userName(name)
{

}

QByteArray User::getAudioData() const
{
    return audioData;
}

void User::setAudioData(const QByteArray& value)
{
    audioData = value;
}

QString User::getUserName() const
{
    return userName;
}

void User::setUserName(const QString &value)
{
    userName = value;
}

bool operator ==(const User &left, const User &right)
{
    return left.userName == right.userName;
}

CurrentUser *CurrentUser::getInstance()
{
    static CurrentUser *obj = new CurrentUser();
    return obj;
}

CurrentUser::CurrentUser()
{

}
