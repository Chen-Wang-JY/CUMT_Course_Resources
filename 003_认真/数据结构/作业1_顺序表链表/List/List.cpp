#pragma once
#include "List.h"
#include<iostream>
using namespace std;

template<typename T>
List<T>::List() {
	first = new LinkNode<T>(-1, NULL);
}

template<typename T>
List<T>::~List() {
	LinkNode<T>* p = first;
	LinkNode<T>* del;
	while (p != NULL) {
		del = p;
		p = p->link;
		delete del;
	}
}

template<typename T>
void List<T>::inPut() {
	while (true) {
		cout << "请输入要插入的元素个数:";
		int n;
		cin >> n;
		if (n < 1)
			cout << "非法数值，请重新输入！" << endl;
		else
		{
			LinkNode<T>* newnode, * last=first;
			T x;
			for (int i = 0; i < n; i++) {
				cout << "请输入第" << i + 1 << "个元素的值:";
				cin >> x;
				newnode = new LinkNode<T>(x);
				last->link = newnode;
				last = newnode;
			}
			break;
		}
	}

}

template<typename T>
void List<T>::outPut() {
	LinkNode<T>* p = first;
	while (p->link != NULL) {
		cout << p->link->data << " ";
		p = p->link;
	}
	cout << endl;
}

template<typename T>
bool List<T>::IsEmpty()const {
	if (first->link == NULL)
		return true;
	else
		return false;
}

template<typename T>
int List<T>::Length()const {
	int len = 0;
	LinkNode<T>* p = first->link;
	while (p != NULL) {
		len++;
		p = p->link;
	}
	return len;
}

template<typename T>
LinkNode<T>* List<T>::Locate(int i)const {
	if (this->IsEmpty()) {
		cout << "无法定位，链表为空表。" << endl;
		return NULL;
	}
	else if (i<0 || i>this->Length()) {
		cout << "输入非法。" << endl;
		return NULL;
	}
	else
	{
		LinkNode<T>* p = first;
		for (int j = 0; j < i; j++) {
			p = p->link;
		}
		return p;
	}
}

template<typename T>
bool List<T>::getData(int i, T& x)const {
	if (this->IsEmpty()) {
		cout << "链表为空。" << endl;
		return false;
	}
	else if (i<1 || i>this->Length()) {
		cout << "输入非法。" << endl;
		return false;
	}
	else {
		x=this->Locate(i)->data;
		return true;
	}
}

template<typename T>
LinkNode<T>* List<T>::Search(T& x)const {
	LinkNode<T>* p = first->link;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	return NULL;
}

template<typename T>
LinkNode<T>* List<T>::getHead()const {
	return first;
}

template<typename T>
bool List<T>::setData(int i, T& x) {
	if (this->Locate(i)) {
		Locate(i)->data = x;
		return true;
	}
	else{
		cout << "输入非法。" << endl;
		return false;
	}
}

template<typename T>
bool List<T>::Insert(int i, T& x) {
	if (!this->Locate(i)) {
		cout << "输入非法。" << endl;
		return false;
	}
	else {
		LinkNode<T>* inode = this->Locate(i);
		LinkNode<T>* newnode = new LinkNode<T>(x, inode->link);
		inode->link = newnode;
		return true;
	}
}

template<typename T>
bool List<T>::Remove(int i, T& x) {
	if (!this->Locate(i)) {
		cout << "输入非法。" << endl;
		return false;
	}
	else {
		LinkNode<T>* inode = this->Locate(i);
		this->Locate(i - 1)->link = inode->link;
		x = inode->data;
		delete inode;
		return true;
	}
}