// �ļ�·����: graph_root\main.cpp
#include "utility.h"					// ʵ�ó��������
#include "adj_matrix_dir_graph.h"		// ����ͼ���ڽӾ�����
#include "graph_root.h"					// ͼ�����㷨

int main(void)
{
	int m[4][4] = {						// �ڽӾ���
		{0, 1, 1, 1},
		{0, 0, 0, 0},
		{0, 0, 0, 1},
		{1, 0, 0, 0}
	};
	int n = 4;							// �������

	AdjMatrixDirGraph<char> g(n);		// ����ͼ	

	for (int u = 0; u < n; u++)
	{	// �����ڽӾ������
		for (int v = 0; v < n; v++)
		{	// �����ڽӾ���Ԫ�ص�ֵ
			if (m[u][v] == 1) g.InsertEdge(u, v);
		}
	}

	cout << "ͼ:" << endl;
	Display(g, false);					// ��ʾͼg
	cout << endl;
	GraphRoot(g);						// �ж�����ͼg�Ƿ��и������У�����ʾ���и�����ֵ

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}


