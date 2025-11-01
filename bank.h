#ifndef BANK_H
#define BANK_H

#include <QString>
#include <unordered_map>
#include <vector>
#include "interest_period.h"
#include "user.h"



class Bank
{
private:
    void calcLiabilities();
public:
    int period_mins;
    int assets;
    long long liabilities;

    Bank();
    std::unordered_map<QString, User> user_list;
    std::vector<InterestPeriod> interest_periods;

    void init();
    bool add_user(QString acc_name);
    bool add_interest_period(QString start_str, QString end_str, double rate_str);
    int calcEquity();
};

#endif // BANK_H
