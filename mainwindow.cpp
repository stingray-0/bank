#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->home_page);
    //timer
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::update_clock);
    timer->start(1000);
    update_clock();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_return_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->home_page);
}

void MainWindow::update_clock()
{
    QString cur_time = QDateTime::currentDateTime().toString("HH:mm:ss");
    ui->clock->setText(cur_time);
}


void MainWindow::on_user_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->user_page);
    ui->account_info->hide();
    ui->new_account_screen->hide();
    ui->account_not_found->hide();
    on_search_button_clicked();
}

void MainWindow::on_admin_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->admin_page);
    ui->start_time_box->hide();
    ui->rate_box->hide();
    ui->end_time_box->hide();
    ui->enter_new_rate->hide();
}

void MainWindow::on_search_button_clicked()
{
    QString acc = ui->search_box->text();
    ui->account_not_found->hide();
    ui->account_list->clear();
    for (const auto& [name, user_data] : data)
    {
        if(name.contains(acc, Qt::CaseInsensitive))
        {
            ui->account_list->addItem(name);
        }
    }
    if (ui->account_list->item(0) == nullptr)
    {
        ui->account_not_found->show();
        return;
    }
}


void MainWindow::on_account_list_itemClicked(QListWidgetItem *item)
{
    cur_account = ui->account_list->currentItem()->text();
    ui->account_name->setText(item->text());
    show_account_info();
}


void MainWindow::on_x_button_clicked()
{
    ui->account_info->hide();
}


void MainWindow::on_add_account_clicked()
{
    QString acc = ui->search_box->text();
    if(!data.try_emplace(acc, acc).second)
    {
        return;
    }
    cur_account = acc;
    ui->account_name->setText("New acc! " + acc);
    show_account_info();
    ui->new_account_screen->hide();
}


void MainWindow::on_not_add_account_clicked()
{
    ui->new_account_screen->hide();
}


void MainWindow::on_new_account_button_clicked()
{
    QString acc = ui->search_box->text();
    if (data.find(acc) == data.end())
    {
        ui->new_account_screen->show();
    }
    else
    {
        on_search_button_clicked();
    }
}

void MainWindow::show_account_info()
{
    ui->account_info->show();
    ui->amount_box->hide();
    ui->enter_amount->hide();
    update_depo_list();
}


void MainWindow::on_depo_button_clicked()
{
    user_action = "Deposit";
    ui->amount_box->show();
    ui->amount_box->clear();
    ui->amount_box->setPlaceholderText("Deposit Amount: ");
    ui->enter_amount->show();
}


void MainWindow::on_draw_button_clicked()
{
    user_action = "Withdraw";
    ui->amount_box->show();
    ui->amount_box->clear();
    ui->amount_box->setPlaceholderText("Withdraw Amount: ");
    ui->enter_amount->show();
}


void MainWindow::on_enter_amount_clicked()
{
    bool* ok_amount = new bool;
    int amount = ui->amount_box->text().toInt(ok_amount);
    ui->amount_box->clear();
    if (!*ok_amount)
    {
        ui->amount_box->setPlaceholderText("Enter Numbers!");
        return;
    }
    if (amount <= 0)
    {
        ui->amount_box->setPlaceholderText("Invalid amount!");
        return;
    }
    if (user_action == "Withdraw")
    {
        if (data[cur_account].withdraw(amount))
        {
            ui->amount_box->setPlaceholderText("Withdraw Completed");
        }
        else
        {
            ui->amount_box->setPlaceholderText("You Brokie!");
        }
    }
    else if (user_action == "Deposit")
    {
        data[cur_account].new_deposit(amount);
        ui->amount_box->setPlaceholderText("Deposit Completed");
    }
    update_depo_list();
}

void MainWindow::update_depo_list()
{
    ui->no_deposit->hide();
    ui->depo_list->clear();
    long long total = 0;
    for (const auto& depo : data[cur_account].account)
    {
        total += depo.m_amount;
        QString depo_info = QString::number(depo.m_amount) + "$     Time: " + QString::number(depo.m_hour);
        ui->depo_list->addItem(depo_info);
    }
    if (ui->depo_list->item(0) == nullptr)
    {
        ui->no_deposit->show();
    }
    ui->total_amount->setText("Total: " + QString::number(total) + "$");

}

void MainWindow::on_return_button_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->home_page);
}



void MainWindow::on_new_button_clicked()
{
    ui->start_time_box->show();
    ui->rate_box->show();
    ui->end_time_box->show();
    ui->enter_new_rate->show();
}

bool MainWindow::check_time(QLineEdit* box)
{
    if(box->text().indexOf(":") != 2 || box->text().length() != 5)
    {
        return false;
    }

    bool* ok_hr = new bool;
    bool* ok_min = new bool;
    int hr = box->text().left(2).toInt(ok_hr);
    int min = box->text().right(2).toInt(ok_min);

    if(!*ok_hr || !*ok_min)
    {
        return false;
    }

    if(0>hr || hr>=24 && 0>min || min>=60)
    {
        return false;
    }

    return true;

}


void MainWindow::on_enter_new_rate_clicked()
{
    bool good = true;
    bool* ok_rate = new bool;
    int rate = ui->rate_box->text().toInt(ok_rate);

    if(!*ok_rate || 0>rate )
    {
        ui->rate_box->setText("");
        good = false;
    }
    if (!check_time(ui->start_time_box))
    {
        ui->start_time_box->setText("");
        good = false;
    }
    if (!check_time(ui->end_time_box))
    {
        ui->end_time_box->setText("");
        good = false;
    }
    if (good)
    {
        QString special = (rate>250)? "damn" : (rate<100)? "bro???" : "";
        ui->rate_list->addItem(ui->start_time_box->text() + " - " + ui->end_time_box->text()
                               + " : " + ui->rate_box->text() + "%  " + special);
    }
}

