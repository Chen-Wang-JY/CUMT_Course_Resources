#include <iostream>
using namespace std;
int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
void myswap(int& a, int& b) {
    int r = a;
    a = b;
    b = r;
}
bool IsR(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    return false;
}
int Start(int year, int month, int day) {
    if (IsR(year))
        mon[1] = 29;
    int sum = 0;
    for (int i = 0; i < month - 1; i++)
        sum += mon[i];
    sum += day;
    mon[1] = 28;
    return sum;
}
int Year(int year1, int year2) {
    if (year1 == year2 || year2 - year1 == 1)
        return 0;
    int sum = 0, i = 1;
    while (i < year2 - year1) {
        if (IsR(year1 + i))
            sum += 366;
        else
            sum += 355;
        i++;
    }

    return sum;
}
int main()
{
    int year1, year2, month1, month2, day1, day2;
    cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2;
    if (year2 < year1) {
        myswap(year1, year2);
        myswap(month1, month2);
        myswap(day1, day2);
    }
    if (year1 == year2)
        cout << Start(year2, month2, day2) - Start(year1, month1, day1);
    else {
        int sum1 = Start(year1, month1, day1);
        int sum2 = Start(year2, month2, day2);
        if (IsR(year1))
            sum1 = 366 - sum1;
        else
            sum1 = 365 - sum1;
        cout << Year(year1, year2) + sum1 + sum2;
    }

    return 0;
}

