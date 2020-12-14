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

    bool Show_tables();
    bool Show_table_data(QString table_name, int id = 0);
    bool ShowSingleProductInfo(int id);
    bool ShowInnerInfo(int id);
    bool ShowWareHouseInfo(int id);

    bool Insert_data (QString table_name, std::vector<QString> data);
    bool Remove_raw(QString table_name, QString column, QString data);

    bool Close_database();

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private slots:
    void onShow_tablesPressed();
    void onShow_table_dataPressed();
    void onShowSingleProductInfoPressed();
    void onShowInnerInfoPressed();
    void onShowWarehouseInfoPressed();

private:
    Ui::MainWindow *ui;
public:
    std::unique_ptr<Database> database;
};
#endif // MAINWINDOW_H
