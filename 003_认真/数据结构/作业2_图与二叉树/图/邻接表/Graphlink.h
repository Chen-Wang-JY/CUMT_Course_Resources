#pragma once
#include<iostream>
using namespace std;
//边结点
template<typename T,typename E>
struct Edge{
	int dest;
	E cost;
	Edge<T, E>* link;
	Edge<T, E>(int dest, E cost, Edge<T, E>* link = NULL) : dest(dest), cost(cost), link(link) {}
};
//顶点结点
template<typename T,typename E>
struct Vertex{
	T data;
	Edge<T, E>* adj;
};

template<typename T,typename E>
class Graphlink
{
private:
	Vertex<T, E>* Vertices;//顶点表
	int numVertices;//当前节点数
	int numEdges;	//当前边数

	void DFS(int v, bool* visited);//由公有的DFS函数调用的深度优先搜索算法
public:
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v0, int v);
	void DFS(int v);//深度优先搜索的接口函数
};

