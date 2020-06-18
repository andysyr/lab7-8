#include <iostream>

using namespace std;


class ID_card
{
public:
    bool status;
    unsigned int id;

    ID_card(bool status_, unsigned int id_)
    {
        status = status_;
        id = id_;
    }
};

//parent virtual class for types of access
class Access
{
public:
    Access *next = nullptr;

    //availability of next checks
    Access *Set_next(Access *next_)
    {
        next = next_;
        return next;
    }

    //virtual method for checking different steps of access
    virtual bool Check_access(ID_card *object) = 0;
};

//status can be unavailable for some reasons
class Check_status: public Access
{
public:
    bool Check_access(ID_card *object) override
    {
        if(object->status)
        {
            if (next != nullptr)
            {
                return next->Check_access(object);
            }
            return true;
        }

        cout << "Your workstatus isn't active! Request denied."<<endl;
        return false;
    }
};

//checking id
class Check_ID: public Access
{
private:
    //check availability of current id in database
    bool ID_accessable(int id)
    {
        if(id >= 100 && id <= 200)
        {
            return true;
        }
        return false;
    }

public:
    bool Check_access(ID_card *object) override
    {
        if(ID_accessable(object->id))
        {
            if (next != nullptr)
            {
                return next->Check_access(object);
            }
            return true;
        }
        cout << "There is not your ID in database! Request denied."<<endl;
        return false;
    }
};


//checking for accordance worktime
class Check_time: public Access
{
    double *work_time_space = nullptr;
private:

public:
    explicit Check_time(double *work_time_space_)
    {
        work_time_space = work_time_space_;
        work_time_space_ = nullptr;
    }

    bool Check_access(ID_card *object) override
    {
        //instead of parsing
        double current_time = 10;

        if(current_time > work_time_space[0] && current_time < work_time_space[1])
        {
            if (next != nullptr)
            {
                return next->Check_access(object);
            }
            return true;
        }

        cout << "It isn't your worktime now! Request denied."<<endl;
        return false;
    }
};


//function of concrete constructoring chain of checkings. may be clientcode
void Access(ID_card *card)
{
    auto *time_arr = new double[2];
    time_arr[0] = 9.5;
    time_arr[1] = 18;

    auto *time_ = new Check_time(time_arr);

    auto *id = new Check_ID();

    auto *status = new Check_status();

    id->Set_next(time_)->Set_next(status);

    if(id->Check_access(card))
    {
        cout << "Request accepted!"<<endl;
    }

    delete []time_arr;
    delete id;
    delete status;
    delete time_;
}


//clientcode
void Behavioral_patterns_part2()
{
    auto *card = new ID_card(true, 120);
    Access(card);
}