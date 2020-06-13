#include <QDebug>
#include <QApplication>

#include <memory>
#include <vector>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w1;

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

    QString table_autorizations = "autorizations";
    QString table_workers = "workers";
    QString table_position = "position";
    QString table_schedule= "schedule";
    QString table_worker_info = "worker_info";

    w1.Connect_database();

    //w1.Show_tables();

    w1.Show_data(table_position, 2);

    return a.exec();
}
