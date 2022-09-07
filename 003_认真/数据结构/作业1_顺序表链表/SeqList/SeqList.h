#pragma once
template<typename T>
class SeqList
{
private:
	T* data;
	int maxSize;
	int last;
public:
	//构造函数析构函数
	SeqList(int size = 10);
	~SeqList();
	//引用型操作
	int Locate(int i)const;	//返回第i个表项的表项序号
	bool getData(int i, T& x)const;//得到第i个表项的值，通过x返回
	int Search(T& x)const;//搜索x在表中的位置
	int Size()const;//计算顺序表的最大容量
	int Length()const;//计算当前顺序表的长度
	bool IsFull();
	bool IsEmpty();

	//加工型操作
	bool setData(int i, T& x);//将表中第i个元素值设置为x
	bool Insert(int i, T& x);//在表中第i个元素后插入x
	bool Remove(int i, T& x);//移除第i个元素，通过x返回
	void Input();
	void Output();
};

