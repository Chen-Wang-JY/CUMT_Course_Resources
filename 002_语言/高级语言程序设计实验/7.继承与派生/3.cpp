#include<iostream>
#include<string>
using namespace std;
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
class DateType {
    int y, m, d;
public:
    void setDate(int y, int m, int d) {
        this->y = y;
        this->m = m;
        this->d = d;
    }
    void IncrementDay();
    void PrintDate();
};
void DateType::IncrementDay() {
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        month[1] = 29;
    if (d == month[m - 1]) {
        d = 1;
        if (m == 12) {
            m = 1;
            y++;
        }
        else
            m++;
    }
    else
        d++;
    month[1] = 28;
}

void DateType::PrintDate() {
    cout << y << "-" << m << "-" << d;
}

class TimeType {
public:
	int h;
	int m;
	int s;
public:
    void setTime(int h, int m, int s) {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void PrintTime() {
        cout << h << ":" << m << ":" << s;
    }
};


class DateTimeType {  
	DateType date; 
	TimeType time; 
public:
    DateTimeType(int y0 = 1, int m0 = 1, int d0 = 1, int hr0 = 0, int mi0 = 0, int se0 = 0)  {
        date.setDate(y0, m0, d0);
        time.setTime(hr0, mi0, se0);
    }
	DateType& GetDate() { return date; } 
	TimeType& GetTime() { return time; }
    void IncrementSecond(int s) 
    {
        long total = time.h * 3600 + time.m * 60 + time.s;

        int xx = (total + s) / 86400;
        for (int i = 0; i < xx; i++)
            date.IncrementDay();

        long newtotal = (total + s)% 86400;
        int newh = newtotal / 3600;
        newtotal -= (newh * 3600);
        int newm = newtotal / 60;
        newtotal -= (newm * 60);
        int news = newtotal ;
        time.h = newh;
        time.m = newm;
        time.s = news;


    }
    void PrintDateTime() 
    {
        date.PrintDate(); cout << " ";
        time.PrintTime(); cout << endl;
    }
};

int  main() {
	DateTimeType dttm1(1999, 12, 31, 23, 59, 59), dttm2;
	(dttm1.GetDate()).PrintDate();
	cout << endl;
	dttm1.PrintDateTime();
	dttm2.PrintDateTime();
	dttm1.IncrementSecond(30); 
	dttm1.PrintDateTime();
    return 0;
}