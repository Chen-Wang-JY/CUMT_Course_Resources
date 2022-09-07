/*
 * @Author: Chen
 * @Date: 2021-09-24 10:08:45
 * @LastEditTime: 2022-04-04 14:10:35
 * @FilePath: \邻接表\Graphlink.cpp
 */
#include "Graphlink.h"

template<typename T,typename E>
int Graphlink<T, E>::getFirstNeighbor(int v) {
	if (v != -1 && Vertices->adj != NULL)
		return Vertices->adj->dest;
	else
		return -1;
}

template<typename T,typename E>
int Graphlink<T, E>::getNextNeighbor(int v0, int v) {
	if (v0 != -1 && v != -1) {
		Edge<T, E>* p = Vertices[v0]->adj;
		while (p != NULL && p->dest != v)
			p = p->link;
		if (p != NULL && p->link != NULL)
			return p->link->dest;
		else
			return -1;
	}
	return -1;
}

template<typename T, typename E>
void Graphlink<T, E>::DFS(int v) {
	bool* visited = new bool[numVertices];
	for (int i = 0; i < numVertices; i++)
		visited[i] = false;
	if (v != -1)
		DFS(v, visited);
	delete[] visited;
}

template<typename T, typename E>
void Graphlink<T, E>::DFS(int v, bool* visited) {
	//访问结点v
	cout << Vertices[v]->dest << " ";
	visited[v] = true;
	//得到下一个关联结点的序号
	int vn = getFirstNeighbor(v);
	while (vn != -1)
	{
		DFS(vn, visited);
		vn = Vertices[vn]->link->dest;
	}
}