#pragma once
#include <iostream>
#include"SeqList.cpp"
using namespace std;


int main()
{
    SeqList<int> s(11);//创建容量为11的顺序表
    s.Input();         //输入元素
    //输入10个元素，分别为1—10。
	cout << endl << endl;

	cout << "测试Locate(10):" << s.Locate(10) << endl << endl;
    cout << "测试getData(5,x)，输出得到的x的值:";
	int x; s.getData(5, x); cout << x << endl << endl;

    cout << "测试Search(x)，输出x=5元素的表项序号：" << s.Search(x) << endl << endl;
    cout << "测试Size(),Length()：" << s.Size() << " " << s.Length() << endl << endl;
    cout << "测试IsFull(),IsEmpty():" << s.IsFull() << " " << s.IsEmpty() << endl << endl;
    cout << "测试setData(3,y),y=30:";
    int y = 30; s.setData(3, y); s.Output(); cout << endl;

    cout << "测试Insert(3,y)";
    s.Insert(3, y); s.Output();
    cout << "此时调用IsFull():" << s.IsFull() << endl;
    cout << "在表满的情况下Insert(3,y):";
    s.Insert(3, y); cout << endl;

    cout << "测试Remove(3,z):";
    int z; s.Remove(3, z); s.Output();
    cout << "被移除的元素z=" << z << endl;

    system("pause");
    return 0;
}
