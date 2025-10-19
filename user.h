#ifndef USER_H
#define USER_H

#include <vector>
#include <QDebug>
#include "deposit.h"
// #include "interest_period.h"

class User
{
private:

    QString m_username;

public:

    std::vector<Deposit> m_account;

    User(){}
    User(QString new_user);

    // void calInterest(std::vector<InterestPeriod>& periods);
    void newDeposit(int amount);
    bool withdraw(int amount);
    // void check();
};
#endif // USER_H
