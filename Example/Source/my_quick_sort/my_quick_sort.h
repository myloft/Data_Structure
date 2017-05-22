// �ļ�·����: my_quick_sort\my_quick_sort.h
#ifndef __MY_QUICK_SORT_H__
#define __MY_QUICK_SORT_H__

template <class ElemType>
int MyPartition(ElemType elem[], int low, int high)
// �������:����elem[low .. high]�е�Ԫ��,ʹ�����ƶ����ʵ�λ��,Ҫ��������֮ǰ��Ԫ��
//	����������,������֮���Ԫ�ز�С�������,�����������λ��

{
	ElemType pivotElem = elem[low];			// ����Ԫ��
	while (low < high)
	{
		while (low < high && elem[high] >= pivotElem)
		{	// elem[low]Ϊ����,ʹhigh�ұߵ�Ԫ�ز�С��elem[low]
			high--;
		}
		elem[low] = elem[high];				// ��С�������Ԫ���Ƶ��Ͷ�

		while (low < high && elem[low] <= pivotElem)
		{	// elem[high]Ϊ����,ʹlow��ߵ�Ԫ�ز�����elem[high]
			low++;
		}
		elem[high] = elem[low];				// �����������Ԫ���Ƶ��߶�
	}
	elem[low] = pivotElem;					// ����Ԫ�ص�λ

	return low;	// ��������λ��
}

template <class ElemType>
void MyQuickSortHelp(ElemType elem[], int low, int high)
// �������:������elem[low .. high]�еļ�¼���п�������
{
	if (low < high)
	{	// ������elem[low .. high]���ȴ���1
		int pivotLoc = MyPartition(elem, low, high);// ����һ���ҷ�
		MyQuickSortHelp(elem, low, pivotLoc - 1);	// ���ӱ�elem[low, pivotLoc - 1]�ݹ�����
		MyQuickSortHelp(elem, pivotLoc + 1, high);	// ���ӱ�elem[pivotLoc + 1, high]�ݹ�����
	}
}

template <class ElemType>
void MyQuickSort(ElemType elem[], int n)
// �������:������elem���п�������
{
	MyQuickSortHelp(elem, 0, n - 1);
}

#endif

