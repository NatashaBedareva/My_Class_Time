#include <gtest/gtest.h>
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
    int getHoure(){ return hour;};
    int getMin(){ return min;};
    int getSeconds(){ return second;};

    int getCount(){return count;};

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


TEST(TimeTestCosyruct, BasicAssertions3) {
    Time t;
    EXPECT_EQ(t.getCount(), 1);
    Time t2;
    Time t3;
    EXPECT_EQ(t3.getCount(), 3);
    EXPECT_EQ(t.getCount(), 3);
    Time t4;
    EXPECT_EQ(t4.getCount(), 4);
    EXPECT_EQ(t3.getCount(), 4);
}


TEST(TimeTestSet, BasicAssertions) {
    Time t = Time(2,10,10);
    t.setHour(5);
    EXPECT_EQ(t.getHoure(), 5);
    t.setMin(80);
    EXPECT_EQ(t.getMin(), 20);

    EXPECT_EQ(t.getSeconds(), 10);
    t.printTime();
}

TEST(TimeTestNormilize, BasicAssertions2) {
    Time t = Time(2,10,10);
    Time t2 = Time(10,55,65);

    EXPECT_EQ(t2.getMin(), 56);
    EXPECT_EQ(t2.getSeconds(), 5);

    t+=t2;
    t.printTime();

    EXPECT_EQ(t.getHoure(), 13);
    EXPECT_EQ(t.getMin(), 5);
    EXPECT_EQ(t.getSeconds(), 15);

}


