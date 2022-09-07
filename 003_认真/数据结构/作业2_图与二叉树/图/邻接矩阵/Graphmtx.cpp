#include "Graphmtx.h"

template<typename T, typename E>
Graphmtx<T, E>::Graphmtx(int size) {
	maxVertices = size;
	numVertices = 0;
	numEdges = 0;
	Vertice = new T[maxVertices];
	Edge = new E * [maxVertices];
	for (int i = 0; i < maxVertices; i++)
		Edge[i] = new E[maxVertices];
	//邻接矩阵初始化
	for (int i = 0; i < maxVertices; i++)
		for (int j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? 0 : MAXWEIGHT;
}

template<typename T, typename E>
int Graphmtx<T, E>::getVertexNum(const T& v) {
	for (int i = 0; i < numVertices; i++)
		if (Vertice[i] == v)
			return i;
	//未找到返回-1
	return -1;
}

template<typename T, typename E>
bool Graphmtx<T, E>::insertVertex(const T& v) {
	if (numVertices == maxVertices) {
		cout << "顶点表满，无法插入!" << endl;
		return false;
	}
	Vertice[numVertices++] = v;
	return true;
}

template<typename T, typename E>
bool Graphmtx<T, E>::insertEdge(const T& v1, const T& v2, const E& w) {
	int V1 = getVertexNum(v1);
	int V2 = getVertexNum(v2);
	//当v1v2都在顶点表中，且两点间无边存在时可以插入边
	if (V1 != -1 && V2 != -1 && Edge[V1][V2] == MAXWEIGHT) {
		Edge[V1][V2] = Edge[V2][V1] = w;
		numEdges++;
		return true;
	}
	else
	{
		cout << "插入边失败！" << endl;
		return false;
	}
}

template<typename T,typename E>
void Graphmtx<T, E>::CreateGraph() {
	int n, m;
	cout << "请输入图中包含的顶点数量："; cin >> n;
	while (n < 0) {
		cout << "输入非法，请重新输入顶点数量：";
		cin >> n;
	}
	cout << "请输入图中包含的边的数量："; cin >> m;
	while (m < 0) {
		cout << "输入非法，请重新输入边的数量：";
		cin >> m;
	}
	//建立顶点表
	for (int i = 0; i < n; i++)
	{
		T v;
		cout << "请输入第" << i + 1 << "个顶点：";
		cin >> v;
		this->insertVertex(v);
	}
	cout << "顶点表创建完毕，开始插入" << m << "条边" << endl;
	//建立邻接矩阵
	int i = 0;
	while (i < m) {
		T v1, v2; E w;
		cout << "请输入第" << i + 1 << "条边的两端点与权值：";
		cin >> v1 >> v2 >> w;
		int V1 = this->getVertexNum(v1);
		int V2 = this->getVertexNum(v2);
		if (V1 == -1 || V2 == -1)
		{
			cout << "定点信息输入有误，重新输入。";
			continue;
		}
		else if (this->insertEdge(v1, v2, w))
			i++;
	}

}

template<typename T,typename E>
void Graphmtx<T, E>::PrintGraph() {
	cout << "当前图中的顶点数量：" << this->numVertices << endl;
	cout << "当前图中的边的数量：" << this->numEdges << endl;
	cout << "顶点表：" << endl;
	for (int i = 0; i < this->numVertices; i++)
		cout << this->Vertice[i] << " ";
	cout << endl;
	cout << "邻接矩阵：" << endl;
	for (int i = 0; i < this->numVertices; i++) {
		for (int j = 0; j < this->numVertices; j++)
			cout << this->Edge[i][j] << " ";
		cout << endl;
	}
}

template<typename T, typename E>
int Graphmtx<T, E>::getFirstNeighbor(int v) {
	if (v == -1)
		return -1;
	for (int i = 0; i < numVertices; i++)
		if (Edge[v][i] != 0 && Edge[v][i] < MAXWEIGHT)
			return i;
}

template<typename T, typename E>
int Graphmtx<T, E>::getNextNeighbor(int v0, int v) {
	if (v0 != -1 && v != -1)
		for (int i = v + 1; i < numVertices; i++)
			if (Edge[v0][i] != -1 && Edge[v0][i] < MAXWEIGHT)
				return i;
	return -1;
}

template<typename T, typename E>
void Graphmtx<T, E>::DepthFirstSearch(T v) {
	bool* visited = new bool[this->numVertices];
	for (int i = 0; i < numVertices; i++)
		visited[i] = false;
	int vn = getVertexNum(v);
	if (vn != -1)
		DFS(vn, visited);
	delete visited;
}

template<typename T,typename E>
void Graphmtx<T, E>::DFS(int v, bool visited[])
{
	//访问当前顶点
	cout << Vertice[v] << " ";
	visited[v] = true;
	//得到当前顶点的第一个邻接顶点
	int vf = getFirstNeighbor(v);
	while (vf != -1) {
		//若当前结点未被访问，则深度优先搜索此结点
		if (!visited[vf]) 
			DFS(vf, visited);
		vf = getNextNeighbor(v, vf);
	}
}


//}
//template<typename T, typename E>
//istream& operator>>(istream& in, Graphmtx<T, E>& G) {
//	int n, m;
//	cout << "请输入图中包含的顶点数量："; cin >> n;
//	while (n < 0) {
//		cout << "输入非法，请重新输入顶点数量：";
//		in >> n;
//	}
//	cout << "请输入图中包含的边的数量："; cin >> m;
//	while (m < 0) {
//		cout << "输入非法，请重新输入边的数量：";
//		in >> m;
//	}
//	//建立顶点表
//	for (int i = 0; i < n; i++)
//	{
//		T v;
//		cout << "请输入第" << i + 1 << "个顶点：";
//		in >> v;
//		G.insertVertex(v);
//	}
//	cout << "顶点表创建完毕，开始插入" << m << "条边" << endl;
//	//建立邻接矩阵
//	int i = 0;
//	while (i < m) {
//		T v1, v2; E w;
//		cout << "请输入第" << i + 1 << "条边的两端点与权值：";
//		in >> v1 >> v2 >> w;
//		int V1 = G.getVertexNum(v1);
//		int V2 = G.getVertexNum(v2);
//		if (V1 == -1 || V2 == -1)
//		{
//			cout << "定点信息输入有误，重新输入。";
//			continue;
//		}
//		else
//		{
//			G.insertEdge(v1, v2, w);
//			i++;
//		}
//	}
//	return in;
//}/*
	/*
template<typename T, typename E>
ostream& operator<<(ostream& out, Graphmtx<T, E>& G) {
	out << "顶点表：";
	for (int i = 0; i < G.numVertices; i++)
		out << G.Vertice[i] << " ";
	out << endl;
	cout << "邻接矩阵：";
	for (int i = 0; i < G.numEdges; i++) {
		for (int j = 0; j < G.numEdges; j++)
			cout << G.Edge[i][j] << " ";
		out << endl;
	}
	cout << endl;
	return out;
}*/