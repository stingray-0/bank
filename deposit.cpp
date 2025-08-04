#include "deposit.h"

deposit::deposit(int m) : m_amount(m)
{
    m_time = time(nullptr);
    tm* local_tm = localtime(&m_time);
    m_hour = local_tm->tm_hour;    
}

deposit::deposit(int m, time_t time, float hour) 
        : m_amount(m), m_time(time), m_hour(hour) {}