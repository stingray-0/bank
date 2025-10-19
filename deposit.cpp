#include "deposit.h"
#include <time.h>

Deposit::Deposit(long long m) : m_amount(m)
{
    time_t now = time(nullptr);
    tm* local_tm = localtime(&now);
    m_mins = local_tm->tm_hour*60 + local_tm->tm_min;
    m_last_updated_mins = m_mins;
}

Deposit::Deposit(long long m, int mins): m_amount(m), m_mins(mins), m_last_updated_mins(mins){}

void Deposit::calInterest(std::vector<InterestPeriod>& periods)
{
    time_t now = time(nullptr);
    tm* local_tm = localtime(&now);
    int cur_mins = local_tm->tm_hour*60 + local_tm->tm_min;
    while (m_last_updated_mins+20 <= cur_mins)
    {
        for (const auto& p : periods)
        {
            if (m_last_updated_mins >= p.start_mins && m_last_updated_mins < p.end_mins)
            {
                m_amount *= p.rate/100;
                break;
            }
        }
        m_last_updated_mins += 20;
    }
}
