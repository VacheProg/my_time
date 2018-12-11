#include <iostream>
using namespace std;
#include <string>
class error //my abstract class
{
    string problem;

  public:
    virtual string what()
    {
        return problem;
    }
};

//MY ERRORS

class out_of_range_second : public error
{
    string problem;

  public:
    out_of_range_second(string text) : problem(text)
    {
    }
    string what() override
    {
        return problem;
    }
};
class out_of_range_minute : public error
{
    string problem;

  public:
    out_of_range_minute(string text) : problem(text)
    {
    }
    string what() override
    {
        return problem;
    }
};
class out_of_range_hour : public error
{
    string problem;

  public:
    out_of_range_hour(string text) : problem(text)
    {
    }
    string what() override
    {
        return problem;
    }
};
class not_valid_time : public error
{
    string problem;

  public:
    not_valid_time(string text) : problem(text)
    {
    }
    string what() override
    {
        return problem;
    }
};
class out_of_range_while_adding : public error
{
    string problem;

  public:
    out_of_range_while_adding(string text) : problem(text)
    {
    }
    string what() override
    {
        return problem;
    }
};

class mytime
{
    int second;
    int minute;
    int hour;

  public:
    mytime(int hour = 0, int min = 0, int sec = 0)
    {
        if ((hour <= 24) && (hour >= 0))
        {
            this->hour = hour;
            if ((min >= 0) && (min <= 60))
            {
                this->minute = min;
                if ((sec >= 0) && (sec <= 60))
                {
                    this->second = sec;
                }
                else
                {
                    throw out_of_range_second("second out of range / wrong constructor number");
                }
            }
            else
            {
                throw out_of_range_minute("minute out of range / wrong constructor number");
            }
        }
        else
        {
            throw out_of_range_hour("hour out of range / wrong constructor number");
        }
    }
    void addsec(int asec);
    void addmin(int amin);
    void addhour(int ah);
    void operator=(mytime &temp);
    bool operator==(mytime &temp);
    bool operator!=(mytime &temp);
    bool operator>(mytime &temp);
    bool operator<(mytime &temp);
    void operator+=(mytime &temp);
    void operator-=(mytime &temp);
    int get_sec()
    {
        return this->second;
    }
    int get_min()
    {
        return this->minute;
    }
    int get_hour()
    {
        return this->hour;
    }
    void set_sec(int sec)
    {
        if (sec >= 0 && sec <= 60)
            this->second = sec;
        else
        {
            throw out_of_range_second("second out of range /  wrong set_sec function number");
        }
    }
    void set_min(int min)
    {
        if (min >= 0 && min <= 60)
            this->minute = min;
        else
            throw out_of_range_minute("minute out of range /  wrong set_min function number");
    }
    void set_hour(int h)
    {
        if (h >= 0 && h <= 24)
            this->hour = h;
        else
            throw out_of_range_hour("hour out of range /  wrong set_hour function number");
    }
    bool isvalid(mytime *temp)
    {
        if ((temp->hour >= 0) && (temp->hour <= 24) && (temp->minute >= 0) && (temp->minute <= 60) && (temp->second >= 0) && (temp->second <= 60))
            return true;
        else
            return false;
    }
    bool isvalid()
    {
        if ((this->hour >= 0) && (this->hour <= 24) && (this->minute >= 0) && (this->minute <= 60) && (this->second >= 0) && (this->second <= 60))
            return true;
        else
            return false;
    }
    bool isvalid(int h, int min, int sec)
    {

        if ((h >= 0) && (h <= 24) && (min >= 0) && (min <= 60) && (sec >= 0) && (sec <= 60))
            return true;
        else
            return false;
    }
    bool isNULL()
    {
        if ((this->hour == 0) && (this->minute == 0) && (this->second == 0))
            return true;
        else
            return false;
    }
};

void mytime::addsec(int asec)
{
    int temp = 60 * this->minute + 3600 * this->hour + this->second + asec;
    int h = temp / 3600;
    int m = (temp - 3600 * this->hour) / 60;
    int sec = temp - (this->hour * 3600 + 60 * this->minute);
    if (isvalid(h, m, sec))
    {
        this->second = sec;
        this->minute = m;
        this->hour = h;
    }
    else
    {
        throw out_of_range_while_adding("out of range / in addsec function wrong number");
    }
}

void mytime::addmin(int amin)
{
    int temp = this->minute + 60 * this->hour + amin;
    int h = temp / 60;
    int m = temp - 60 * this->hour;
    if (h, m, this->second)
    {
        this->hour = h;
        this->minute = m;
    }
    else
    {
        throw out_of_range_while_adding("out of range / in addmin function wrong number");
    }
}

void mytime::addhour(int ah)
{
    if (isvalid((this->hour + ah), this->minute, this->second))
    {
        this->hour += ah;
    }
    else
    {
        throw out_of_range_while_adding("out of range / in addhour function wrong number");
    }
}

bool mytime::operator==(mytime &temp)
{
    if ((this->hour == temp.hour) && (this->minute == temp.hour) && (this->second == temp.second))
    {
        return true;
    }
    else
        return false;
}

bool mytime::operator!=(mytime &temp)
{
    if ((this->hour == temp.hour) && (this->minute == temp.hour) && (this->second == temp.second))
    {
        return false;
    }
    else
        return true;
}

bool mytime::operator>(mytime &temp)
{
    if ((this->hour - temp.hour) > 0)
    {
        return true;
    }
    else
    {
        if ((this->minute - temp.minute) > 0)
        {
            return true;
        }
        else
        {
            if ((this->second - temp.second) > 0)
            {
                return true;
            }
            else
                return false;
        }
    }
}

bool mytime::operator<(mytime &temp)
{
    if ((this->hour - temp.hour) > 0)
    {
        return false;
    }
    else
    {
        if ((this->minute - temp.minute) > 0)
        {
            return false;
        }
        else
        {
            if ((this->second - temp.second) > 0)
            {
                return false;
            }
            else
                return true;
        }
    }
}

void mytime::operator+=(mytime &temp)
{
    mytime tempary = *this;
    ;
    tempary.second += temp.second;
    if (tempary.second > 60)
    {
        tempary.second -= 60;
        ++tempary.minute;
    }
    tempary.minute += temp.minute;
    if (tempary.minute > 60)
    {
        tempary.minute -= 60;
        ++tempary.hour;
    }
    tempary.hour += temp.hour;
    if (tempary.isvalid())
    {
        this->hour = tempary.hour;
        this->minute = tempary.minute;
        this->second = tempary.second;
    }

    else
        throw not_valid_time(" out of range/ wrong time in += operator");
}

void mytime::operator=(mytime &right_obj)
{
    this->second = right_obj.second;
    this->minute = right_obj.second;
    this->hour = right_obj.hour;
}

void mytime::operator-=(mytime &temp)
{
    mytime tempary = *this;
    if ((tempary.second -= temp.second) > 0)
    {
        --tempary.minute;
        tempary.second += 60;
    }
    if ((tempary.minute -= temp.minute < 0))
    {
        --tempary.hour;
        tempary.minute += 60;
    }
    tempary.hour -= temp.hour;
    if (tempary.isvalid())
    {
        this->second = tempary.second;
        this->minute = tempary.minute;
        this->hour = tempary.hour;
    }
    else
    {
        throw not_valid_time("out of range/ wrong time in -= operator");
    }
}

int main()
{
    try
    {
        mytime ftime(12, 15, 12);
        mytime stime(8, 26, 15);
        cout << (ftime > stime) << "----" << (ftime < stime) << "---" << (ftime != stime) << "---" << (ftime == stime);
        ftime += stime;
        ftime -= stime;
    }
    catch (error &temp)
    {
        cout << temp.what();
    }
    int b;
    return 0;
}