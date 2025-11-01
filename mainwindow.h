#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QListWidget>
#include "user.h"
#include <QMessageBox>
#include "bank.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void update_clock();

    void on_return_button_clicked();

    void on_user_button_clicked();

    void on_search_button_clicked();

    void on_account_list_itemClicked(QListWidgetItem *item);

    void on_x_button_clicked();

    void on_add_account_clicked();

    void on_not_add_account_clicked();

    void on_new_account_button_clicked();

    void on_depo_button_clicked();

    void on_draw_button_clicked();

    void on_enter_amount_clicked();



    void on_return_button_2_clicked();

    void on_admin_button_clicked();

    void on_new_button_clicked();

    void on_enter_new_rate_clicked();

    void on_reset_button_clicked();

    void on_update_period_clicked();


    void on_update_assests_clicked();

    void on_full_reset_button_clicked();

    void on_do_not_reset_button_clicked();

    void on_proceed_reset_button_clicked();

private:
    Ui::MainWindow *ui;

    std::unordered_map<QString, User> data;
    Bank bank;
    QString user_action = "";
    QString cur_account = "";
    void update_depo_list();
    void show_account_info();
    bool check_time(QLineEdit* box);
    void update_rate_list();
    void update_tick_rate();
    void update_total_assets();
    void update_risk();
};
#endif // MAINWINDOW_H
