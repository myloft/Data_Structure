// 文件路径名: my_radix_sort\main.cpp
#include "utility.h"							// 实用程序软件包
#include "radix_sort.h"							// 基数排序算法
#include "my_radix_sort.h"						// 改造后的基数排序算法

int main(void)
{
	int *a, *b;									// 数组
	int size = 1000000;							// 元素个数
	int pos;									// 临时变量
	a = new int[size];							// 分配存储空间
	b = new int[size];							// 分配存储空间
	double time;								// 运行时间

	SetRandSeed();								// 设置当前时间为随机数种子
	for (pos = 0; pos < size; pos++)
		a[pos] = GetRand();						// 成生随机数

	for (pos = 0; pos < size; pos++)
		b[pos] = a[pos];						// 复制a到b
	
	cout << "数据元素个数:" << size << endl;
	Timer objTime;								// 计时器对象

	RadixSort(b, size, 10, 5);					// 基数排序
	time = objTime.ElapsedTime();				// 运行时间
	cout << "基数排序:" << time << "秒" << endl;// 显示排序时间
	
	for (pos = 0; pos < size; pos++)
		b[pos] = a[pos];						// 复制a到b

	objTime.Reset();							// 重置开始时间
	MyRadixSort(b, size, 10, 5);				// 改造后的基数排序
	time = objTime.ElapsedTime();				// 运行时间
	cout << "改造后的基数排序:" << time << "秒" << endl;// 显示排序时间

	delete []a; delete []b;						// 释放存储空间

	system("PAUSE");							// 调用库函数system()
	return 0;									// 返回值0, 返回操作系统
}
