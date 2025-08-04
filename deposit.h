#pragma once
#include <time.h>

class deposit
{
public:

    long long m_amount;
    float m_hour;
    time_t m_time;

    deposit(int m);
    deposit(int m, time_t time, float hour);
};