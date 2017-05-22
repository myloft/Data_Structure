// 文件路径名: my_radix_sort\my_radix_sort.h
#ifndef __MY_RADIX_SORT_H__
#define __MY_RADIX_SORT_H__

// 静态链表的结点类型
template <class ElemType>
struct NodeType
{
	ElemType e;								// 数据元素
	int next;								// 表示后继的元素的位置
};

template <class ElemType>
void MyDistribute(NodeType<ElemType> node[], int n, int r, int d, int i, int f[], int e[])
// 初始条件: node存储静态链表,r为基数,d为关键字位数,f[]与e[]存储各队列的队头与队尾
// 操作结果: 进行第i趟分配
{
	int j, index, power;					// 临时变量
	for (j = 0; j < r; j++) f[j] = -1;		// 各队列为空 
	for (power = (int)pow((double)r, i - 1), index = node[0].next; index != -1; index = node[index].next)
	{	// 进行第i起分配
		j = (node[index].e / power) % r;	// 取出第i位
		if (f[j] == -1) f[j] = index;		// 空队列
		else node[e[j]].next = index;		// 非空队列
		e[j] = index;						// 新队尾

	}
}

template <class ElemType>
void MyColect(NodeType<ElemType> node[], int n, int r, int d, int i, int f[], int e[])
// 初始条件: node存储静态链表,r为基数,d为关键字位数,f[]与e[]存储各队列的队头与队尾
// 操作结果: 进行第i趟收集
{
	int j, t;								// 临时变量
	int first = true;						// 是否为1个非空队列
	for (j = 0; j < r; j++)
	{	// 将非空队列连接成一个链表
		if (f[j] != -1)
		{	// 非空队列
			if (first) 
			{	// 第1个非空队列
				node[0].next = f[j];		// node[0].next指向第1个非实队列的队头结点
				first = false;				// 下1个非空队列将不为1个非实队列
			}
			else
			{	// 非第1个非空队列
				node[t].next = f[j];		// 上1个非空队列队尾t的后继续为f[j]
			}
			t = e[j];						// t表示当前非空队列的队尾
		}
	}
	node[t].next = -1;						// 静态链表的最后1个结点的后继为空
}

template <class ElemType>
void MyRadixSort(ElemType elem[], int n, int r, int d)
// 初始条件: r为基数,d为关键字位数
// 操作结果: 对elem进行基数排序
{
	NodeType<ElemType> *node;				// 存储静态链表结点
	int *f, *e;								// 队头与队尾数组
	int i, p;								// 临时变量

	node = new NodeType<ElemType>[n + 1];	// 分配存储空间,node[0]为头结点
	f = new int[r];	e = new int[r];			// 为队头与队尾数组分配存储空间

	for (i = 1; i <= n; i++)
	{	// 初始化静态链表
		node[i].e = elem[i - 1];			// 初始元素值
		node[i].next = i + 1;				// 后继元素位置
	}
	node[0].next = 1;						// 头结点的后继
	node[n].next = -1;						// 表尾后继为空(-1表示空)

	for (i = 1; i <= d; i++)
	{	// 第i趟分配与收集
		MyDistribute(node, n, r, d, i, f, e);	// 分配
		MyColect(node, n, r, d, i, f, e);		// 收集
	}

	p = node[0].next;						// p指向第1个元素
	for (i = 0; i < n; i++)
	{	// 将静态链表中的元素存入elem[]
		elem[i] = node[p].e;				// 元素值
		p = node[p].next;					// p移向后继
	}
	
	delete []f;								// 释放队头数组所占存储空间
	delete []e;								// 释放队尾数组所占存储空间
	delete []node;							// 释放静态链表所占存储空间
}

#endif
