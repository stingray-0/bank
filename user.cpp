#include "user.h"
#include <iostream>

User::User(QString new_user) : m_username(new_user) {}

// void User::calInterest(std::vector<InterestPeriod>& periods)
// {
//     // for (auto &depo : account)
//     // {
//     //     double interest_rate = 0;
//     //     int periods = difftime(time(nullptr), depo.m_time) / 60 / 20;

//     //     if (periods == 0) continue;
//     //     if (depo.m_hour <= 13.5) interest_rate = 1.2;
//     //     else if (depo.m_hour <= 14) interest_rate = 1.5;
//     //     else interest_rate = 1.7;

//     //     while (periods--) depo.m_amount *= interest_rate;
//     //     depo.m_hour = localtime(&depo.m_time)->tm_hour + localtime(&depo.m_time)->tm_min / 60.0;
//     //     depo.m_time = time(nullptr);
//     // }
//     // return;
//     time_t now =time(nullptr);
//     tm *lt_now = localtime(&now);
//     int cur_mins = lt_now->tm_hour*60 + lt_now->tm_min;

//     for (auto &depo : m_account)
//     {
//         int last_mins = depo.m_last_updated_mins;
//         while (last_mins+20 < cur_mins)
//         {
//             for (const auto& p : periods)
//             {
//                 if (last_mins >= p.start_mins && last_mins < p.end_mins)
//                 {
//                     depo.m_amount *= p.rate/100;
//                     break;
//                 }
//             }
//             last_mins += 20;
//         }
//         depo.m_last_updated_mins = last_mins;
//     }
// }

void User::newDeposit(int amount)
{
    m_account.push_back(Deposit(amount));
}


bool User::withdraw(int amount)
{
    // calInterest();

    int total = 0;
    for (const auto& depo : m_account) total += depo.m_amount;
    if (total < amount) {
        std::cout << "You brokie\n";
        return false;
    }
    if (total == amount)
    {
        m_account.erase(m_account.begin(), m_account.end());
    }

    for (auto it = --m_account.end(); true ; )
    {

        if (it->m_amount > amount)
        {
            it->m_amount -= amount;
            break;
        }

        amount -= it->m_amount;
        it = m_account.erase(it);

        if (it != m_account.begin()) --it;
    }
    return true;
}

// void User::check()
// {
//     calInterest();

//     int total = 0;
//     for (const auto& depo : account) total += depo.m_amount;

//     std::cout << total << '\n';
// }
