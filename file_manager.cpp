#include "file_manager.h"
#include <iostream>
#include <fstream>

const std::filesystem::path file_manager::backup_data = "datas/backup_bank_data.txt";
const std::filesystem::path file_manager::temp_data = "datas/temp_bank_data.txt";
const std::filesystem::path file_manager::data = "datas/bank_data.txt";

void file_manager::check_temp_data()
{
    if (std::filesystem::exists(temp_data))
    {
        char copy;
        std::cout << "Do you want to copy temp_data to your current data? (Y/N)\n";
        std::cin >>  copy;
        if (std::cin.fail() && std::cin.eof()) return;

        if (copy == 'Y')
        {
            std::cout << "Copying\n";
            std::filesystem::remove(data);
            std::filesystem::copy(temp_data, data, std::filesystem::copy_options::overwrite_existing);        
        }
        
        std::filesystem::remove(temp_data);
    }
}

void file_manager::check_missing_files()
{
    if (!std::filesystem::exists(data) && !std::filesystem::exists(backup_data))
    {
        std::cout << "Fresh start? Lemme create file for you real quick\n";
        std::ofstream out_data(data);
        out_data.close();
        return;
    }
    if (!std::filesystem::exists(data))
    {
        std::cout << "Lost data, restoring from backup\n";
        std::filesystem::copy_file(backup_data, data, std::filesystem::copy_options::overwrite_existing);
        return;
    }
    if (!std::filesystem::exists(backup_data))
    {
        std::cout << "Seriously? You lost your backup data!\n";
        std::filesystem::copy_file(data, backup_data, std::filesystem::copy_options::overwrite_existing);
        return;
    }
}

void file_manager::load_to_file(std::unordered_map<std::string, user>& d)
{
    std::ifstream in_data(temp_data);
    if(!in_data)
    {
        std::cout << "Man! Where's the data!\n";
        return;
    }
    

    //loads data from file
    std::string name;
    int depo_count, amount, hour;
    time_t time;
    while (in_data >> name >> depo_count)
    {
        user u(name);
        for (int i = 0; i < depo_count; i++)
        {
            in_data >> amount >> time >> hour;
            deposit depo(amount, time, hour);
            u.account.push_back(depo);
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


void file_manager::load(std::unordered_map<std::string, user>& d)
{
    //different situations for different missing files
    check_temp_data();
    check_missing_files();
    
    //copy data to temp_data
    std::filesystem::copy(data, temp_data, std::filesystem::copy_options::overwrite_existing);
    
    //loads data from file
    load_to_file(d);  
}

void file_manager::save(const std::unordered_map<std::string, user>& d)
{
    std::ofstream out_data(temp_data);
    if (!out_data)
    {
        std::cerr << "Error: Failed to open temp data file for writing\n";
        return;
    }

    for (const auto& [name, user_data] : d)
    {
        out_data << name << " " << user_data.account.size() << "\n";
        for (const auto& depo : user_data.account)
        {
            out_data << depo.m_amount << " " << depo.m_time << " " << depo.m_hour << "\n";
        }
    }

    out_data.close();
}

void file_manager::safe_save()
{
    //check_existence
    if (!std::filesystem::exists(temp_data))
    {
        std::cout << "No temp data\n";
        return;
    }
    
    //safe saving process
    std::error_code ec;
    std::filesystem::remove(backup_data, ec);
    std::filesystem::rename(data, backup_data, ec);
    std::filesystem::rename(temp_data, data, ec);
    if (ec)
    {
        std::cout << "Ah shit....\n";
        std::cout << "Safe saving error: " << ec.message() << '\n';
        return;
    }

    std::cout << "Safe saving completed successfully!\n";
}