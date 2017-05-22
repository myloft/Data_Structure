// 文件路径名: my_quick_sort\my_quick_sort.h
#ifndef __MY_QUICK_SORT_H__
#define __MY_QUICK_SORT_H__

template <class ElemType>
int MyPartition(ElemType elem[], int low, int high)
// 操作结果:交换elem[low .. high]中的元素,使枢轴移动到适当位置,要求在枢轴之前的元素
//	不大于枢轴,在枢轴之后的元素不小于枢轴的,并返回枢轴的位置

{
	ElemType pivotElem = elem[low];			// 枢轴元素
	while (low < high)
	{
		while (low < high && elem[high] >= pivotElem)
		{	// elem[low]为枢轴,使high右边的元素不小于elem[low]
			high--;
		}
		elem[low] = elem[high];				// 将小于枢轴的元素移到低端

		while (low < high && elem[low] <= pivotElem)
		{	// elem[high]为枢轴,使low左边的元素不大于elem[high]
			low++;
		}
		elem[high] = elem[low];				// 将大于枢轴的元素移到高端
	}
	elem[low] = pivotElem;					// 枢轴元素到位

	return low;	// 返回枢轴位置
}

template <class ElemType>
void MyQuickSortHelp(ElemType elem[], int low, int high)
// 操作结果:对数组elem[low .. high]中的记录进行快速排序
{
	if (low < high)
	{	// 子序列elem[low .. high]长度大于1
		int pivotLoc = MyPartition(elem, low, high);// 进行一趟找分
		MyQuickSortHelp(elem, low, pivotLoc - 1);	// 对子表elem[low, pivotLoc - 1]递归排序
		MyQuickSortHelp(elem, pivotLoc + 1, high);	// 对子表elem[pivotLoc + 1, high]递归排序
	}
}

template <class ElemType>
void MyQuickSort(ElemType elem[], int n)
// 操作结果:对数组elem进行快速排序
{
	MyQuickSortHelp(elem, 0, n - 1);
}

#endif

