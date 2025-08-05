#include "signal_handler.h"


std::atomic_bool is_exiting = false;
std::atomic_bool has_saved = false;

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