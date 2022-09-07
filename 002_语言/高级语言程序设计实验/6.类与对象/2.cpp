#include<iostream>
using namespace std;
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
class DateType {
    int y, m, d;
public:
    DateType(int y = 1, int m = 1, int d = 1) {
        this->y = y;
        this->m = m;
        this->d = d;
    }
    void IncrementDay();
    bool Equal(DateType dt2);
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
bool DateType::Equal(DateType dt2) {
    if (this->y==dt2.y&&this->m==dt2.m&&this->d==dt2.d)
        return true;
    else
        return false;
}
void DateType::PrintDate() {
    cout << y << ":" << m << ":" << d;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    DateType dt1(y1, m1, d1), dt2(y2, m2, d2);
    dt1.PrintDate(); cout << endl;
    dt2.PrintDate(); cout << endl;
    if (dt1.Equal(dt2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    dt1.IncrementDay();
    dt2.IncrementDay();
    dt1.PrintDate(); cout << endl;
    dt2.PrintDate(); cout << endl;
    return 0;
}