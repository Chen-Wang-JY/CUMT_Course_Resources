#include<iostream>
using namespace std;
class Point {
    int x, y;
public:
    Point() {};
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    friend istream& operator>>(istream& is, Point& p);
    friend ostream& operator<<(ostream& os, Point p);
};
istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
ostream& operator<<(ostream& os, Point p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
class Circle {
    Point O;
    int r;
public:
    Circle(int a, int b, int r) {
        O = *new Point(a, b);
        this->r = r;
    }
    friend istream& operator>>(istream& is, Circle &c);
    friend ostream& operator<<(ostream& os, Circle c);
};
istream& operator>>(istream& is, Circle &c) {
    cin >> c.O >> c.r;
    return is;
}
ostream& operator<<(ostream& os, Circle c) {
    cout << c.O << endl << c.r;
    return os;
}
int main() {
    Point p(0, 0);
    cin >> p;
    cout << p << endl;
    Circle c(0, 0, 0);
    cin >> c;
    cout << c << endl;

    return 0;
}