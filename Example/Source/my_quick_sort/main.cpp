// �ļ�·����: my_quick_sort\main.cpp
#include "utility.h"							// ʵ�ó��������
#include "quick_sort.h"							// ���������㷨
#include "my_quick_sort.h"						// �����Ŀ��������㷨

int main(void)
{
	int *a, *b;									// ����
	int size = 1000000;							// Ԫ�ظ���
	int pos;									// ��ʱ����
	a = new int[size];							// ����洢�ռ�
	b = new int[size];							// ����洢�ռ�
	double time;								// ����ʱ��

	SetRandSeed();								// ���õ�ǰʱ��Ϊ���������
	for (pos = 0; pos < size; pos++)
		a[pos] = GetRand();						// ���������

	for (pos = 0; pos < size; pos++)
		b[pos] = a[pos];						// ����a��b
	
	cout << "����Ԫ�ظ���:" << size << endl;
	Timer objTime;								// ��ʱ������

	QuickSort(b, size);							// ��������
	time = objTime.ElapsedTime();				// ����ʱ��
	cout << "��������:" << time << "��" << endl;// ��ʾ����ʱ��
	
	for (pos = 0; pos < size; pos++)
		b[pos] = a[pos];						// ����a��b

	objTime.Reset();							// ���ÿ�ʼʱ��
	MyQuickSort(b, size);						// �����Ŀ�������
	time = objTime.ElapsedTime();				// ����ʱ��
	cout << "�����Ŀ�������:" << time << "��" << endl;// ��ʾ����ʱ��

	delete []a; delete []b;						// �ͷŴ洢�ռ�

	system("PAUSE");							// ���ÿ⺯��system()
	return 0;									// ����ֵ0, ���ز���ϵͳ
}
