#include "Binarytree.h"
template<typename T>
void Binarytree<T>::preCreate(BinTreeNode<T>*& subTree) {
	T value;
	cin >> value;
	if (value==RefValue)
		subTree = NULL;
	else {
		subTree = new BinTreeNode<T>(value);
		preCreate(subTree->leftChild);
		preCreate(subTree->rightChild);
		cout << endl;
	}
}

template<typename T>
void Binarytree<T>::preOut(BinTreeNode<T>* subTree) {
	if (subTree != NULL) {
		cout << subTree->data << " ";
		preOut(subTree->leftChild);
		preOut(subTree->rightChild);
	}
}

template<typename T>
void Binarytree<T>::inOut(BinTreeNode<T>* subTree) {
	if (subTree != NULL) {
		inOut(subTree->leftChild);
		cout << subTree->data << " ";
		inOut(subTree->rightChild);
	}
}

template<typename T>
void Binarytree<T>::postOut(BinTreeNode<T>* subTree) {
	if (subTree != NULL) {
		postOut(subTree->leftChild);
		postOut(subTree->rightChild);
		cout << subTree->data << " ";
	}
}

template<typename T>
int Binarytree<T>::NodeNum(BinTreeNode<T>* subTree) {
	if (subTree != NULL)
		return 1 + NodeNum(subTree->leftChild) + NodeNum(subTree->rightChild);
	else
		return 0;
}

template<typename T>
int Binarytree<T>::LeafNodeNum(BinTreeNode<T>*& subTree) {
	if (subTree == NULL)
		return 0;
	else {
		if (subTree->leftChild == NULL && subTree->rightChild == NULL)
			return 1;
		else
			return LeafNodeNum(subTree->leftChild) + LeafNodeNum(subTree->rightChild);
	}
}

template<typename T>
void Binarytree<T>::Fun(T data,int& count, int& height, BinTreeNode<T>* subTree) {
	if (subTree != NULL) {
		if (subTree->data == data)
			count++;
		
		int L_height=0, R_height=0;
		Fun(data, count, L_height, subTree->leftChild);
		Fun(data, count, R_height, subTree->rightChild);
		if (L_height > R_height)
			height = L_height + 1;
		else
			height = R_height + 1;
	}
}

template<typename T>
BinTreeNode<T>* Binarytree<T>::findData(BinTreeNode<T>* subTree,T data) {
	if (subTree == NULL)
		return NULL;
	else {
		if (subTree->data == data)
			return subTree;
		BinTreeNode<T>* a = findData(subTree->leftChild, data);
		BinTreeNode<T>* b = findData(subTree->rightChild, data);
		if (a != NULL)
			return a;
		else
			return b;
	}
}

template<typename T>
BinTreeNode<T>* Binarytree<T>::findParents(BinTreeNode<T>* subTree, BinTreeNode<T>* target) {
	if (subTree == NULL)
		return NULL;
	else
	{
		if (subTree->leftChild == target || subTree->rightChild == target)
			return subTree;
		BinTreeNode<T>* p1 = findParents(subTree->leftChild, target);
		BinTreeNode<T>* p2 = findParents(subTree->rightChild, target);
		if (p1 != NULL)
			return p1;
		else
			return p2;
	}
}

template<typename T>
void Binarytree<T>::levelOrder(BinTreeNode<T>* subTree) {
	if (subTree == NULL)return;
	queue<BinTreeNode<T>*> Q;
	Q.push(root);
	while (!Q.empty()) {
		subTree = Q.front();
		Q.pop();
		if (subTree->leftChild != NULL)
			Q.push(subTree->leftChild);
		if (subTree->rightChild != NULL)
			Q.push(subTree->rightChild);
		cout << subTree->data << " ";
	}
}