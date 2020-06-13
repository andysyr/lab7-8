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

void MainWindow::Input_data(QString table_name, std::vector<QString> data)
{
    database->Input_data(table_name, data);
}

void MainWindow::Insert_data (QString table_name, std::vector<QString> data)
{
    database->Insert_data(table_name, data);
}

void MainWindow::Show_tables()
{
    database->Show_tables();
}

void MainWindow::Show_table_data(QString table_name)
{
    database->Show_table_data(table_name);
    this->show();
}

void MainWindow::Show_data(QString table_name, int id)
{
    database->Show_data(table_name, id);
    this->show();
}

void MainWindow::Attendance_control(int id)
{
    database->Attendance_control(id);
    this->show();
}

void MainWindow::Remove_raw(QString table_name, QString column, QString data)
{
    database->Remove_raw(table_name, column, data);
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

