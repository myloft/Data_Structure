#ifndef __GRAPHAM_H__
#define __GRAPHAM_H__
#include "utility.h"
#include "kruskal.h"					// Kruskal算法
#include "veram.h"
#include <queue>

#define INFINITE (1000000)
//int infity = INFINITE;

template<class T>
class GraphAM {
protected:
    int size = 0;                   // 最大顶点数
    int verNum = 0, edgeNum = 0; // 当前的顶点数和边数
    int kind;   // 0无向图，1有向图，2无向网，3有向网
    VerAM<T> *vertex; // 顶点元素表
    int **edge;
    bool *visited; // 标记是否被访问

    int LocateVex(T e);   // 定位顶点，返回顶点的序号
    int FirstAdjVex(T e); // 返回指定顶点的第一个邻接顶点
    int FirstAdjVex(int pos, int s);

    int NextAdjVex(int v, int pos);

    bool EdgeExist(T s, T e);

    bool SetWeight(T s, T e, int w);

    void DFSHelp(int start);

    void BFSHelp(int start);

public:
    GraphAM() = default;

    ~GraphAM() { DestroyGraph(); }

    void InitGraph(int kind, int n);

    void Clear();

    void DestroyGraph();

    void CreateGraph();

    int GetKind() { return kind; }

    int InsertVex(T e);

	void kruskal();

    bool InsertEdge(T s, T e);

    bool InsertEdge(T s, T e, int w);

    bool DeleteEdge(T s, T e);

    bool DeleteVex(T e);

    bool SetElem(T e, T x); // 设置顶点的元素值
    
	bool DFS(T e);

    bool BFS(T e);
};

template<class T>
void GraphAM<T>::InitGraph(int k, int n) {
    size = n;
    kind = k;
    verNum = edgeNum = 0;

    vertex = new VerAM<T>[size];

    for (int i = 0; i < size; i++)
        vertex[i].flag = false;

    edge = new int *[size];

    for (int i = 0; i < n; i++) {
        edge[i] = new int[size];
        for (int j = 0; j < size; j++)
            if (kind < 2)
                edge[i][j] = 0;
            else
                edge[i][j] = INFINITE;
    }
	visited = new bool[size];
}

template<class T>
void GraphAM<T>::Clear() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (kind < 2)
                edge[i][j] = 0;
            else
                edge[i][j] = INFINITE;
    edgeNum = 0;
    for (int i = 0; i < size; i++)
        vertex[i].flag = false;

    verNum = 0;
}

template<class T>
void GraphAM<T>::DestroyGraph() {
    delete[] vertex;
    for (int j = 0; j < size; j++)
        delete[] edge[j];
    delete[] edge;
    delete[] visited;
}

template<class T>
void GraphAM<T>::CreateGraph() {
    int v1, v2, n = 0;
    char answer;
    if (verNum > 0)
        Clear();
    std::cout << "请输入图的顶点数：";
    while (true) {
        std::cin >> verNum;
        if (verNum > size)
            std::cout << "顶点个数溢出，请重新输入：" << std::endl;
        else
            break;
    }
    std::cout << "请输入各个顶点的值：";
    for (int i = 0; i < verNum; i++) {
        std::cin >> vertex[i].elem;
        vertex[i].flag = true;
    }
    while (true) {
        std::cout << "请输入一条边的两端顶点的下标：";
        std::cin >> v1 >> v2;
		int i = LocateVex(v1);
		int j = LocateVex(v2);
        if (kind < 2) {
            edge[i][j] = 1;
            if (kind == 0)
                edge[j][i] = 1;
        } else {
            std::cout << "请输入该边的权值：";
            std::cin >> edge[i][j];
			if (kind == 2)
                edge[j][i] = edge[i][j];
        }
        n++;
        std::cout << "继续构造边吗？（Y/N）";
        std::cin >> answer;
        if (answer == 'n' || answer == 'N')
            break;
    }
    edgeNum = n;
}

template<class T>
int GraphAM<T>::LocateVex(T e) {
    for (int i = 0; i < size; i++)
        if (vertex[i].flag && vertex[i].elem == e)
            return i;
    return -1;
}

template<class T>
int GraphAM<T>::InsertVex(T e) {
    if (verNum + 1 > size)
        return -1;
    int i;
    for (i = 0; i < size; i++)
        if (vertex[i].flag == false) {
            vertex[i].elem = e;
            vertex[i].flag = true;
            break;
        }
    verNum++;
    return i;
}

template<class T>
bool GraphAM<T>::InsertEdge(T s, T e) {
    int i = LocateVex(s);
    int j = LocateVex(e);
    if (i < 0 || j < 0)
        return false;
    if (edge[i][j] != 0)
        return false;
    edge[i][j] = 1;
    if (kind == 0)
        edge[j][i] = 1;
    edgeNum++;
    return true;
}

template<class T>
bool GraphAM<T>::InsertEdge(T s, T e, int w) {
    int i = LocateVex(s);
    int j = LocateVex(e);
    if (i < 0 || j < 0)
        return false;
    if (edge[i][j] != INFINITE)
        return false;
    edge[i][j] = w;
    if (kind == 2)
        edge[j][j] = w;
    edgeNum++;
    return true;
}

template<class T>
bool GraphAM<T>::DeleteEdge(T s, T e) {
    int i = LocateVex(s);
    int j = LocateVex(e);
    if (i < 0 || j < 0)
        return false;
    if (kind < 2) {
        edge[i][j] = 0;
        if (kind == 0)
            edge[j][i] = 0;
    } else {
        edge[i][j] = INFINITE;
        if (kind == 2)
            edge[j][i] = INFINITE;
    }
    edgeNum--;
    return true;
}

template<class T>
bool GraphAM<T>::DeleteVex(T e) {
    int pos = LocateVex(e);
    if (pos < 0)
        return false;
    vertex[pos].flag = false;
    verNum--;
    if (kind < 2) {
        for (int j = 0; j < size; j++)
            if (edge[pos][j] == 1) {
                edge[pos][j] = 0;
                if (kind == 0)
                    edge[j][pos] = 0;
                edgeNum--;
            }
    } else {
        for (int j = 0; j < size; j++)
            if (edge[pos][j] != INFINITE) {
                edge[pos][j] = INFINITE;
                if (kind == 2)
                    edge[j][pos] = INFINITE;
                edgeNum--;
            }
    }
    return true;
}

template<class T>
bool GraphAM<T>::SetElem(T e, T x) {
    int pos = LocateVex(e);
    if (pos < 0)
        return false;
    vertex[pos].elem = x;
    return true;
}

template<class T>
int GraphAM<T>::FirstAdjVex(T e) {
    int pos = LocateVex(e);
    if (pos < 0)
        return -1;
    return FirstAdjVex(pos, 0);
}

template<class T>
int GraphAM<T>::FirstAdjVex(int pos, int s) {
    if (pos < 0)
        return -1;
    if (kind < 2) {
        for (int j = s; j < size; j++)
            if (j != pos && edge[pos][j] == 1)
                return j;
    } else {
        for (int j = s; j < size; j++)
            if (j != pos && edge[pos][j] != INFINITE)
                return j;
    }
    return -1;
}

template<class T>
int GraphAM<T>::NextAdjVex(int v, int pos) {
    return FirstAdjVex(v, pos + 1);
}

template<class T>
bool GraphAM<T>::EdgeExist(T s, T e) {
    int i = LocateVex(s);
    int j = LocateVex(e);
    if (i < 0 || j < 0)
        return false;
    if (kind < 2) {
        if (edge[i][j] == 1)
            return true;
        else
            return false;
    } else if (edge[i][j] == INFINITE)
        return false;
    else
        return true;
}

template<class T>
bool GraphAM<T>::SetWeight(T s, T e, int w) {
    int i = LocateVex(s);
    int j = LocateVex(e);
    if (i < 0 || j < 0 || edge[i][j] == INFINITE)
        return false;
    edge[i][j] = w;
    return true;
}

template<class T>
bool GraphAM<T>::DFS(T e) {
    int p = LocateVex(e);
    if (p < 0)
        return false;
    for (int i = 0; i < size; i++)
        visited[i] = false;
    DFSHelp(p);
    return true;
}

template<class T>
void GraphAM<T>::DFSHelp(int start) {
    visited[start] = true;
    std::cout << vertex[start].elem << '\t';
    for (int i = FirstAdjVex(start, 0); i != -1; i = NextAdjVex(start, i))
        if (visited[i] == false)
            DFSHelp(i);
}

template<class T>
bool GraphAM<T>::BFS(T e) {
    int p = LocateVex(e);
    if (p < 0)
        return false;
    for (int i = 0; i < size; i++)
        visited[i] = false;
    BFSHelp(p);
    return true;
}

template<class T>
void GraphAM<T>::BFSHelp(int start) {
    visited[start] = true;
    std::cout << vertex[start].elem << '\t';
    std::queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int w = FirstAdjVex(t, 0); w >= 0; w = NextAdjVex(t, w)) {
            if (visited[w] == false) {
                visited[w] = true;
                std::cout << vertex[w].elem << '\t';
                q.push(w);
            }
        }
    }
}

template<class T>
void GraphAM<T>::kruskal() {
	
	int *vexs = new int[verNum];
	for (int i = 0; i < verNum; i++) {
		vexs[i] = vertex[i].elem;
	}
	int **m = new int*[verNum];
	for (int i = 0; i<verNum; i++)
	{
		m[i] = new int[verNum];
	}

	for (int u = 0; u < verNum; u++)
	{	
		for (int v = 0; v < verNum; v++)
		{	
			m[u][v] = edge[u][v];
			cout << setw(4) << m[u][v] <<setw(4) << " ";
		}
		cout << endl;
	}

	AdjListUndirNetwork<int, int> net(vexs, verNum);
	for (int u = 0; u < verNum; u++)
	{	// 生成邻接矩阵的行
		for (int v = 0; v < verNum; v++)
		{	// 生成邻接矩阵元素的值
			if (m[u][v] != INFINITE) net.InsertEdge(u, v, m[u][v]);
		}
	}

	cout << "原网:";
	Display(net);					// 显示网net
	cout << endl;
	cout << "Kruskal算法产生最小生成树的边:" << endl;
	MiniSpanTreeKruskal(net);		// Kruskal算法
	cout << endl;
}
#endif