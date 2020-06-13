#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databaselogic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void Add_widget_to_layout(QWidget *object);

    void Connect_database();

    void Show_tables();

    void Show_table_data(QString table_name);

    void Show_data(QString table_name, int id = 0);

    void Attendance_control(int id = 0);

    void Input_data(QString table_name, std::vector<QString> data);

    void Insert_data (QString table_name, std::vector<QString> data);

    void Remove_raw(QString table_name, QString column, QString data);

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Database> database;
};
#endif // MAINWINDOW_H
