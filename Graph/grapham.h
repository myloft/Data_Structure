#include "lkqueue.h"
#include "veram.h"
#include <iostream>
using namespace std;

template <class ElemType>
class GraphAM {
public:
    int size;
    int verNum;
    int edgeNum;
    int kind;
    VerAM<ElemType> * vertex;
    int ** edge;
    void InitGraph(int k, int n);
    void Clear();
    void DestoryGraph();
    void CreateGraph();
    int LocateVer(ElemType e);
    int InsertVer(ElemType e);
    bool InsertEdge(ElemType s, ElemType e);
    bool InsertEdge(ElemType s, ElemType e, int w);
    void DeleteEdge(ElemType s, ElemType e);
    void DeleteVer(ElemType e);
    int SetElem(ElemType e, ElemType x);
    int FirstAdjVer(ElemType e);
    int PFirstAdjVer(int pos);
    int FirstAdjVer(int pos, int s);
    int NextAdjVer(int v, int pos);
    int EdgeExsit(ElemType s, ElemType e);
    int SetWeight(ElemType s, ElemType e, int w);
    void Display();
    void TraverseDFS(int start);
    int DFS(int s, int tag[]);
    void BFS(int start);
};

template <class ElemType>
void
GraphAM<ElemType>::InitGraph(int k, int n) {
	size=n;
	kind=k;
    verNum = edgeNum = 0;
    vertex = new VerAM<ElemType>[size];
    for (int i = 0; i < size; i++)
        vertex[i].flag = 0;
    edge = new int *[size];
    for (int i = 0; i < n; i++) {
        edge[i] = new int[size];
        for (int j = 0; j < size; j++) {
            if (kind < 2)
                edge[i][j] = 0;
            else
                edge[i][j] = 65535;
        }
    }
}

template <class ElemType>
void
GraphAM<ElemType>::Clear() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (kind < 2)
                edge[i][j] = 0;
            else
                edge[i][j] = 65535;
    edgeNum = 0;
    for (int i = 0; i < size; i++)
        vertex[i].flag = 0;
    verNum = 0;
}

template <class ElemType>
void
GraphAM<ElemType>::CreateGraph() {
    int v1,v2,n = 0;
    char answer;
    if (verNum > 0) Clear();
    cout << "请输入图的顶点个数：";
    cin>>verNum;
    while (1) {
        if (verNum > size){
            cout << "顶点个数溢出！请重新输入：" << endl;
            cin >> verNum;
        }
        else{
            break;
        }
    }
    cout << "请输入各个顶点的值：" << endl;
    for (int i = 0; i < verNum; i++) {
        cin >> vertex[i].elem;
        vertex[i].flag = 1;
    }
    int i = 0;
    int j = 0;
    while (1) {
        cout << "请输入一条边／弧的两端顶点的下标：" << endl;
        cin >> v1 >> v2;
        i=LocateVer(v1);
        j=LocateVer(v2);
        if (kind < 2) {
            edge[i][j] = 1;
            if (kind == 0) edge[j][i] = 1;
        } else {
            cout << "请输入该边/弧的权值：";
            cin >> edge[i][j];
            if (kind == 2) edge[j][i] = edge[i][j];
        }
        n++;
        cout << "继续构造边／弧吗？（Y/ N）";
        cin >> answer;
        if (answer == 'N' || answer == 'n') break;
    }
    edgeNum = n;
}

template <class ElemType>
int
GraphAM<ElemType>::LocateVer(ElemType e) {
    for (int i = 0; i < size; i++)
        if (vertex[i].flag == 1 && vertex[i].elem == e) return i;
    return -1;
}

template <class ElemType>
int
GraphAM<ElemType>::InsertVer(ElemType e) {
    if (verNum + 1 > size) return -1;
    int j;
    for (j = 0; j < size; j++)
        if (vertex[j].flag == 0) {
            vertex[j].elem = e;
            vertex[j].flag = 1;
            break;
        }
    verNum++;
    return j;
}

template <class ElemType>
bool
GraphAM<ElemType>::InsertEdge(ElemType s, ElemType e) {
    int i = LocateVer(s);
    int j = LocateVer(e);
    if (i < 0 || j < 0) return false;
    if (edge[i][j] != 0) return false;
    edge[i][j] = 1;
    if (kind == 0) edge[j][i] = 1;
    edgeNum++;
    return true;
}

template <class ElemType>
bool
GraphAM<ElemType>::InsertEdge(ElemType s, ElemType e, int w) {
    int i = LocateVer(s);
    int j = LocateVer(e);
    if (i < 0 || j < 0) return false;
    if (edge[i][j] != 65535) return false;
    edge[i][j] = w;
    if (kind == 2) edge[j][i] = w;
    edgeNum++;
    return true;
}

template <class ElemType>
void
GraphAM<ElemType>::DeleteEdge(ElemType s, ElemType e) {
    int i = LocateVer(s);
    int j = LocateVer(e);
    if (i < 0 || j < 0) return;
    if (kind < 2) {
        edge[i][j] = 0;
        if (kind == 0) edge[j][i] = 0;
    } else {
        edge[i][j] = 65535;
        if (kind == 2) edge[i][j] = 65535;
    }
    edgeNum--;
}

template <class ElemType>
void
GraphAM<ElemType>::DeleteVer(ElemType e) {
    int pos = LocateVer(e);
    if (pos < 0) return;
    vertex[pos].flag = 0;
    verNum--;
    if (kind < 2) {
        for (int j = 0; j < size; j++)
            if (edge[pos][j] == 1) {
                edge[pos][j] = 0;
                if (kind == 0) edge[j][pos] = 0;
                edgeNum--;
            }
    } else {
        for (int j = 0; j < size; j++)
            if (edge[pos][j] != 65535) {
                edge[pos][j] = 65535;
                if (kind == 2) edge[j][pos] = 65535;
                edgeNum--;
            }
    }
}

template <class ElemType>
int
GraphAM<ElemType>::SetElem(ElemType e, ElemType x) {
    int pos = LocateVer(e);
    if (pos < 0) return false;
    vertex[pos].elem = x;
    return true;
}

template <class ElemType>
int
GraphAM<ElemType>::FirstAdjVer(ElemType e) {
    int pos = LocateVer(e);
    if (pos < 0) return -1;
    return PFirstAdjVer(pos);
}

template <class ElemType>
int
GraphAM<ElemType>::PFirstAdjVer(int pos) {
    if (kind < 2) {
        for (int j = 0; j < size; j++)
            if (j != pos && edge[pos][j] == 1) return j;
    } else {
        for (int j = 0; j < size; j++)
            if (j != pos && edge[pos][j] != 65536) return j;
    }
    return -1;
}

template <class ElemType>
int
GraphAM<ElemType>::NextAdjVer(int v, int pos) {
	return FirstAdjVer(pos + 1, v);
}

template <class ElemType>
int
GraphAM<ElemType>::FirstAdjVer(int pos, int s) {
    if (kind < 2) {
        for (int j = s; j < size; j++)
            if (j != pos && edge[pos][j] == 1) return j;
    } else {
        for (int j = s; j < size; j++)
            if (j != pos && edge[pos][j] != 65535) return j;
    }
    return -1;
}

template <class ElemType>
int
GraphAM<ElemType>::EdgeExsit(ElemType s, ElemType e) {
    int i = LocateVer(s);
    int j = LocateVer(e);
    if (i < 0 || j < 0) return false;
    if (kind < 2) {
        if (edge[i][j] == 1)
            return true;
        else
            return false;
    } else if (edge[i][j] == 65535)
        return false;
    else
        return true;
}

template <class ElemType>
int
GraphAM<ElemType>::SetWeight(ElemType s, ElemType e, int w) {
    int i = LocateVer(s);
    int j = LocateVer(e);
    if (i < 0 || j < 0) return false;
    if (edge[i][j] == 65535) return false;
    edge[i][j] = w;
    return true;
}

template <class ElemType>
void
GraphAM<ElemType>::Display() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }
}

template <class ElemType>
void
GraphAM<ElemType>::TraverseDFS(int start) {
    int m, ok;
    m = ok = 0;
    static int * tag = new int[size];
    for (int i = 0; i < size; i++)
        tag[i] = 0;
    if (start > 0) {
        m = DFS(start, tag);
        if (m == verNum) ok = 1;
    }
    if (ok == 0) {
        for (int i = 0; i < size; i++)
            if (vertex[i].flag == 1 && tag[i] == 0) {
                m = m + DFS(i, tag);
                if (m == verNum) break;
            }
    }
    for(int i=0;i<verNum;i++){
    	cout<<tag[i]<<" ";
    }
	cout << endl;
    delete[] tag;
}

template <class ElemType>
int
GraphAM<ElemType>::DFS(int s, int tag[]) {
    int n = 0;
    cout << vertex[s].elem << " ";
    tag[s] = 1;
    int pos = FirstAdjVer(s);
    while (pos >= 0 && tag[pos] == 0) {
        n += DFS(pos, tag);
        pos = NextAdjVer(pos, s);
    }
    return n + 1;
}

template <class ElemType>
void
GraphAM<ElemType>::BFS(int start) {
}