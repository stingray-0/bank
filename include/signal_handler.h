#pragma once
#include <atomic>
#include <windows.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

#include "user.h"
#include "file_manager.h"


extern std::atomic_bool is_exiting;
extern std::atomic_bool has_saved;


BOOL WINAPI signal_handler(DWORD signal);
void can_save();

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