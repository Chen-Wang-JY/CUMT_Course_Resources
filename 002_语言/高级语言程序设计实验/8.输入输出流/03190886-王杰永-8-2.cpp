#include<iostream>
#include<fstream>
using namespace std;
int main(){
   fstream file("f1.txt",ios::out);
   if(!file){
       cout<<"文件打开失败！";
       return -1;
   }
   for(int i=1;i<=15;i++)
        file<<double(i)*i+0.5<<" ";
    file.close();

    file.open("f2.txt",ios::out);
    if(!file){
        cout<<"文件打开失败！";
        return -1;
    }
    for(int i=1;i<=10;i++)
        file<<10.0*i+0.5<<" ";
    file<<357.9<<" ";
    file.close();

    double data[26];
    file.open("f1.txt",ios::in);
    if(!file){
        cout<<"文件打开失败！";
        return -1;
    }
    for(int i=0;i<15;i++)
        file>>data[i];
    file.close();

    file.open("f2.txt",ios::in);
    if(!file){
        cout<<"文件打开失败！";
        return -1;
    }
    for(int i=15;i<26;i++)
        file>>data[i];
    file.close();
    
    for(int i=0;i<25;i++){
        int r=i;
        for(int j=i+1;j<26;j++){
            if(data[i]>data[j])
                r=j;
        }
        double tmp=data[i];
        data[i]=data[r];
        data[r]=tmp;
    }
    file.open("f3.txt",ios::out);
    if(!file){
        cout<<"文件打开失败!";
        return -1;
    }
    for(int i=0;i<26;i++)
        file<<data[i]<<" ";
    file.close();
    system("pause");
    return 0;
}