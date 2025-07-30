#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <fstream>
#include <filesystem>

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
    deposit(int m, time_t time, int hour) : amount(m), deposit_time(time), deposit_hour(hour){}
};

class user
{
private:
    std::string m_username;
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
    std::vector<deposit> accounts;

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
        if (total == amount) 
        {
            accounts.erase(accounts.begin(), accounts.end());
        }

        for (auto it = --accounts.end(); it != accounts.end(); ) 
        {

            if (it->amount > amount) 
            {
                it->amount -= amount;
                break;
            }
            else 
            {   
                amount -= it->amount;
                it = accounts.erase(it);

                if (it != accounts.begin()) --it;
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

void save(std::unordered_map<std::string, user> d)
{
    std::ofstream out_data("temp_bank_data.txt");

    for (const auto& u : d)
    {
        out_data << u.first << ' ' << u.second.accounts.size() << '\n';
        for (deposit depo : u.second.accounts)
        {
            out_data << depo.amount << ' '<< depo.deposit_time << ' ' << depo.deposit_hour <<'\n';
        }
        out_data << '\n';
    }

    out_data.close();
}

void safe_save()
{
    std::filesystem::path temp_data = "temp_bank_data.txt";
    std::filesystem::path new_data = "bank_data.txt";

    if (!std::filesystem::exists(temp_data))
    {
        std::cout << "No temp data\n";
        return;
    }
    
    std::error_code ec;

    std::filesystem::remove("bank_data.txt", ec);
    std::filesystem::rename(temp_data, new_data, ec);
    if (ec)
    {
        std::cout << "Safe saving error: " << ec.message() << '\n';
    }
    else
    {
        std::cout << "Safe saving completed successfully!\n";
    }
}

void load(std::unordered_map<std::string, user>& d)
{
    std::ifstream in_data("bank_data.txt");
    if(!in_data)
    {
        std::cout << "Man! Where's the data!\n";
        return;
    }

    std::string name;
    int depo_count, amount, hour;
    time_t time;
    while (in_data >> name >> depo_count)
    {
        user u(name);
        // u.accounts.reserve(depo_count);
        for (int i = 0; i < depo_count; i++)
        {
            in_data >> amount >> time >> hour;
            deposit depo(amount, time, hour);
            u.accounts.push_back(depo);
        }
        d[name] = u;
    }

    if (in_data.eof())
    {
        std::cout << "Reached end of data\n";
    }
    else
    {
        std::cerr << "Error: Failed to read complete data\n";
    }

    in_data.close();
}

int main()
{
    std::unordered_map<std::string, user> data;

    load(data);

    while (true)
    {
        std::string ac = "";
        std::string action = "";
        int money = 0;

        std::cout << "Action: ";
        std::cin >> action;
        std::cout << "Account name: ";
        std::cin >> ac;


        if (data.find(ac) == data.end())
        {
            data.try_emplace(ac, ac);
            std::cout << "New account " << ac << " created!\n"; 
            save(data);
        }

        
        if (action == "D")
        {
            std::cout << "Deposit amount: ";
            std::cin >> money;
            if (money > 0)
            {
                data[ac].new_deposit(money);
                save(data);
            }
            else 
            {
                std::cout   <<"C'mon man what you trying to do?\n"
                            <<"Don't waste my time\n";
            }
        }
        else if (action == "W")
        {
            std::cout << "Withdraw amount: ";
            std::cin >> money;
            if (money > 0)
            {
                data[ac].withdraw(money);
                save(data);
            }
            else 
            {
                std::cout   <<"C'mon man what you trying to do?\n"
                            <<"Don't waste my time\n";
            }
        }
        else if (action == "C")
        {
            data[ac].check();
        }
        else
        {
            std::cout << "You're invalid action was eaten by a stingray\n";
        }


        safe_save();
    }

    return 0;
}
