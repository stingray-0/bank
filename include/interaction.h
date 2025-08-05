#pragma once
#include <unordered_map>
#include <string>

#include "user.h"


void interaction_loop(std::unordered_map <std::string, user> &data);
void handle_deposit(std::unordered_map<std::string, user> &data, const std::string &acc);
void handle_withdraw(std::unordered_map<std::string, user> &data, const std::string &acc);
void handle_check(std::unordered_map<std::string, user> &data, const std::string &acc);