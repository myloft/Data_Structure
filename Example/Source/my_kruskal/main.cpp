// 文件路径名: my_kruskal\main.cpp
#include "utility.h"					// 实用程序软件包
#include "my_kruskal.h"					// Kruskal算法

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
		int infity = DEFAULT_INFINITY;	// 无究大(用于表示两顶点之无边时的权值)
		char vexs[] = {'A', 'B', 'C', 'D'};	// 顶点元素
		int m[4][4] = {					// 邻接矩阵
			{infity, 2, 3, 4},
			{2, infity, 5, 6},
			{3, 5, infity, 7},
			{4, 6, 7, infity}
		};
		int n = 4;						// 顶点数

		AdjListUndirNetwork<char, int> net(vexs, n);	// 生成网

		for (int u = 0; u < n; u++)
		{	// 生成邻接矩阵的行
			for (int v = 0; v < n; v++)
			{	// 生成邻接矩阵元素的值
				if (m[u][v] != infity) net.InsertEdge(u, v, m[u][v]);
			}
		}

		cout << "原网:";
		Display(net);					// 显示网net
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		cout << "Kruskal算法产生最小生成树的边:" << endl;
		MiniSpanTreeKruskal(net);		// Kruskal算法
		cout << endl;
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}

