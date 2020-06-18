#include <iostream>
#include <string>

using namespace std;

class Worker
{
private:
    double salary;

public:
    Worker(double _salary)
    {salary = _salary;}

    virtual double Get_salary()
    {return salary;}
};

class Salary_adapter: public Worker
{
private:
    Worker *worker = nullptr;

public:
    Salary_adapter(Worker *_worker) : Worker(_worker->Get_salary())
    {worker = _worker;}

    double Get_salary() override
    {return worker->Get_salary() * 0.033;}

};

class Payment
{
private:
    string data;

public:
    Payment(string _data)
    {
        data = _data;
    }

    double Calculate_payment(Worker *worker)
    {
        return worker->Get_salary();
    }
};


void Structural_patterns()
{
    Worker *worker = new Worker(10000);
    Salary_adapter *adapter = new Salary_adapter(worker);

    Payment payment("data");
    cout << payment.Calculate_payment(worker)<<endl;
    cout << payment.Calculate_payment(adapter) << endl;

    delete worker;
    delete adapter;
}
