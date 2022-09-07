#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;

class Base
{
private:
    int price; char place[10], material[10];
public:
    Base(int pri, char* pla, char* mat)
    {
        price = pri;
        strcpy(place, pla);
        strcpy(material, mat);
    }
    int GetPrice() { return price; }
    void Display()
    {
        cout << price << " " << place << " " << material;
    }
};

class shirt :public Base
{
public:
    shirt(int pri, char* pla, char* mat) :Base(pri, pla, mat) {}
    void shirtDisplay() { Base::Display(); }
    int GetPrice() { return Base::GetPrice(); }
};

class cap :public Base
{
private:
    char style[10];
public:
    cap(int pri, char* pla, char* mat, char* sty) :Base(pri, pla, mat)
    {
        strcpy(style, sty);
    }
    int GetPrice() { return Base::GetPrice(); }
    void Display()
    {
        Base::Display();
        cout << " " << style;
    }
};

class Wardrobe :public Base
{
private:
    char color[10];
public:
    Wardrobe(int pri, char* pla, char* mat, char* col) :Base(pri, pla, mat)
    {
        strcpy(color, col);
    }
    int GetPrice() { return Base::GetPrice(); }
    void Display()
    {
        Base::Display();
        cout << " " << color;
    }
};

int main()
{
    int pri; char pla[10], mat[10], sty[10], col[10];
    cout << "5 * shirt data in: price/place/material =>";
    cin >> pri >> pla >> mat; cout << endl;
    shirt s1(pri, pla, mat);
    cout << "3 * shirt data in: price/place/material =>";
    cin >> pri >> pla >> mat; cout << endl;
    shirt s2(pri, pla, mat);
    for (int i = 1; i <= 5; i++) { s1.Display(); cout << endl; }
    for (int i = 1; i <= 3; i++) { s2.Display(); cout << endl; }
    cout << "shiSto.TotalPrice()=" << (s1.GetPrice() * 5 + s2.GetPrice() * 3) << endl;
    for (int i = 1; i <= 4; i++) { s1.Display(); cout << endl; }
    cout << "shiSto.TotalPrice()=" << (s1.GetPrice() * 4) << endl;
    cout << "5 * Cap data in: price/place/material/style =>";
    cin >> pri >> pla >> mat >> sty; cout << endl;
    cap c1(pri, pla, mat, sty);
    cout << "3 * Cap data in: price/place/material/style =>";
    cin >> pri >> pla >> mat >> sty; cout << endl;
    cap c2(pri, pla, mat, sty);
    for (int i = 1; i <= 5; i++) { c1.Display(); cout << endl; }
    for (int i = 1; i <= 3; i++) { c2.Display(); cout << endl; }
    cout << "capSto.TotalPrice()=" << (c1.GetPrice() * 5 + c2.GetPrice() * 3) << endl;
    for (int i = 1; i <= 4; i++) { c1.Display(); cout << endl; }
    cout << "capSto.TotalPrice()=" << (c1.GetPrice() * 4) << endl;
    cout << "5 * Wardrobe data in: price/place/material/color =>";
    cin >> pri >> pla >> mat >> col; cout << endl;
    Wardrobe w1(pri, pla, mat, col);
    cout << "3 * Wardrobe data in: price/place/material/color =>";
    cin >> pri >> pla >> mat >> col; cout << endl;
    Wardrobe w2(pri, pla, mat, col);
    for (int i = 1; i <= 5; i++) { w1.Display(); cout << endl; }
    for (int i = 1; i <= 3; i++) { w2.Display(); cout << endl; }
    cout << "WarSto.TotalPrice()=" << (w1.GetPrice() * 5 + w2.GetPrice() * 3) << endl;
    for (int i = 1; i <= 4; i++) { w1.Display(); cout << endl; }
    cout << "WarSto.TotalPrice()=" << (w1.GetPrice() * 4) << endl;
    return 0;
}