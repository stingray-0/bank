#include <thread>
#include <unordered_map>

#include "user.h"
#include "file_manager.h"
#include "interaction.h"
#include "signal_handler.h"


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