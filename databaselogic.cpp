#include "databaselogic.h"
#include "mainwindow.h"

Database::Database(QString DatabaseName_, QString hostname_, QString username_, QString password_, MainWindow *window_):
    DatabaseName(DatabaseName_),hostname(hostname_), username(username_), password(password_), window(window_)
{
    window->Add_widget_to_layout(&view);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(DatabaseName);
    db.setHostName(hostname);
    db.setUserName(username);
    db.setPassword(password);

    if(!db.open())
    {
        std::cout<<"Failed to open database!" << std::endl;
    }
}

QStringList Database::Show_tables()
{
    if(!db.open())
    {
        return {};
    }
//        foreach (QString str, db.tables())
//        {
//            qDebug()<< " table: " + str;
//        }
    return db.tables();
}

bool Database::Show_table_data (QString table_name, int id)
{
    if(!db.open())
    {
        return false;
    }
    QString temp = "SELECT *FROM " + table_name;


    if(id != 0)
    {
        temp += " WHERE " + table_name + ".id = " + QString::number(id);
    }

    model_read.setQuery(temp);
    view.setModel(&model_read);
    return true;
}

bool Database::Insert_data (QString table_name, std::vector<QString> data)
{
    if(!db.open())
    {
        return false;
    }
    QString temp_string = "INSERT INTO " + table_name + " VALUES (";

    for (int i = 0; i < data.size(); i++)
    {
        temp_string += "'" + data[i] + "'";
        if(i != data.size() - 1)
        {
            temp_string += ", ";
        }
    }
    temp_string += ")";

    model_read.setQuery(temp_string);
    view.setModel(&model_read);

    return true;
}

bool Database::ShowSingleProductInfo(int id)
{
    if(!db.open())
    {
        return false;
    }
    QString temp = "SELECT * FROM singleproduct LEFT JOIN producttype ON singleproduct.serialNumber = producttype.idSingleProduct";

    if(id != 0)
    {
        temp += " WHERE singleproduct.serialNumber = " + QString::number(id);
    }

    model_read.setQuery(temp);
    view.setModel(&model_read);

    return true;
}

bool Database::ShowInnerInfo(int id)
{
    if(!db.open())
    {
        return false;
    }
    QString temp = "SELECT * FROM innerinfo LEFT JOIN producttype ON innerinfo.idInnerInfo = producttype.idSingleProduct";

    if(id != 0)
    {
        temp += " WHERE innerinfo.idInnerInfo = " + QString::number(id);
    }

    model_read.setQuery(temp);
    view.setModel(&model_read);

    return true;
}

bool Database::ShowWareHouseInfo(int id)
{
    if(!db.open())
    {
        return false;
    }
    QString temp = "SELECT * FROM warehouseinfo LEFT JOIN producttype ON warehouseinfo.idwarehouseInfo = producttype.idSingleProduct";

    if(id != 0)
    {
        temp += " WHERE warehouseinfo.idwarehouseInfo = " + QString::number(id);
    }

    model_read.setQuery(temp);
    view.setModel(&model_read);

    return true;
}

bool Database::Remove_raw(QString table_name, QString column, QString data)
{
    if(!db.open())
    {
        return false;
    }
    model_read.setQuery("DELETE FROM " + table_name + " WHERE " + column + " = " + "'" + data + "'");
    view.setModel(&model_read);

    return true;
}


bool Database::Close_database()
{
    if(!db.open())
    {
        return false;
    }
    db.close();

    return true;
}
