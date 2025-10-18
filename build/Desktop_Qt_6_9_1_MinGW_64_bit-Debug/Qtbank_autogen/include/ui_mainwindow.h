/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *home_page;
    QPushButton *admin_button;
    QPushButton *settings_button;
    QPushButton *user_button;
    QLabel *title;
    QWidget *user_page;
    QLineEdit *search_box;
    QPushButton *search_button;
    QLabel *user_title;
    QPushButton *return_button;
    QWidget *account_info;
    QLabel *account_name;
    QPushButton *depo_button;
    QPushButton *draw_button;
    QPushButton *x_button;
    QLineEdit *amount_box;
    QPushButton *enter_amount;
    QListWidget *depo_list;
    QLabel *no_deposit;
    QLabel *total_amount;
    QListWidget *account_list;
    QWidget *new_account_screen;
    QLabel *new_account_confirm;
    QPushButton *add_account;
    QPushButton *not_add_account;
    QPushButton *new_account_button;
    QLabel *account_not_found;
    QWidget *admin_page;
    QLabel *admin_title;
    QLabel *Interest_rate;
    QPushButton *new_button;
    QPushButton *reset_button;
    QListWidget *rate_list;
    QLineEdit *start_time_box;
    QLineEdit *end_time_box;
    QLineEdit *rate_box;
    QPushButton *enter_new_rate;
    QPushButton *return_button_2;
    QWidget *page;
    QLabel *clock;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(34, 38, 72)\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 801, 551));
        home_page = new QWidget();
        home_page->setObjectName("home_page");
        admin_button = new QPushButton(home_page);
        admin_button->setObjectName("admin_button");
        admin_button->setGeometry(QRect(460, 440, 271, 61));
        admin_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(61, 43, 118);\n"
"	font: 36pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color:rgb(77, 55, 150);\n"
"}"));
        settings_button = new QPushButton(home_page);
        settings_button->setObjectName("settings_button");
        settings_button->setGeometry(QRect(20, 30, 151, 41));
        settings_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(115, 105, 163);\n"
"	font: 24pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color:rgb(148, 135, 211);\n"
"}"));
        user_button = new QPushButton(home_page);
        user_button->setObjectName("user_button");
        user_button->setGeometry(QRect(70, 440, 271, 61));
        user_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(35, 37, 162);\n"
"	font: 36pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color: rgb(46, 48, 211);\n"
"}"));
        title = new QLabel(home_page);
        title->setObjectName("title");
        title->setGeometry(QRect(40, 130, 691, 131));
        title->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 600 48pt \"Cascadia Code\";\n"
"}"));
        stackedWidget->addWidget(home_page);
        user_page = new QWidget();
        user_page->setObjectName("user_page");
        search_box = new QLineEdit(user_page);
        search_box->setObjectName("search_box");
        search_box->setGeometry(QRect(30, 130, 201, 41));
        search_box->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	frame: rgb(255, 255, 255);\n"
"	color:rgb(255, 255, 255);\n"
"	font: 20pt \"Sans Serif Collection\";\n"
"}"));
        search_button = new QPushButton(user_page);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(240, 130, 121, 41));
        search_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(87, 98, 161);\n"
"	font: 24pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color:rgb(129, 146, 239);\n"
"}"));
        user_title = new QLabel(user_page);
        user_title->setObjectName("user_title");
        user_title->setGeometry(QRect(60, 30, 211, 81));
        user_title->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 600 36pt \"Cascadia Code\";\n"
"}"));
        return_button = new QPushButton(user_page);
        return_button->setObjectName("return_button");
        return_button->setGeometry(QRect(20, 50, 31, 41));
        return_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(34, 38, 72);\n"
"	font: 900 24pt \"Noto Sans TC\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	color:rgb(181, 181, 181);\n"
"}"));
        account_info = new QWidget(user_page);
        account_info->setObjectName("account_info");
        account_info->setGeometry(QRect(460, 130, 301, 391));
        account_info->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color:rgb(90, 93, 138);\n"
"}"));
        account_name = new QLabel(account_info);
        account_name->setObjectName("account_name");
        account_name->setGeometry(QRect(10, 10, 281, 41));
        account_name->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	font: 20pt \"Sans Serif Collection\";\n"
"}"));
        depo_button = new QPushButton(account_info);
        depo_button->setObjectName("depo_button");
        depo_button->setGeometry(QRect(20, 70, 111, 31));
        depo_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(129, 120, 163);\n"
"	font: 16pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color:rgb(168, 157, 213)\n"
"}"));
        draw_button = new QPushButton(account_info);
        draw_button->setObjectName("draw_button");
        draw_button->setGeometry(QRect(170, 70, 111, 31));
        draw_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(34, 39, 148);\n"
"	font: 16pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color:rgb(45, 52, 194);\n"
"}"));
        x_button = new QPushButton(account_info);
        x_button->setObjectName("x_button");
        x_button->setGeometry(QRect(260, 10, 31, 31));
        x_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 700 16pt \"Noto Sans TC\";\n"
"	background-color: rgb(241, 110, 106);\n"
"	border-radius:10px;\n"
"	text-align: center;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color: rgb(241, 77, 65);\n"
"}"));
        amount_box = new QLineEdit(account_info);
        amount_box->setObjectName("amount_box");
        amount_box->setGeometry(QRect(20, 120, 201, 21));
        amount_box->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"	border-color: rgb(109, 109, 109);\n"
"	color:rgb(255, 255, 255);\n"
"	font: 14pt \"Sans Serif Collection\";\n"
"}"));
        enter_amount = new QPushButton(account_info);
        enter_amount->setObjectName("enter_amount");
        enter_amount->setGeometry(QRect(240, 120, 41, 21));
        enter_amount->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 700 16pt \"Noto Sans TC\";\n"
"	background-color: rgb(76, 255, 157);\n"
"	border-radius:10px;\n"
"	text-align: center;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color: rgb(171, 255, 185);\n"
"}"));
        depo_list = new QListWidget(account_info);
        depo_list->setObjectName("depo_list");
        depo_list->setGeometry(QRect(20, 160, 256, 161));
        depo_list->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 500 14pt \"Noto Sans TC\";\n"
"	margin: 5px, 5px, 5px, 0px;\n"
"}"));
        no_deposit = new QLabel(account_info);
        no_deposit->setObjectName("no_deposit");
        no_deposit->setGeometry(QRect(60, 220, 201, 41));
        no_deposit->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	font: 18pt \"Sans Serif Collection\";\n"
"	text-align: center;\n"
"}"));
        total_amount = new QLabel(account_info);
        total_amount->setObjectName("total_amount");
        total_amount->setGeometry(QRect(30, 330, 201, 41));
        total_amount->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	font: 18pt \"Sans Serif Collection\";\n"
"}"));
        account_list = new QListWidget(user_page);
        account_list->setObjectName("account_list");
        account_list->setGeometry(QRect(30, 200, 381, 321));
        account_list->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 500 18pt \"Noto Sans TC\";\n"
"	margin: 5px, 5px, 5px, 0px;\n"
"}"));
        new_account_screen = new QWidget(user_page);
        new_account_screen->setObjectName("new_account_screen");
        new_account_screen->setGeometry(QRect(90, 290, 261, 131));
        new_account_screen->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color:rgb(90, 93, 138);\n"
"}"));
        new_account_confirm = new QLabel(new_account_screen);
        new_account_confirm->setObjectName("new_account_confirm");
        new_account_confirm->setGeometry(QRect(20, 10, 231, 41));
        new_account_confirm->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	font: 20pt \"Sans Serif Collection\";\n"
"	text-align: center;\n"
"}"));
        add_account = new QPushButton(new_account_screen);
        add_account->setObjectName("add_account");
        add_account->setGeometry(QRect(30, 80, 80, 24));
        add_account->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 700 16pt \"Noto Sans TC\";\n"
"	background-color: rgb(76, 255, 157);\n"
"	border-radius:10px;\n"
"	text-align: center;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color: rgb(171, 255, 185);\n"
"}"));
        not_add_account = new QPushButton(new_account_screen);
        not_add_account->setObjectName("not_add_account");
        not_add_account->setGeometry(QRect(150, 80, 80, 24));
        not_add_account->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 700 16pt \"Noto Sans TC\";\n"
"	background-color: rgb(241, 110, 106);\n"
"	border-radius:10px;\n"
"	text-align: center;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color: rgb(241, 77, 65);\n"
"}"));
        new_account_button = new QPushButton(user_page);
        new_account_button->setObjectName("new_account_button");
        new_account_button->setGeometry(QRect(370, 130, 41, 41));
        new_account_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(163, 155, 255);\n"
"	font: 24pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color:rgb(138, 123, 255);\n"
"}"));
        account_not_found = new QLabel(user_page);
        account_not_found->setObjectName("account_not_found");
        account_not_found->setGeometry(QRect(80, 230, 291, 41));
        account_not_found->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	font: 20pt \"Sans Serif Collection\";\n"
"	text-align: center;\n"
"}"));
        stackedWidget->addWidget(user_page);
        admin_page = new QWidget();
        admin_page->setObjectName("admin_page");
        admin_title = new QLabel(admin_page);
        admin_title->setObjectName("admin_title");
        admin_title->setGeometry(QRect(60, 30, 141, 81));
        admin_title->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 600 36pt \"Cascadia Code\";\n"
"}"));
        Interest_rate = new QLabel(admin_page);
        Interest_rate->setObjectName("Interest_rate");
        Interest_rate->setGeometry(QRect(60, 150, 191, 81));
        Interest_rate->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 24pt \"Sans Serif Collection\";\n"
"}\n"
""));
        new_button = new QPushButton(admin_page);
        new_button->setObjectName("new_button");
        new_button->setGeometry(QRect(270, 170, 91, 41));
        new_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(231, 158, 255);\n"
"	font: 24pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color:rgb(227, 124, 255)\n"
"}"));
        reset_button = new QPushButton(admin_page);
        reset_button->setObjectName("reset_button");
        reset_button->setGeometry(QRect(380, 170, 91, 41));
        reset_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(255, 121, 121);\n"
"	font: 24pt \"Sans Serif Collection\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color:rgb(255, 79, 79)\n"
"}"));
        rate_list = new QListWidget(admin_page);
        rate_list->setObjectName("rate_list");
        rate_list->setGeometry(QRect(60, 300, 411, 201));
        rate_list->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 500 15pt \"Noto Sans TC\";\n"
"	margin: 5px, 5px, 5px, 0px;\n"
"}"));
        start_time_box = new QLineEdit(admin_page);
        start_time_box->setObjectName("start_time_box");
        start_time_box->setGeometry(QRect(60, 240, 131, 21));
        start_time_box->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"	border-color: rgb(109, 109, 109);\n"
"	color:rgb(255, 255, 255);\n"
"	font: 14pt \"Sans Serif Collection\";\n"
"}"));
        end_time_box = new QLineEdit(admin_page);
        end_time_box->setObjectName("end_time_box");
        end_time_box->setGeometry(QRect(210, 240, 121, 21));
        end_time_box->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"	border-color: rgb(109, 109, 109);\n"
"	color:rgb(255, 255, 255);\n"
"	font: 14pt \"Sans Serif Collection\";\n"
"}"));
        rate_box = new QLineEdit(admin_page);
        rate_box->setObjectName("rate_box");
        rate_box->setGeometry(QRect(350, 240, 81, 21));
        rate_box->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"	border-color: rgb(109, 109, 109);\n"
"	color:rgb(255, 255, 255);\n"
"	font: 14pt \"Sans Serif Collection\";\n"
"}"));
        enter_new_rate = new QPushButton(admin_page);
        enter_new_rate->setObjectName("enter_new_rate");
        enter_new_rate->setGeometry(QRect(440, 240, 31, 21));
        enter_new_rate->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 700 16pt \"Noto Sans TC\";\n"
"	background-color: rgb(76, 255, 157);\n"
"	border-radius:10px;\n"
"	text-align: center;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	background-color: rgb(171, 255, 185);\n"
"}"));
        return_button_2 = new QPushButton(admin_page);
        return_button_2->setObjectName("return_button_2");
        return_button_2->setGeometry(QRect(20, 50, 31, 41));
        return_button_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color: rgb(34, 38, 72);\n"
"	font: 900 24pt \"Noto Sans TC\";\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"	color:rgb(181, 181, 181);\n"
"}"));
        stackedWidget->addWidget(admin_page);
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        clock = new QLabel(centralwidget);
        clock->setObjectName("clock");
        clock->setGeometry(QRect(660, 20, 121, 41));
        clock->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgb(151, 184, 255);\n"
"	font: 700 18pt \"Calibri\";\n"
"	border-radius: 5px;\n"
"	qproperty-alignment: AlignCenter;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        admin_button->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        settings_button->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        user_button->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "IZCC Casino Bank", nullptr));
        search_box->setText(QString());
        search_button->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        user_title->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        return_button->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        account_name->setText(QCoreApplication::translate("MainWindow", "Account Name", nullptr));
        depo_button->setText(QCoreApplication::translate("MainWindow", "Deposit", nullptr));
        draw_button->setText(QCoreApplication::translate("MainWindow", "Withdraw", nullptr));
        x_button->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        amount_box->setText(QString());
        amount_box->setPlaceholderText(QCoreApplication::translate("MainWindow", "Amount: ", nullptr));
        enter_amount->setText(QCoreApplication::translate("MainWindow", "\342\234\223", nullptr));
        no_deposit->setText(QCoreApplication::translate("MainWindow", "No Deposits Yet", nullptr));
        total_amount->setText(QCoreApplication::translate("MainWindow", "Total:", nullptr));
        new_account_confirm->setText(QCoreApplication::translate("MainWindow", "Add New Account ?", nullptr));
        add_account->setText(QCoreApplication::translate("MainWindow", "Yes", nullptr));
        not_add_account->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        new_account_button->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        account_not_found->setText(QCoreApplication::translate("MainWindow", "ACCOUNT NOT FOUND", nullptr));
        admin_title->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        Interest_rate->setText(QCoreApplication::translate("MainWindow", "Interest Rate", nullptr));
        new_button->setText(QCoreApplication::translate("MainWindow", "new", nullptr));
        reset_button->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        start_time_box->setText(QString());
        start_time_box->setPlaceholderText(QCoreApplication::translate("MainWindow", "Start(HH: MM)", nullptr));
        end_time_box->setText(QString());
        end_time_box->setPlaceholderText(QCoreApplication::translate("MainWindow", "End(HH:MM)", nullptr));
        rate_box->setText(QString());
        rate_box->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rate(%)", nullptr));
        enter_new_rate->setText(QCoreApplication::translate("MainWindow", "\342\234\223", nullptr));
        return_button_2->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        clock->setText(QCoreApplication::translate("MainWindow", "Timer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
