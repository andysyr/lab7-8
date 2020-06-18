#include <iostream>

class Position
{
public:
    Position() = default;

    virtual void AddSchedule() = 0;
};


class Creator
{
public:
    Creator() = default;

    virtual Position *FactoryMethod() = 0;
};


class Shef : public Position
{
public:
    void AddSchedule() override
    {
        std::cout << "Adding schedule of a new shef" << std::endl;
    }
};

class Waiter : public Position
{
    void AddSchedule() override
    {
        std::cout << "Adding schedule of a new waiter" << std::endl;
    }
};

class Barman : public Position
{
private:
    void AddSchedule() override
    {
        std::cout << "Adding schedule of a new barman" << std::endl;
    }
};

class ShefCreator : public Creator
{
public:
    Position *FactoryMethod() override
    {
        return new Shef();
    }
};

class WaiterCreator : public Creator
{
public:

    Position *FactoryMethod() override
    {
        return new Waiter();
    }
};

class BarmanCreator : public Creator
{
public:

    Position *FactoryMethod() override
    {
        return new Barman();
    }
};

void Creational_patterns()
{
    BarmanCreator barman;
    Position *position = barman.FactoryMethod();

    position->AddSchedule();

    delete position;


    WaiterCreator waiter;
    position = waiter.FactoryMethod();

    position->AddSchedule();

    delete position;

    ShefCreator shef;
    position = shef.FactoryMethod();

    position->AddSchedule();

    delete position;
}
