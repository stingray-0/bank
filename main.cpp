#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <thread>
#include <atomic>
#include <windows.h>
#include <chrono>

#include "user.h"
#include "file_manager.h"


void interaction_loop(std::unordered_map <std::string, user> &data);
void handle_deposit(std::unordered_map<std::string, user> &data, const std::string &acc);
void handle_withdraw(std::unordered_map<std::string, user> &data, const std::string &acc);
void handle_check(std::unordered_map<std::string, user> &data, const std::string &acc);
BOOL WINAPI signal_handler(DWORD signal);
void can_save();

template<typename T>
void safe_input(T &variable, const std::unordered_map <std::string, user> &data);


std::atomic_bool is_exiting = false;
std::atomic_bool has_saved = false;


int main()
{
    SetConsoleCtrlHandler(signal_handler, TRUE);
    std::thread saver(can_save);
    saver.detach();

    std::unordered_map<std::string, user> bank_data;

    file_manager::load(bank_data);

    interaction_loop(bank_data);

    return 0;
}


BOOL WINAPI signal_handler(DWORD signal) 
{
    if (signal == CTRL_C_EVENT || signal == CTRL_CLOSE_EVENT || signal == CTRL_SHUTDOWN_EVENT) 
    {
        is_exiting = true;
        if (has_saved)
            std::_Exit(0);

        return TRUE;
    }

    return FALSE;
}

void can_save()
{
    while (!is_exiting)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    if (!has_saved || is_exiting)
    {
        file_manager::safe_save();
        has_saved = true;
    }
}

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

template<typename T>
void safe_input(T &variable, const std::unordered_map <std::string, user> &data)
{
    if (!(std::cin >> variable) || is_exiting) 
    {
        std::cerr << "\nexiting...\n";
        file_manager::save(data);

        while (!has_saved) std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::_Exit(0);
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