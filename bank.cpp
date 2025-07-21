#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <chrono>

class deposit
{
public:
    long long amount;
    int deposit_hour;
    time_t deposit_time;
    deposit(int m) : amount(m)
    {
        deposit_time = time(nullptr);
        tm* local_tm = localtime(&deposit_time);
        deposit_hour = local_tm->tm_hour;    
    } 
};

class user
{
private:
    std::string m_username;
    std::vector<deposit> accounts;

    void cal_interest()
    {
        for (auto &depo : accounts) 
        {
            double interest_rate = 0;
            int periods = difftime(time(nullptr), depo.deposit_time) / 60 / 20;
            
            if (periods == 0) continue;
            if (depo.deposit_hour == 14) interest_rate = 1.2;
            else if (depo.deposit_hour == 15) interest_rate = 1.5;
            else interest_rate = 1.7;

            while (periods--) depo.amount *= interest_rate;
            depo.deposit_time = time(nullptr);
        }
        return;  
    }

public:
    user() {};
    user(std::string new_user) : m_username(new_user) {}
    void new_deposit(int amount) 
    {
        accounts.push_back(deposit (amount));
    }

    void withdraw(int amount) 
    {   
        cal_interest();

        int total = 0;
        for (auto ac : accounts) total += ac.amount;
        if (total < amount) {
            std::cout << "You brokie\n";
            return;
        }

        for (auto it = accounts.begin(); it != accounts.end(); ++it) 
        {

            if (it->amount >= amount) 
            {
                it->amount -= amount;
                break;
            }

            else 
            {   
                amount -= it->amount;
                it = accounts.erase(it);
            }
        }
    }

    void check() 
    {   
        cal_interest();
        int total = 0;
        for (auto ac : accounts) total += ac.amount;

        std::cout << total << '\n';
    }

};

int main()
{
    std::unordered_map<std::string, user> data;
    std::string ac;
    std::string action;
    int money;

    while (true)
    {
        std::cout << "Action: ";
        std::cin >> action;
        std::cout << "Account name: ";
        std::cin >> ac;

        if (data.find(ac) == data.end())
        {
            std::cout << "New account " << ac << " created!\n"; 
        }

        if (action == "D")
        {
            std::cout << "Deposit amount: ";
            std::cin >> money;
            (data.try_emplace(ac, ac).first->second).new_deposit(money);
        }
        else if (action == "W")
        {
            std::cout << "Withdraw amount: ";
            std::cin >> money;
            data[ac].withdraw(money);
        }
        else
        {
            data[ac].check();
        }
    }

    return 0;
}