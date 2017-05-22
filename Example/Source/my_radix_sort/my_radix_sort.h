// �ļ�·����: my_radix_sort\my_radix_sort.h
#ifndef __MY_RADIX_SORT_H__
#define __MY_RADIX_SORT_H__

// ��̬����Ľ������
template <class ElemType>
struct NodeType
{
	ElemType e;								// ����Ԫ��
	int next;								// ��ʾ��̵�Ԫ�ص�λ��
};

template <class ElemType>
void MyDistribute(NodeType<ElemType> node[], int n, int r, int d, int i, int f[], int e[])
// ��ʼ����: node�洢��̬����,rΪ����,dΪ�ؼ���λ��,f[]��e[]�洢�����еĶ�ͷ���β
// �������: ���е�i�˷���
{
	int j, index, power;					// ��ʱ����
	for (j = 0; j < r; j++) f[j] = -1;		// ������Ϊ�� 
	for (power = (int)pow((double)r, i - 1), index = node[0].next; index != -1; index = node[index].next)
	{	// ���е�i�����
		j = (node[index].e / power) % r;	// ȡ����iλ
		if (f[j] == -1) f[j] = index;		// �ն���
		else node[e[j]].next = index;		// �ǿն���
		e[j] = index;						// �¶�β

	}
}

template <class ElemType>
void MyColect(NodeType<ElemType> node[], int n, int r, int d, int i, int f[], int e[])
// ��ʼ����: node�洢��̬����,rΪ����,dΪ�ؼ���λ��,f[]��e[]�洢�����еĶ�ͷ���β
// �������: ���е�i���ռ�
{
	int j, t;								// ��ʱ����
	int first = true;						// �Ƿ�Ϊ1���ǿն���
	for (j = 0; j < r; j++)
	{	// ���ǿն������ӳ�һ������
		if (f[j] != -1)
		{	// �ǿն���
			if (first) 
			{	// ��1���ǿն���
				node[0].next = f[j];		// node[0].nextָ���1����ʵ���еĶ�ͷ���
				first = false;				// ��1���ǿն��н���Ϊ1����ʵ����
			}
			else
			{	// �ǵ�1���ǿն���
				node[t].next = f[j];		// ��1���ǿն��ж�βt�ĺ����Ϊf[j]
			}
			t = e[j];						// t��ʾ��ǰ�ǿն��еĶ�β
		}
	}
	node[t].next = -1;						// ��̬��������1�����ĺ��Ϊ��
}

template <class ElemType>
void MyRadixSort(ElemType elem[], int n, int r, int d)
// ��ʼ����: rΪ����,dΪ�ؼ���λ��
// �������: ��elem���л�������
{
	NodeType<ElemType> *node;				// �洢��̬������
	int *f, *e;								// ��ͷ���β����
	int i, p;								// ��ʱ����

	node = new NodeType<ElemType>[n + 1];	// ����洢�ռ�,node[0]Ϊͷ���
	f = new int[r];	e = new int[r];			// Ϊ��ͷ���β�������洢�ռ�

	for (i = 1; i <= n; i++)
	{	// ��ʼ����̬����
		node[i].e = elem[i - 1];			// ��ʼԪ��ֵ
		node[i].next = i + 1;				// ���Ԫ��λ��
	}
	node[0].next = 1;						// ͷ���ĺ��
	node[n].next = -1;						// ��β���Ϊ��(-1��ʾ��)

	for (i = 1; i <= d; i++)
	{	// ��i�˷������ռ�
		MyDistribute(node, n, r, d, i, f, e);	// ����
		MyColect(node, n, r, d, i, f, e);		// �ռ�
	}

	p = node[0].next;						// pָ���1��Ԫ��
	for (i = 0; i < n; i++)
	{	// ����̬�����е�Ԫ�ش���elem[]
		elem[i] = node[p].e;				// Ԫ��ֵ
		p = node[p].next;					// p������
	}
	
	delete []f;								// �ͷŶ�ͷ������ռ�洢�ռ�
	delete []e;								// �ͷŶ�β������ռ�洢�ռ�
	delete []node;							// �ͷž�̬������ռ�洢�ռ�
}

#endif
