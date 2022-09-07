#pragma once
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
struct BinTreeNode {
	T data;
	BinTreeNode<T>* leftChild;
	BinTreeNode<T>* rightChild;
	BinTreeNode() { leftChild = NULL; rightChild = NULL; }
	BinTreeNode(T x, BinTreeNode<T>* l=NULL, BinTreeNode* r=NULL) {
		data = x;
		leftChild = l;
		rightChild = r;
	}
};

template<typename T>
class Binarytree
{
private:
	BinTreeNode<T>* root;
	T RefValue;
	void preCreate(BinTreeNode<T>*& subTree);	//ǰ�򴴽�������
	void preOut(BinTreeNode<T>* subTree);		//�������
	void inOut(BinTreeNode<T>* subTree);		//�������
	void postOut(BinTreeNode<T>* subTree);		//�������
	int NodeNum(BinTreeNode<T>* subTree);		//��ڵ���
	int LeafNodeNum(BinTreeNode<T>*& subTree);	//��Ҷ�ڵ���
	void Fun(T data, int& count, int& height, BinTreeNode<T>* subTree);//QQ��ҵ�����⣬���ֵΪdata�Ľڵ���Ŀ����������ĸ߶�
	BinTreeNode<T>* findData(BinTreeNode<T>* subTree, T data);//��ֵΪdata�Ľ�㣨��һ�γ��֣�
	BinTreeNode<T>* findParents(BinTreeNode<T>* subTree, BinTreeNode<T>* target);//����ض����ĸ��ڵ�
	void levelOrder(BinTreeNode<T>* subTree);	//��α���
public:
	Binarytree(T value) :RefValue(value), root(NULL) {}
	
	//ǰ�򴴽�������
	void preCreate() { preCreate(root); }
	//ǰ�����
	void preOut() { preOut(root); }
	//�������
	void inOut() { inOut(root); }
	//�������
	void postOut() { postOut(root); }
	//��ڵ���
	int NodeNum() { return NodeNum(root); }
	//��Ҷ�ڵ���
	int LeafNodeNum() { return LeafNodeNum(root); }
	//������ֵΪdata�Ľڵ�������������ĸ߶�
	void Fun(T data,int& count, int& height) { Fun(data,count ,height, root); }
	//��ֵΪdata�Ľ�㣨��һ�γ��֣�
	BinTreeNode<T>* findData(T data) { return findData(root, data); }
	//����ض����ĸ��ڵ�
	BinTreeNode<T>* findParents(BinTreeNode<T>* target) { return findParents(root, target); }
	//��α���
	void levelOrder() { levelOrder(root); }
};