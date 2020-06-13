#include <QDebug>
#include <QApplication>

#include <memory>
#include <vector>

#include "mainwindow.h"

#include "gtest/gtest.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    std::vector<QString> position_data(3);
    position_data[0]="3";
    position_data[1]="streetBuilder";
    position_data[2] = "take zhittya";

    std::vector<QString> autorization_data(3);
    autorization_data[0]="2";
    autorization_data[1]="2020-11-04 08:11:33";
    autorization_data[2] = "2020-11-04 17:43:34";

    std::vector<QString> worker_info_data(4);
    worker_info_data[0]= "4";
    worker_info_data[1]="Str. Leto's Garet, 3";
    worker_info_data[2] = "+355234521";
    worker_info_data[3] = "num4@example.com";

    std::vector<QString> schedule_data(3);
    schedule_data[0]= "4";
    schedule_data[1]="2020:11:03 13:45:00";
    schedule_data[2] = "2020:11:03 21:00:00";

    std::vector<QString> test_position_data(3);
    schedule_data[0]= "101";
    schedule_data[1]="2020:11:03 13:45:00";
    schedule_data[2] = "2020:11:03 21:00:00";

    QString table_autorizations = "autorizations";
    QString table_workers = "workers";
    QString table_position = "position";
    QString table_schedule= "schedule";
    QString table_worker_info = "worker_info";

    w.Connect_database();

    w.Show_tables();

    w.Show_data(table_worker_info);

    //w.Show_data(table_position, 1);

    //w.Show_table_data(table_autorizations);

    //w.Show_table_data(table_autorizations, 1);

    //w.Attendance_control();

    //w.Attendance_control(2);

    //w.Remove_raw(table_position, "pos_name", "test");

    //w.Show_table_data(table_position);

    //w.Insert_data(table_position, test_position_data);

    ::testing::InitGoogleTest (&argc, argv);
    RUN_ALL_TESTS();

    return a.exec();
}



TEST (Business_Logic, Show_tables)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.Show_tables());

    w.Close_database();
    w.close();
}


TEST (Business_Logic, Show_table_data)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.Show_table_data("workers"));
    EXPECT_TRUE(w.Show_table_data("autorizations"));
    EXPECT_TRUE(w.Show_table_data("position"));
    EXPECT_TRUE(w.Show_table_data("schedule"));
    EXPECT_TRUE(w.Show_table_data("worker_info"));

    w.Close_database();
    w.close();
}

TEST (Business_Logic, Show_data)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.Show_data("workers"));
    EXPECT_TRUE(w.Show_data("autorizations"));
    EXPECT_TRUE(w.Show_data("position"));
    EXPECT_TRUE(w.Show_data("schedule"));
    EXPECT_TRUE(w.Show_data("worker_info"));

    w.Close_database();
    w.close();
}

TEST (Business_Logic, Insert_data)
{
    MainWindow w;
    w.Connect_database();

    std::vector<QString> data(3);
    data[0] = "11";
    data[1] = "test";
    data[2] = "test";

    EXPECT_TRUE(w.Insert_data("position", data));

    w.Close_database();
    w.close();
}

TEST (Business_Logic, Remove_raw)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.Remove_raw("position", "pos_name", "test"));

    w.Close_database();
    w.close();
}

TEST (Business_Logic, Attendance_control)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.Attendance_control());

    w.Close_database();
    w.close();
}



TEST (Repository_logic, Show_tables)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.database->Show_tables());

    w.Close_database();
    w.close();
}


TEST (Repository_logic, Show_table_data)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.database->Show_table_data("workers"));
    EXPECT_TRUE(w.database->Show_table_data("autorizations"));
    EXPECT_TRUE(w.database->Show_table_data("position"));
    EXPECT_TRUE(w.database->Show_table_data("schedule"));
    EXPECT_TRUE(w.database->Show_table_data("worker_info"));

    w.Close_database();
    w.close();
}

TEST (Repository_logic, Show_data)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.database->Show_data("workers", 0));
    EXPECT_TRUE(w.database->Show_data("autorizations", 0));
    EXPECT_TRUE(w.database->Show_data("position", 0));
    EXPECT_TRUE(w.database->Show_data("schedule", 0));
    EXPECT_TRUE(w.database->Show_data("worker_info", 0));

    w.Close_database();
    w.close();
}

TEST (Repository_logic, Insert_data)
{
    MainWindow w;
    w.Connect_database();

    std::vector<QString> data(3);
    data[0] = "101";
    data[1] = "test";
    data[2] = "test";

    EXPECT_TRUE(w.database->Insert_data("position", data));

    w.Close_database();
    w.close();
}

TEST (Repository_logic, Remove_raw)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.database->Remove_raw("position", "pos_name", "test"));
    w.Close_database();
    w.close();
}

TEST (Repository_logic, Attendance_control)
{
    MainWindow w;
    w.Connect_database();

    EXPECT_TRUE(w.database->Attendance_control());

    w.Close_database();
    w.close();
}
