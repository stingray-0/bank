#include "bank.h"
#include <QTime>

Bank::Bank()
{
    InterestPeriod default_period;
    default_period.start_mins = 0;
    default_period.end_mins = 1439;
    default_period.rate = 100;
    interest_periods.push_back(default_period);
}

bool Bank::add_user(QString acc_name)
{
    if (this->user_list.try_emplace(acc_name, acc_name).second) return true;
    return false;
}


bool Bank::add_interest_period(QString start_str, QString end_str, double rate)
{
    QTime start_time = QTime::fromString(start_str, "HH:mm");
    QTime end_time = QTime::fromString(end_str, "HH:mm");

    InterestPeriod new_period;
    new_period.start_mins = start_time.hour()*60 + start_time.minute();
    new_period.end_mins = end_time.hour()*60 + end_time.minute();
    new_period.rate = rate;

    if (new_period.start_mins >= new_period.end_mins)
    {
        return false;
    }

    for (auto& period : interest_periods)
    {
        if (new_period.end_mins > period.start_mins && new_period.start_mins < period.end_mins)
        {
            return false;
        }
    }

    interest_periods.push_back(new_period);

    return true;
}
