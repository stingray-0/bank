#include <unordered_set>
#include <iostream>
#include <chrono>
#include <thread>

#include "file_manager.h"
#include "interaction.h"
#include "signal_handler.h"

void interaction_loop(std::unordered_map <std::string, user> &data)
{
    std::unordered_set<std::string> valid_actions = {"D", "W", "C", "exit"};
    while(true)
    {
        if (is_exiting)
        {   
            std::cerr << "exiting...\n";
            file_manager::save(data);
            while (!has_saved) std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::_Exit(0);
        }

        //cleaning up the variables
        std::string acc = "";
        std::string action = "";

        //fetch action
        std::cout << "Action (D/W/C/exit): ";
        safe_input<std::string>(action, data);

        if (valid_actions.count(action) == 0)
        {
            std::cerr << "Your invalid action was eaten by a blue stingray!\n";
            continue;
        }
        if (action == "exit")
        {
            file_manager::save(data);
            file_manager::safe_save();
            std::cout << "exiting...\n";
            break;
        }

        //fetch account
        std::cout << "Account name: ";
        safe_input<std::string>(acc, data);

        if (data.try_emplace(acc, acc).second)
        {
            std::cout << "New account " << acc << " created!\n"; 
            file_manager::save(data);
        }

        //performing action
        if (action == "D")
        {
            handle_deposit(data, acc);
        }
        else if (action == "W")
        {
            handle_withdraw(data, acc);
        }
        else if (action == "C")
        {
            data[acc].check();
            file_manager::save(data);
        }

    }
}

void handle_deposit(std::unordered_map<std::string, user> &data, const std::string &acc)
{
    int money = 0;
    std::cout << "Deposit amount: ";
    safe_input<int>(money, data);
    if (money <= 0) 
    {
        std::cout << "Bro, you thought you're smart enough to trick me?\n";
        return;
    }

    data[acc].new_deposit(money);
    file_manager::save(data);
}

void handle_withdraw(std::unordered_map<std::string, user> &data, const std::string &acc)
{
    int money = 0;
    std::cout << "Withdraw amount: ";
    safe_input<int>(money, data);
    if (money <= 0) 
    {
        std::cout << "Bro, you thought you're smart enough to trick me?\n";
        return;
    }

    data[acc].withdraw(money);
    file_manager::save(data);
}

void handle_check(std::unordered_map<std::string, user> &data, const std::string &acc)
{
    data[acc].check();
    file_manager::save(data);
}