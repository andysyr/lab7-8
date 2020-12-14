#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::Add_widget_to_layout(QWidget *object)
{
    ui->verticalLayout->addWidget(object);
    connect(ui->showTablesButton, &QPushButton::pressed, this, &MainWindow::onShow_tablesPressed);
    connect(ui->showDataPushButton, &QPushButton::pressed, this, &MainWindow::onShow_table_dataPressed);
    connect(ui->showSingleProductInfopushButton, &QPushButton::pressed, this, &MainWindow::onShowSingleProductInfoPressed);
    connect(ui->showInnerInfoPushButton, &QPushButton::pressed, this, &MainWindow::onShowInnerInfoPressed);
    connect(ui->showWareHouseInfopushButton, &QPushButton::pressed, this, &MainWindow::onShowWarehouseInfoPressed);
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
    QStringList tables = database->Show_tables();
    QString string = tables.join(" | ");
    ui->label_8->setText(string);
    return true;
}

bool MainWindow::Show_table_data(QString table_name, int id)
{
    bool res = database->Show_table_data(table_name, id);
//    this->show();
    return res;
}

bool MainWindow::ShowSingleProductInfo(int id)
{
    bool res = database->ShowSingleProductInfo(id);
    return res;
}

bool MainWindow::ShowInnerInfo(int id)
{
    bool res = database->ShowInnerInfo(id);
    return res;
}

bool MainWindow::ShowWareHouseInfo(int id)
{
    bool res = database->ShowWareHouseInfo(id);
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

void MainWindow::onShow_tablesPressed()
{
    Show_tables();
}

void MainWindow::onShow_table_dataPressed()
{
    Show_table_data(ui->showDataLineEdit->text(), ui->showDataIdSpinBox->value());
}

void MainWindow::onShowSingleProductInfoPressed()
{
    ShowSingleProductInfo(ui->showSingleProductInfospinBox->value());
}

void MainWindow::onShowInnerInfoPressed()
{
    ShowInnerInfo(ui->showInnerInfoSpinBox->value());
}

void MainWindow::onShowWarehouseInfoPressed()
{
    ShowWareHouseInfo(ui->showInnerInfoSpinBox->value());
}

