#pragma once
#include <unordered_map>
#include <filesystem>
#include <string>
#include "user.h"


class file_manager
{
    private:

    static const std::filesystem::path backup_data;
    static const std::filesystem::path temp_data;
    static const std::filesystem::path data;
    static void check_temp_data();
    static void check_missing_files();
    static void load_to_file(std::unordered_map<std::string, user>& d);
    
    public:

    static void save(const std::unordered_map<std::string, user>& d);
    static void safe_save();
    static void load(std::unordered_map<std::string, user>& d);
};
