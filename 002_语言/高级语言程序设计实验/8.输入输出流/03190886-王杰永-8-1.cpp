#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int i;
    double d;
    char c;
    ofstream file("ft.txt",ios::out);
    if(!file){
        cout<<"文件打开错误！";
        return -1;
    }
    for(int k=1;k<=15;k++){
        i=2*k-1;
        d=k*k+k-9.8;
        c='H'+k;
        file<<i<<" "<<d<<" "<<c<<endl;
    }
    system("pause");
    return 0;
}