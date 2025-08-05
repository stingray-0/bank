#pragma once
#include <vector>
#include <string>
#include "deposit.h"

class user
{
private:

    std::string m_username;
    void cal_interest();

public:

    std::vector<deposit> account;

    user(){}
    user(std::string new_user);

    void new_deposit(int amount);
    void withdraw(int amount);
    void check();
};