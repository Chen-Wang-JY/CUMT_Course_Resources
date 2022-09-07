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
		cout << "���������Ԫ�ص�������";
		int n; cin >> n;
		if (last + n + 1 > 0 && last + n + 1 <= maxSize) {
			for (int i = last + 1; i < last + n+1; i++) {
				cout << "�������" << i + 1 << "��Ԫ�ص�ֵ��";
				cin >> data[i];
			}
			last = last + n;
			break;
		}
		else
			cout << "Ԫ����Ŀ�������������롣" << endl;
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
	else return 0;	//i��ֵ�������󣬷���0
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
	return 0;//δ�ҵ�����0
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
		cout << "����ʧ�ܣ�" << endl;
		return false;
	}
}

template<typename T>
bool SeqList<T>::Insert(int i, T& x) {
	if (this->IsFull()) {
		cout << "����ʧ�ܣ�˳����������㡣" << endl;
		return false;
	}
	if (i<0 || i>last + 1) {
		cout << "����ʧ�ܣ�����λ�÷Ƿ���" << endl;
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
		cout << "�Ƴ�ʧ�ܣ��˱��ǿձ�" << endl;
		return false;
	}
	if (i<1 || i>last + 1) {
		cout << "�Ƴ�ʧ�ܣ�������ŷǷ�" << endl;
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