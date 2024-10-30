#include <iostream>
#include <vector>
#include <memory>


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

//6.1

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

    return 0;
}
