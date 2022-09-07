#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct LinkNode {
	T data;
	LinkNode<T>* link;
	LinkNode<T>() {};
	LinkNode<T>(T data,LinkNode<T>* link=NULL) {
		this->data = data;
		this->link = link;
	}
};

template<typename T>
class List
{
private:
	LinkNode<T>* first;
public:
	bool getData(int i, T& x)const;
	LinkNode<T>* Locate(int i)const;
	LinkNode<T>* Search(T& x)const;
	int Length()const;
	bool IsEmpty()const;
	LinkNode<T>* getHead()const;

	bool setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);

	List();
	~List();
	void inPut();
	void outPut();


};

