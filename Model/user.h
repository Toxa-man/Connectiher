#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();
protected:
    QString userName;
    quint8 ip4[4];
    bool isMuted;

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
