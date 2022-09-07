#pragma once
template<typename T>
class SeqList
{
private:
	T* data;
	int maxSize;
	int last;
public:
	//���캯����������
	SeqList(int size = 10);
	~SeqList();
	//�����Ͳ���
	int Locate(int i)const;	//���ص�i������ı������
	bool getData(int i, T& x)const;//�õ���i�������ֵ��ͨ��x����
	int Search(T& x)const;//����x�ڱ��е�λ��
	int Size()const;//����˳�����������
	int Length()const;//���㵱ǰ˳���ĳ���
	bool IsFull();
	bool IsEmpty();

	//�ӹ��Ͳ���
	bool setData(int i, T& x);//�����е�i��Ԫ��ֵ����Ϊx
	bool Insert(int i, T& x);//�ڱ��е�i��Ԫ�غ����x
	bool Remove(int i, T& x);//�Ƴ���i��Ԫ�أ�ͨ��x����
	void Input();
	void Output();
};

