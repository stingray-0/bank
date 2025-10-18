#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <time.h>

class deposit
{
public:

    long long m_amount;
    float m_hour;
    time_t m_time;

    deposit(long long m);
    deposit(long long m, time_t time, float hour);
};

#endif // DEPOSIT_H
