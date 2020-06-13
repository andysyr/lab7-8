#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::Add_widget_to_layout(QWidget *object)
{
    ui->verticalLayout->addWidget(object);
}

void MainWindow::Connect_database()
{
    database.reset(new Database("factory", "127.0.0.1", "root", "root", this));
}

bool MainWindow::Insert_data(QString table_name, std::vector<QString> data)
{
    return database->Insert_data(table_name, data);
}

bool MainWindow::Show_tables()
{
    return database->Show_tables();
}

bool MainWindow::Show_table_data(QString table_name)
{
    bool res = database->Show_table_data(table_name);
    this->show();
    return res;
}

bool MainWindow::Show_data(QString table_name, int id)
{
    bool res = database->Show_data(table_name, id);
    this->show();
    return res;
}

bool MainWindow::Attendance_control(int id)
{
    bool res = database->Attendance_control(id);
    this->show();
    return res;
}

bool MainWindow::Remove_raw(QString table_name, QString column, QString data)
{
    return database->Remove_raw(table_name, column, data);
}

bool MainWindow::Close_database()
{
    return database->Close_database();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

