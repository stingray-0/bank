#ifndef BANK_H
#define BANK_H

#include <QTime>
#include <QString>
#include "user.h"
#include <unordered_map>
#include <vector>


class Bank
{
private:

public:
    Bank();
    struct InterestPeriod
    {
        double rate;
        QTime start_time;
        QTime end_time;
    };
    std::unordered_map<QString, User> user_list;
    std::vector<InterestPeriod> intesrest_periods;
};

#endif // BANK_H
