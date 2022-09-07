#pragma once
#include<iostream>
#include"SeqList.cpp"
using namespace std;
template<typename T>
void PaiXu(SeqList<T>& s) {
    T x,y,min;
    for (int i = 1; i <= s.Length() ; i++) {
        for (int j = 1; j <= s.Length()-1; j++) {
            s.getData(j, x);
            s.getData(j+1, y);
            if (x > y) {
                T r = x;
                s.setData(j, y);
                s.setData(j + 1, r);
            }
        }
    }
}
template<typename T>
void GuiBing(SeqList<T>& s1, SeqList<T>& s2, SeqList<T>& s) {
    int i = 1, j = 1;
    while (i <= s1.Length() || j <= s2.Length()) {
        T x1, x2;
        s1.getData(i, x1);
        s2.getData(j, x2);
        if (i <= s1.Length() && j <= s2.Length()) {
            if (x1 > x2) {
                s.Insert(s.Length(), x2);
                j++;
            }
            else {
                s.Insert(s.Length(), x1);
                i++;
            }
        }
        else if (i <= s1.Length() && j > s2.Length()) {
            s.Insert(s.Length(), x1);
            i++;
        }
        else if (i > s1.Length() && j <= s2.Length()) {
            s.Insert(s.Length(), x2);
            j++;
        }
    }
}
int main(){


    SeqList<int> s1,s2;
    s1.Input();
    s2.Input();
    SeqList<int> s3(s1.Length()+s2.Length());
    PaiXu(s1);
    PaiXu(s2);
    GuiBing(s1,s2,s3);
    s3.Output();cout<<endl;
    system("pause");
    return 0;
}
