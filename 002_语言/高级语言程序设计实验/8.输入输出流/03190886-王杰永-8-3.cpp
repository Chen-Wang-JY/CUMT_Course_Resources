#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream f5("f5.txt",ios::in);
    fstream f6("f6.txt",ios::out);
    if(!f5&&!f6){
        cout<<"文件读取失败!";
        return -1;
    }
    char ch[500];bool flag=false;
    while(f5.getline(ch,500)){
        flag=false;
        char* p=ch;
        while(*p!='\0'){
            
            if(*p!='/'){
                f6<<*p;
                cout<<*p;
                flag=true;
            }
            else if(*p=='/'&&*(p+1)=='/'){
                break;
            }
            p++;
        }
        if(flag){
            f6<<'\n';
            cout<<endl;
        }
    }
    system("pause");
    return 0;
}