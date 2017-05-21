#ifndef __MY_KRUSKAL_H__
#define __MY_KRUSKAL_H__

#include "adj_list_undir_network.h"			// 邻接表无向网
#include "equivalence.h"					// 等价类
#include "min_priority_lk_queue.h"			// 最小优先链队列类

// Kruskal边结构
template <class WeightType>
struct KruskalEdge
{
	int vertex1, vertex2;					// 边的顶点
	WeightType weight;						// 边的权值
	KruskalEdge(int v1 = -1, int v2 = -1, int w = 0): vertex1(v1), vertex2(v2), weight(w){ };
		// 构造函数
};

template <class WeightType>
bool operator <=(const KruskalEdge<WeightType> &first, const KruskalEdge<WeightType> &second)
// 操作结果: 重载关系运算符<=
{
	return first.weight <= second.weight;	
}

template <class ElemType, class WeightType>
void MiniSpanTreeKruskal(const AdjListUndirNetwork<ElemType, WeightType> &net)
// 初始条件：存在网net
// 操作结果：用Kruskal算法构造网net的最小代价生成树
{
	int vexNum = net.GetVexNum();			// 顶点数
	Equivalence equival(vexNum);			// 等价类
	MinPriorityLinkQueue<KruskalEdge<WeightType> > prioQ;	// 优先队列

	for (int v = 0; v < vexNum; v++)
	{	// 顶点v
		for (int u = net.FirstAdjVex(v); u >= 0; u = net.NextAdjVex(v, u))
		{	// 将边(v, u)存入kEdge中
			if (v < u)
			{	// 只存储v > u的边(v,u)
				KruskalEdge<WeightType> kEdge(v, u, net.GetWeight(v, u)); // 生在边
				prioQ.InQueue(kEdge);		// 边入队
			}
		}
	}

	for (int count = 0; count < vexNum - 1;)
	{	// 输出最小生成树中的边
		KruskalEdge<WeightType> kEdge;		// 边
		prioQ.OutQueue(kEdge);				// 边出队
		int v1 = kEdge.vertex1, v2 = kEdge.vertex2;		// 边的顶点
		if (equival.Differ(v1, v2))
		{	// 边的两端不在同一棵树上,则为最小代价生成树上的边
			cout << "edge:(" << v1 << "," << v2 << ") weight:" 
				<<net.GetWeight(v1, v2)<< endl ;		// 输出边及权值
			count++;						// 输出边的个数自加1
			equival.Union(v1, v2);			// 将v2所在树与v1所在的树进行合并
		}
	}
}

#endif



	

