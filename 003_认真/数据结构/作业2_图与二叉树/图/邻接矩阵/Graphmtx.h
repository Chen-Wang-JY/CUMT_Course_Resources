#pragma once
#include<iostream>
using namespace std;
const double MAXWEIGHT=100;	//权值的无穷大量
const double MINWEIGHT=0;	//无权值的图，权值的默认值
template<typename T,typename E>
class Graphmtx
{
private:
	T* Vertice;	//顶点表
	E** Edge;	//邻接矩阵
	int maxVertices;	//最大顶点数
	int numVertices;	//当前顶点数
	int numEdges;		//当前边数

	void DFS(int v,bool visited[]);	//深度优先搜索
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v0, int v);
public:
	Graphmtx(int size = 20);
	bool insertVertex(const T& v);//插入顶点
	bool insertEdge(const T& v1, const T& v2, const E& w=MINWEIGHT);//插入边
	int getVertexNum(const T& v);//得到顶点在顶点表中的序号
	void CreateGraph();
	void PrintGraph();
	
	void DepthFirstSearch(T v);
	//friend istream& operator>>(istream& in, Graphmtx<T, E>& G);//创建图
	//friend ostream& operator<<(ostream& out, Graphmtx<T, E>& G);//简单输出邻接矩阵和顶点表
};
