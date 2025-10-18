#ifndef USER_H
#define USER_H

#include <vector>
// #include <string>
#include "deposit.h"
#include <QDebug>


class User
{
private:

    QString m_username;
    void cal_interest();

public:

    std::vector<deposit> account;

    User(){}
    User(QString new_user);

    void new_deposit(int amount);
    bool withdraw(int amount);
    void check();
};
#endif // USER_H
