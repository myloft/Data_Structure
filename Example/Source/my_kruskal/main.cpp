// �ļ�·����: my_kruskal\main.cpp
#include "utility.h"					// ʵ�ó��������
#include "my_kruskal.h"					// Kruskal�㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;	// �޾���(���ڱ�ʾ������֮�ޱ�ʱ��Ȩֵ)
		char vexs[] = {'A', 'B', 'C', 'D'};	// ����Ԫ��
		int m[4][4] = {					// �ڽӾ���
			{infity, 2, 3, 4},
			{2, infity, 5, 6},
			{3, 5, infity, 7},
			{4, 6, 7, infity}
		};
		int n = 4;						// ������

		AdjListUndirNetwork<char, int> net(vexs, n);	// ������

		for (int u = 0; u < n; u++)
		{	// �����ڽӾ������
			for (int v = 0; v < n; v++)
			{	// �����ڽӾ���Ԫ�ص�ֵ
				if (m[u][v] != infity) net.InsertEdge(u, v, m[u][v]);
			}
		}

		cout << "ԭ��:";
		Display(net);					// ��ʾ��net
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "Kruskal�㷨������С�������ı�:" << endl;
		MiniSpanTreeKruskal(net);		// Kruskal�㷨
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

