#ifndef __MY_KRUSKAL_H__
#define __MY_KRUSKAL_H__

#include "adj_list_undir_network.h"			// �ڽӱ�������
#include "equivalence.h"					// �ȼ���
#include "min_priority_lk_queue.h"			// ��С������������

// Kruskal�߽ṹ
template <class WeightType>
struct KruskalEdge
{
	int vertex1, vertex2;					// �ߵĶ���
	WeightType weight;						// �ߵ�Ȩֵ
	KruskalEdge(int v1 = -1, int v2 = -1, int w = 0): vertex1(v1), vertex2(v2), weight(w){ };
		// ���캯��
};

template <class WeightType>
bool operator <=(const KruskalEdge<WeightType> &first, const KruskalEdge<WeightType> &second)
// �������: ���ع�ϵ�����<=
{
	return first.weight <= second.weight;	
}

template <class ElemType, class WeightType>
void MiniSpanTreeKruskal(const AdjListUndirNetwork<ElemType, WeightType> &net)
// ��ʼ������������net
// �����������Kruskal�㷨������net����С����������
{
	int vexNum = net.GetVexNum();			// ������
	Equivalence equival(vexNum);			// �ȼ���
	MinPriorityLinkQueue<KruskalEdge<WeightType> > prioQ;	// ���ȶ���

	for (int v = 0; v < vexNum; v++)
	{	// ����v
		for (int u = net.FirstAdjVex(v); u >= 0; u = net.NextAdjVex(v, u))
		{	// ����(v, u)����kEdge��
			if (v < u)
			{	// ֻ�洢v > u�ı�(v,u)
				KruskalEdge<WeightType> kEdge(v, u, net.GetWeight(v, u)); // ���ڱ�
				prioQ.InQueue(kEdge);		// �����
			}
		}
	}

	for (int count = 0; count < vexNum - 1;)
	{	// �����С�������еı�
		KruskalEdge<WeightType> kEdge;		// ��
		prioQ.OutQueue(kEdge);				// �߳���
		int v1 = kEdge.vertex1, v2 = kEdge.vertex2;		// �ߵĶ���
		if (equival.Differ(v1, v2))
		{	// �ߵ����˲���ͬһ������,��Ϊ��С�����������ϵı�
			cout << "edge:(" << v1 << "," << v2 << ") weight:" 
				<<net.GetWeight(v1, v2)<< endl ;		// ����߼�Ȩֵ
			count++;						// ����ߵĸ����Լ�1
			equival.Union(v1, v2);			// ��v2��������v1���ڵ������кϲ�
		}
	}
}

#endif



	

