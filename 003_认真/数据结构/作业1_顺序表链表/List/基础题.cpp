#pragma once
#include <iostream>
#include"List.cpp"
using namespace std;

int main()
{
    List<int> list;

    cout << "测试IsEmpty():" << list.IsEmpty() << endl << endl;
    list.inPut();   //为链表赋值，测试中采用5， 1 2 3 4 5 赋值
	cout << endl << "测试outPut():"; list.outPut();
	cout << "赋值后，再次测试IsEmpty():" << list.IsEmpty() << endl << endl;
    cout << "测试Length():" << list.Length() << endl << endl;
    
    cout << "测试getHead()：";
    LinkNode<int>* first = list.getHead();
    cout << "前两个结点的data分别是：" << first->link->data << " " << first->link->link->data << endl << endl;
    
    cout << "测试Locate(3),第三四个元素的data分别是：";
    LinkNode<int>* p = list.Locate(3);
    cout << p->data << " " << p->link->data << endl << endl;

    cout << "测试setData(3,x),x=33:";
    int x = 33; list.setData(3, x); list.outPut(); 
    cout << endl;

    cout << "测试Insert(4,x):"; list.Insert(4, x); list.outPut(); 
    cout << endl;

    cout << "测试Remove(5,x)"; list.Remove(5, x); list.outPut();
    cout << "被移除的元素x:" << x << endl;


   

    system("pause");
    return 0;
}
