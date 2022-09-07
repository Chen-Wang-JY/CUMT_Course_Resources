#pragma once
#include "SeqList.h"
#include<iostream>
using namespace std;

template<typename T>
SeqList<T>::SeqList(int size) {
	data = new T[size];
	maxSize = size;
	last = -1;
}
template<typename T>
SeqList<T>::~SeqList() {
	delete[] data;
}

template<typename T>
void SeqList<T>::Input() {
	while (1) {
		cout << "请输入插入元素的数量：";
		int n; cin >> n;
		if (last + n + 1 > 0 && last + n + 1 <= maxSize) {
			for (int i = last + 1; i < last + n+1; i++) {
				cout << "请输入第" << i + 1 << "个元素的值：";
				cin >> data[i];
			}
			last = last + n;
			break;
		}
		else
			cout << "元素数目有误，请重新输入。" << endl;
	}
}

template<typename T>
void SeqList<T>::Output() {
	for (int i = 0; i <= last; i++)
		cout << data[i] << " ";
	cout << endl;
}

template<typename T>
int SeqList<T>::Locate(int i)const {
	if (i > 0 && i <= last + 1) return i;
	else return 0;	//i的值输入有误，返回0
}

template<typename T>
bool SeqList<T>::getData(int i, T& x)const {
	if (i > 0 && i <= last + 1) { x = data[i - 1]; return true; }
	else return false;
}

template<typename T>
int SeqList<T>::Search(T& x)const {
	for (int i = 0; i <= last; i++)
		if (data[i] == x)
			return i + 1;
	return 0;//未找到返回0
}

template<typename T>
int SeqList<T>::Size()const { return maxSize; }

template<typename T>
int SeqList<T>::Length()const { return last + 1; }

template<typename T>
bool SeqList<T>::IsFull() {
	if (last + 1 == maxSize) return true;
	else return false;
}

template<typename T>
bool SeqList<T>::IsEmpty() {
	if (last == -1) return true;
	else return false;
}

template<typename T>
bool SeqList<T>::setData(int i, T& x) {
	if (i >= 1 && i <= last + 1) {
		data[i - 1] = x;
		return true;
	}
	else {
		cout << "设置失败！" << endl;
		return false;
	}
}

template<typename T>
bool SeqList<T>::Insert(int i, T& x) {
	if (this->IsFull()) {
		cout << "插入失败，顺序表容量不足。" << endl;
		return false;
	}
	if (i<0 || i>last + 1) {
		cout << "插入失败，插入位置非法。" << endl;
		return false;
	}
	else {
		T r = data[i];
		T rr = data[i + 1];
		data[i] = x;
		last++;
		for (int j = i; j <= last; j++) {
			rr = data[j + 1];
			data[j + 1] = r;
			r = rr;
		}
		return true;
	}
}

template<typename T>
bool SeqList<T>::Remove(int i,T& x) {
	if (this->IsEmpty()) {
		cout << "移除失败，此表是空表。" << endl;
		return false;
	}
	if (i<1 || i>last + 1) {
		cout << "移除失败，表项序号非法" << endl;
		return false;
	}
	else
	{
		x = data[i - 1];
		last--;
		for (int j = i - 1; j <= last; j++) {
			data[j] = data[j + 1];
		}
		return true;
	}
}