#include "user.h"
#include <iostream>

user::user(std::string new_user) : m_username(new_user) {}

void user::cal_interest()
{
    for (auto &depo : account) 
    {
        double interest_rate = 0;
        int periods = difftime(time(nullptr), depo.m_time) / 60 / 20;
        
        if (periods == 0) continue;
        if (depo.m_hour == 14) interest_rate = 1.2;
        else if (depo.m_hour == 15) interest_rate = 1.5;
        else interest_rate = 1.7;
        
        while (periods--) depo.m_amount *= interest_rate;
        depo.m_time = time(nullptr);
    }
    return;  
}

void user::new_deposit(int amount) 
{
    account.push_back(deposit(amount));
}

void user::withdraw(int amount) 
{   
    cal_interest();

    int total = 0;
    for (const auto& depo : account) total += depo.m_amount;
    if (total < amount) {
        std::cout << "You brokie\n";
        return;
    }
    if (total == amount) 
    {
        account.erase(account.begin(), account.end());
    }

    for (auto it = --account.end(); true ; ) 
    {

        if (it->m_amount > amount) 
        {
            it->m_amount -= amount;
            break;
        }
        
        amount -= it->m_amount;
        it = account.erase(it);

        if (it != account.begin()) --it;
    }
}

void user::check()
{
    cal_interest();
        
    int total = 0;
    for (const auto& depo : account) total += depo.m_amount;

    std::cout << total << '\n';
}
