#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "interest_period.h"
#include <vector>
class Deposit
{
public:

    long long m_amount;
    int m_mins;
    int m_last_updated_mins;

    Deposit(long long m);
    Deposit(long long m, int mins);
    void calInterest(std::vector<InterestPeriod>& periods);
};

#endif // DEPOSIT_H
