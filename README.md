# IZCC Summer/Winter Camp Casino Bank

## Intro
**This project is fully written in C++!**<br>
The project is dedicated to act as the bank during the casino activity! <br>
It can track different accounts and handle deposits, withdrawings, and interest counting automatically! More importantly, it has safe savings, which means that it stores your data(if you use it the right way ofcourse)! <br>
With this we no longer need to use Excel for the bank and it's also more fitting to computer science clubs. <br>
This project can still be improved, feel free to try to optimize the code or add new features and such.

## Using Instruction

### 1. File Structure
Pretty common file structure imo.<br>
The **"datas"** folder stores txt files which bank datas are stored at.<br>
**Bin** is not strictly necessary since only one exe file is produced, but I decided to put it in case future adjustments are made.<br>
**".vscode"** folder is obviously... for vscode, if you can't run / build the project on vscode, my task.json might not fit your environment. <br>

### 2. Building and Running
Do **not** use vscode run, build manaully then run the file using "./bin/bank_app" in the terminal.<br>
If you do use vscode run, safe saving that triggers when ctrl+C is pressed will **not** work!<br>

## Code Logic
### Summary
Yes the logic may be confusing(?). So lemme explain it. <br>

Data Structure -<br>
user class is basically an account.<br>
deposit class is one single deposit, an account can have many deposits<br>

Interaction Loop -<br>
checks for action first then checks the account you want to put action, finally runs different functions based on action.<br>

Saving -<br>
"backup_bank_data" stores the previous version of data<br>
"bank_data" stores the current data version<br>
"temp_bank_data" stores temporary data<br>
save function stores to "temp_bank_data" and safe_save copies the data to "bank_data" and creates the backup

### class deposit
stores the hour and time of deposit creation for interest calculations<br>
m_amount stores amount ,yeah....

### class user
tracks each deposits of the user and modifies the account according to functions<br>
Note: interests are only calculated when running check or withdraw

### file manager
file_manager is a static class that handles files<br>
Maybe the code looks fancy? But its just to make sure data files are stored<br>
Perhaps its a bit of an overkill, but better safe than sorry I guess?

### signal handler
**ONLY WORKS ON WINDOWS**<br>
signal_handler is to deal with safe saving when ctrl + C interuption<br>
can_save is a thread that detects if safe_saving condition is met<br>
safe_input function is for triggering bruteforce exiting and save. The point of it is to make sure to save, and bruteforce exiting makes the terminal cleaner(no weird cin cout messages)

## Conclusion 

Hope you like the bank program!<br>
I really hope that IZCC can pass this down in the future.<br>
If you find any bugs or have troubles using it, feel free to ask!<br>
Thanks a ton for treeman to help build this project!<br>
---
author: stingray-0
---
