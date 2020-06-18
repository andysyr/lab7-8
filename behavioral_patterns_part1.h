#include <iostream>

using namespace std;


class B_Position
{
public:
    void Update()
    {
        this->Payment();
        this->SetSchedule();
    }

private:
    virtual void SetSchedule() = 0;

    void Payment()
    {
        cout << "Method Payment of abstract class" << endl;
    }
};

class Director : public B_Position
{
private:
    void SetSchedule() override
    {
        cout << "Method SetSchedule of Director class" << endl << endl;
    }
};

class Manager : public B_Position
{
private:
    void SetSchedule() override
    {
        cout << "Method SetSchedule of Manager class" << endl << endl;
    }
};

class Consultant : public B_Position
{
private:
    void SetSchedule() override
    {
        cout << "Method SetSchedule of Consultant class" << endl << endl;
    }
};


void Behavioral_patterns_part1()
{
    B_Position *dir = new Director();
    B_Position *man = new Manager();
    B_Position *con = new Consultant();

    cout << "Director object:" << endl;
    dir->Update();
    cout << "Manager object:" << endl;
    man->Update();
    cout << "Consultant object:" << endl;
    con->Update();

    delete man;
    delete con;
    delete dir;
}
