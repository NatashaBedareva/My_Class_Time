#include <iostream>
#include <vector>
#include <memory>
#include <string>

struct WrongAgeExceptionHour {
    int h;
    WrongAgeExceptionHour(int hour): h(hour){
        std::cerr<<"hour is not correct: ";
    };
};
struct WrongAgeExceptionMin {
    int m;
    WrongAgeExceptionMin(int min): m(min){
        std::cerr<<"min is not correct: ";
    };
};
struct WrongAgeExceptionSecond {
    int s;
    WrongAgeExceptionSecond(int second): s(second){
        std::cerr<<"second is not correct: ";
    };
};


class Time {
    int hour{};
    int min{};
    int second{};


    void Normalize() {


        if (second >= 60) {
            min += second / 60;
            second %= 60;
        } else if (second < 0) {
            min -= (-second + 59) / 60;
            second = (second % 60 + 60) % 60;
        }

        if (min >= 60) {
            hour += min / 60;
            min %= 60;
        } else if (min < 0) {
            hour -= (-min + 59) / 60;
            min = (min % 60 + 60) % 60;
        }
        if (hour >= 24) {
            hour %= 24;
        } else if (hour < 0) {
            hour = (hour % 24 + 24) % 24;
        }
    }

    void MyExept(int h=0, int m=0, int s=0)
    {
        if(h<0)       throw WrongAgeExceptionHour(h);
        else if (m<0) throw WrongAgeExceptionMin(m);
        else if (s<0) throw WrongAgeExceptionSecond(s);
    }


public:
    static int count;


    Time()
    {
        count++;
        std::cout<<"Create new Time. Count = "<<count<<std::endl;
    }

    Time(int h, int m, int s)
    {
        hour = h;
        min = m;
        second = s;

        MyExept(h,m,s);


        count++;
        Normalize();
        std::cout<<"Create new Time. Count = "<<count<<std::endl;
    }

    void printTime() noexcept
    {
        std::cout<<hour<<':'<<min<<':'<<second<<std::endl;
    }
    void setHour(int value) {this->hour=value;MyExept(hour,min,second);Normalize();};
    void setMin (int value) {this->min=value;MyExept(hour,min,second);Normalize();};
    void setSeconds(int value) {this->second=value;MyExept(hour,min,second);Normalize();};

    int ToSeconds() noexcept {return (hour*60*60+min*60+second);}
    int getHoure()noexcept{ return this->hour;};
    int getMin()noexcept{ return this->min;};
    int getSeconds()noexcept{ return this->second;};

    int getCount()noexcept{return this->count;};

    Time operator+ (const Time& other) const noexcept{
        Time result;
        result.hour = hour + other.hour;
        result.min = min + other.min;
        result.second = second + other.second;
        result.Normalize();
        return result;
    }

    Time operator- (const Time& other) const noexcept{
        Time result;
        result.hour = hour - other.hour;
        result.min = min - other.min;
        result.second = second - other.second;
        result.Normalize();
        return result;
    }
    Time& operator-= (const Time& other) noexcept{

        this->hour = this->hour - other.hour;
        this->min = this->min - other.min;
        this->second = this->second - other.second;
        this->Normalize();
        return *this;
    }
    Time& operator+= (const Time& other) noexcept{

        this->hour = this->hour + other.hour;
        this->min = this->min + other.min;
        this->second = this->second + other.second;
        this->Normalize();
        return *this;
    }

    Time& operator= (const Time& other) noexcept{
        this->hour = other.hour;
        this->min = other.min;
        this->second = other.second;
        this->Normalize();
        return  *this;
    }

    bool operator== (const Time& other) const noexcept{
        if ((this->hour == other.hour)&&(this->min == other.min)&&(this->second == other.second))
        {
            return true;
        }
        return  false;
    }

    ~Time() noexcept
    {
        count--;
        std::cout<<"Destroy Time. Count = "<<this->getCount()<<std::endl;
    }

    friend class SimpleWatch;
    friend class Watch;

};
int Time::count = 0;


class Watch
{
    bool formatIs24 = true;
public:
    void WhatTime(const Time& t) const
    {
        if (formatIs24) std::cout<<t.hour<<":"<<t.min<<":"<<t.second<<std::endl;
        else
        {
            if(t.hour>12) std::cout<<t.hour-12<<":"<<t.min<<":"<<t.second<<" PM"<<std::endl;
            else std::cout<<t.hour<<":"<<t.min<<":"<<t.second<<" AM"<<std::endl;
        }
    }
    void setTimeHour(Time& t,int h){t.hour = h;}
    void setTimeMin(Time& t, int m){t.min = m;}
    void setTimeSecond(Time& t, int s){t.second = s;}

    void setFormat(bool f)
    {
        formatIs24 = f;
    }

    friend class SimpleWatch;
};

class SimpleWatch
{

public:

    void WhatTime(const Time& t) const {
        std::cout << t.hour << ":" << t.min << ":" << t.second << std::endl;
    }
    void WhatTime(const Time& t, const Watch& w) const
    {
        if (w.formatIs24) std::cout<<t.hour<<":"<<t.min<<":"<<t.second<<std::endl;
        else
        {
            if(t.hour>12) std::cout<<t.hour-12<<":"<<t.min<<":"<<t.second<<" PM"<<std::endl;
            else std::cout<<t.hour<<":"<<t.min<<":"<<t.second<<" AM"<<std::endl;
        }
    }
    void setTimeHour(Time& t,int h){t.hour = h;}
    void setTimeMin(Time& t, int m){t.min = m;}
    void setTimeSecond(Time& t, int s){t.second = s;}

};


int main() {

//7.1
    {
        Time t{10, 30, 45};
        SimpleWatch simpleWatch;
        Watch watch;

        simpleWatch.WhatTime(t);
        watch.WhatTime(t);

        simpleWatch.setTimeHour(t, 20);

        simpleWatch.WhatTime(t);
        watch.WhatTime(t);

        watch.setFormat(false);
        simpleWatch.WhatTime(t,watch);
    }


//6.2

    {
        try {
            Time t_exept {5,8,20};
        }
        catch (const WrongAgeExceptionHour& ex) {
            std::cerr << ex.h;
            return 1;
        }
        catch (const WrongAgeExceptionMin& ex) {
            std::cerr << ex.m;
            return 1;
        }
        catch (const WrongAgeExceptionSecond& ex) {
            std::cerr << ex.s;
            return 1;
        }

        Time t_exept;

        try {
            t_exept.setSeconds(-50);
        }
        catch (const WrongAgeExceptionHour& ex) {
            std::cerr << ex.h;
            return 1;
        }
        catch (const WrongAgeExceptionMin& ex) {
            std::cerr << ex.m;
            return 1;
        }
        catch (const WrongAgeExceptionSecond& ex) {
            std::cerr << ex.s;
            return 1;
        }
    }





//6.1
/*

    {
        Time *t1 = new Time (20,20,60);
        t1->printTime();
        delete t1;
        t1 = nullptr;

        Time *t {new Time [3]{Time (10,10,10),Time(20,20,20),Time(10,30,30)}};

        for(int i=0;i<3;i++)
        {
            (t[i]).printTime();
        }

        delete[] t;
        t = nullptr;

        std::unique_ptr<Time> t_unique = std::make_unique<Time>(Time (25,25,25));
        t_unique->setHour(20);
        t_unique->printTime();

        std::shared_ptr<Time> t_shared1 = std::make_shared<Time>(Time (10,26,26));
        auto t_shared2 = t_shared1;

        t_shared2->printTime();


        std::vector<Time> t_vector;

        t_vector.push_back(Time(20,20,20));

        for(int i=0;i<t_vector.size();i++)
        {
            t_vector[i].printTime();
        }
    }
*/


    return 0;
}
