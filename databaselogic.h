#ifndef DATABASELOGIC_H
#define DATABASELOGIC_H

#include <QCoreApplication>
#include<iostream>
#include <QtSql>
#include <QTableView>
#include <QApplication>


class MainWindow;

class Database
{
public:

    Database() = default;

    Database (QString DatabaseName_, QString hostname_, QString username_, QString password_, MainWindow *window_);

    void Show_tables();

    void Show_table_data(QString table_name);

    void Show_workers();

    void Show_data(QString table, int id);

    void Attendance_control(int id = 0);

    void Input_data(QString table_name, std::vector<QString> data);

    void Insert_data (QString table_name, std::vector<QString> data);

    void Remove_raw(QString table_name, QString column, QString data);

    void Close_database();

private:
    QString DatabaseName,
            hostname,
            username,
            password;

    QTableView view;
    QSqlQueryModel model_read;
    QSqlTableModel model_read_write;
    QSqlDatabase db;
    MainWindow *window;
};

#endif // DATABASELOGIC_H
