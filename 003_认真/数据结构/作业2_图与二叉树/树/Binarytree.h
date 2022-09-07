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
	void preCreate(BinTreeNode<T>*& subTree);	//前序创建二叉树
	void preOut(BinTreeNode<T>* subTree);		//先序输出
	void inOut(BinTreeNode<T>* subTree);		//中序输出
	void postOut(BinTreeNode<T>* subTree);		//后序输出
	int NodeNum(BinTreeNode<T>* subTree);		//求节点数
	int LeafNodeNum(BinTreeNode<T>*& subTree);	//求叶节点数
	void Fun(T data, int& count, int& height, BinTreeNode<T>* subTree);//QQ作业第三题，求出值为data的节点数目，并求出树的高度
	BinTreeNode<T>* findData(BinTreeNode<T>* subTree, T data);//求值为data的结点（第一次出现）
	BinTreeNode<T>* findParents(BinTreeNode<T>* subTree, BinTreeNode<T>* target);//求出特定结点的父节点
	void levelOrder(BinTreeNode<T>* subTree);	//层次遍历
public:
	Binarytree(T value) :RefValue(value), root(NULL) {}
	
	//前序创建二叉树
	void preCreate() { preCreate(root); }
	//前序输出
	void preOut() { preOut(root); }
	//中序输出
	void inOut() { inOut(root); }
	//后续输出
	void postOut() { postOut(root); }
	//求节点数
	int NodeNum() { return NodeNum(root); }
	//求叶节点数
	int LeafNodeNum() { return LeafNodeNum(root); }
	//求所有值为data的节点数，并求出树的高度
	void Fun(T data,int& count, int& height) { Fun(data,count ,height, root); }
	//求值为data的结点（第一次出现）
	BinTreeNode<T>* findData(T data) { return findData(root, data); }
	//求出特定结点的父节点
	BinTreeNode<T>* findParents(BinTreeNode<T>* target) { return findParents(root, target); }
	//层次遍历
	void levelOrder() { levelOrder(root); }
};