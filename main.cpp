#include <QDebug>
#include <QApplication>

#include <memory>
#include <vector>

#include "mainwindow.h"

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

//    std::string input;
//    std::cout << "This is demo C++/MYSQL application, supporting commands\n"
//                 "are shown below. Please, choose one of them\n"
//                 "To exit the application input \"exit\"" << std::endl;

//    do
//    {
//        std::cout << "\"tables\" - to show list of tables\n"
//                     "\"show table data\" - to show data of the\n"
//                     "choosen table\n"
//                     "\"show data\" - to show all data\n"
//                     "\"Control\" - to show attendance control info\n"
//                     "\"insert\" - to display control info\n"
//                     "\"remove\" - to remove row in a table\n"
//                     "To exit the application input \"exit\"" << std::endl;

//        std::cout << "Your command: ";
//        std::cin >> input;

//        if(input == "tables")
//        {
//            w.Show_tables();
//            a.exec();
//
//        }
//        else if (input == "show table data")
//        {

//        }

//    }while(input != "exit");



//    w.Show_tables();

//    w.Show_data(table_worker_info);

//    w.Show_data(table_schedule, 1);

//    w.Show_table_data(table_autorizations);

//    w.Show_table_data(table_autorizations, 1);

//    w.Attendance_control();

//    w.Attendance_control(2);

//    w.Remove_raw(table_position, "pos_name", "test");
//    w.Insert_data(table_position, test_position_data);

    w.show();
    return a.exec();
}
