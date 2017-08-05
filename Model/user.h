#ifndef USER_H
#define USER_H
#include <QString>
#include <QBuffer>

class User
{
public:
    User();
    User(QString name);
    QByteArray getAudioData() const;
    void setAudioData(const QByteArray &value);

    QString getUserName() const;
    void setUserName(const QString &value);
    friend bool operator ==(const User& left, const User& right);

protected:
    QString userName;
    quint8 ip4[4];
    bool isMuted;
    QByteArray audioData;

};
#define CURRENT_USER CurrentUser::getInstance()
class CurrentUser : public User
{
public:
    static CurrentUser* getInstance();
private:

    CurrentUser();
};

#endif // USER_H
