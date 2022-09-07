#include <iostream>
#include "Graphmtx.cpp"

int main()
{
    Graphmtx<char,float> G;
    G.CreateGraph();
    G.PrintGraph();;
    cout << "深度优先搜索序列："; G.DepthFirstSearch('A');
    return 0;
}

