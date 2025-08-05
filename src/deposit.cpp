#include "deposit.h"

deposit::deposit(long long m) : m_amount(m)
{
    m_time = time(nullptr);
    tm* local_tm = localtime(&m_time);
    m_hour = local_tm->tm_hour + local_tm->tm_min / 60.0f;    
}

deposit::deposit(long long m, time_t time, float hour) 
        : m_amount(m), m_time(time), m_hour(hour) {}