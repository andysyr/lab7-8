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

    db.open();
}

bool Database::Show_tables()
{
    if(!db.open())
    {
        return false;
    }
        foreach (QString str, db.tables())
        {
            qDebug()<< " table: " + str;
        }
    return true;
}

bool Database::Show_table_data (QString table_name)
{
    if(!db.open())
    {
        return false;
    }
    model_read.setQuery("SELECT *FROM " + table_name);
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

bool Database::Show_data(QString table, int id)
{
    if(!db.open())
    {
        return false;
    }
    QString temp = "SELECT * FROM workers LEFT JOIN " + table + " ON workers.id = " + table + ".id";

    if(id != 0)
    {
        temp += " WHERE workers.id = " + QString::number(id);
    }

    model_read.setQuery(temp);
    view.setModel(&model_read);

    return true;
}

bool Database::Attendance_control(int id)
{
    if(!db.open())
    {
        return false;
    }
    QString temp = "SELECT * FROM workers LEFT JOIN schedule ON workers.id = schedule.id INNER JOIN autorizations ON workers.id = autorizations.id";

    if(id != 0)
    {
        temp += " WHERE workers.id = " + QString::number(id);
    }

    model_read.setQuery(temp);

    auto check = model_read_write.query();

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
