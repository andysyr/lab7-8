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

    if (!db.open())
    {
        qDebug() << "Cannot open database:" << db.lastError();
    }
    else
    {
        qDebug() << "Database opened.";
    }
}

void Database::Show_tables()
{
        foreach (QString str, db.tables())
        {
            qDebug()<< " table: " + str;
        }
}

void Database::Show_table_data (QString table_name)
{
    model_read.setQuery("SELECT *FROM " + table_name);
    view.setModel(&model_read);
}

void Database::Insert_data (QString table_name, std::vector<QString> data)
{
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
}

void Database::Input_data(QString table_name, std::vector<QString> data)
{
    model_read_write.setTable(table_name);
    model_read_write.setEditStrategy(QSqlTableModel::OnFieldChange);

    model_read_write.select();
    qDebug() << model_read_write.lastError();

    if(data.size() != model_read_write.columnCount())
    {
        qDebug()<<"wrong amount of arguments, columns: " << model_read_write.columnCount();
        return;
    }

    int row = model_read_write.rowCount();

    model_read_write.insertRows(row, 0);

    for (int i = 0; i < data.size(); i++)
    {
        model_read_write.setData(model_read_write.index(row, 1), data[i+1]);
    }

    view.setModel(&model_read_write);
    //view.show();
}

void Database::Show_data(QString table, int id)
{
    QString temp = "SELECT * FROM workers LEFT JOIN " + table + " ON workers.id = " + table + ".id";

    if(id != 0)
    {
        temp += " WHERE workers.id = " + QString::number(id);
    }

    model_read.setQuery(temp);
    view.setModel(&model_read);
}

void Database::Attendance_control(int id)
{
    QString temp = "SELECT * FROM workers LEFT JOIN schedule ON workers.id = schedule.id INNER JOIN autorizations ON workers.id = autorizations.id";

    if(id != 0)
    {
        temp += " WHERE workers.id = " + QString::number(id);
    }

    model_read.setQuery(temp);
    view.setModel(&model_read);
}

void Database::Remove_raw(QString table_name, QString column, QString data)
{
    model_read.setQuery("DELETE FROM " + table_name + " WHERE " + column + " = " + data);
    view.setModel(&model_read);
}


void Database::Close_database()
{
    db.close();
}
