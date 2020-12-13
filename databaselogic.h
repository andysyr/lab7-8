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

    bool Show_tables();

    bool Show_table_data(QString table_name, int id = 0);

    bool Show_workers();

    bool Show_data(QString table, int id);

    bool Attendance_control(int id = 0);

    bool Insert_data (QString table_name, std::vector<QString> data);

    bool Remove_raw(QString table_name, QString column, QString data);

    bool Close_database();

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
