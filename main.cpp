#include <iostream>


class Time
{
    int hour;
    int min;
    int second;


    void Normalize()
    {

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


public:
    static int count;

    Time(int h=0, int m=0, int s=0): hour(h),min(m),second(s)
    {
        count++;
        Normalize();
        std::cout<<"Create new Time. Count = "<<count<<std::endl;
    }

    void printTime()
    {
        std::cout<<hour<<':'<<min<<':'<<second<<std::endl;
    }
    void setHour(int value) {this->hour=value;Normalize();};
    void setMin (int value) {this->min=value;Normalize();};
    void setSecond(int value) {this->second=value;Normalize();};

    int ToSeconds(){return (hour*60*60+min*60+second);}
    int getHoure(){ return this->hour;};
    int getMin(){ return this->min;};
    int getSeconds(){ return this->second;};

    int getCount(){return this->count;};

    Time operator+ (const Time& other) const {
        Time result;
        result.hour = hour + other.hour;
        result.min = min + other.min;
        result.second = second + other.second;
        result.Normalize();
        return result;
    }

    Time operator- (const Time& other) const {
        Time result;
        result.hour = hour - other.hour;
        result.min = min - other.min;
        result.second = second - other.second;
        result.Normalize();
        return result;
    }
    Time& operator-= (const Time& other) {

        this->hour = this->hour - other.hour;
        this->min = this->min - other.min;
        this->second = this->second - other.second;
        this->Normalize();
        return *this;
    }
    Time& operator+= (const Time& other) {

        this->hour = this->hour + other.hour;
        this->min = this->min + other.min;
        this->second = this->second + other.second;
        this->Normalize();
        return *this;
    }

    Time& operator= (const Time& other) {
        this->hour = other.hour;
        this->min = other.min;
        this->second = other.second;
        this->Normalize();
        return  *this;
    }

    bool operator== (const Time& other) const {
        if ((this->hour == other.hour)&&(this->min == other.min)&&(this->second == other.second))
        {
            return true;
        }
        return  false;
    }

    ~Time()
    {
        count--;
        std::cout<<"Destroy Time. Count = "<<this->getCount()<<std::endl;
    }

};

int Time::count = 0;

int main() {

    Time t(1,20,50);
    Time t2(12,-5,6);
    Time t3(10,10,10);

    t2=t;
    (t+t2).printTime();
    (t3-t).printTime();

    t.printTime();
    t2.printTime();

    t3+=t;
    (t3+t);

    t3.setHour(5);
    t3.setMin(10);
    t3.printTime();

    return 0;
}
