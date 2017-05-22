// 文件路径名: graph_root\main.cpp
#include "utility.h"					// 实用程序软件包
#include "adj_matrix_dir_graph.h"		// 有向图的邻接矩阵类
#include "graph_root.h"					// 图顶点算法

int main(void)
{
	int m[4][4] = {						// 邻接矩阵
		{0, 1, 1, 1},
		{0, 0, 0, 0},
		{0, 0, 0, 1},
		{1, 0, 0, 0}
	};
	int n = 4;							// 顶点个数

	AdjMatrixDirGraph<char> g(n);		// 定义图	

	for (int u = 0; u < n; u++)
	{	// 生成邻接矩阵的行
		for (int v = 0; v < n; v++)
		{	// 生成邻接矩阵元素的值
			if (m[u][v] == 1) g.InsertEdge(u, v);
		}
	}

	cout << "图:" << endl;
	Display(g, false);					// 显示图g
	cout << endl;
	GraphRoot(g);						// 判断有向图g是否有根，若有，则显示所有根结点的值

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}


