#include "user.h"

User::User()
{

}

CurrentUser *CurrentUser::getInstance()
{
    static CurrentUser *obj = new CurrentUser();
    return obj;
}

CurrentUser::CurrentUser()
{

}
