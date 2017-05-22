// �ļ�·����: my_radix_sort\main.cpp
#include "utility.h"							// ʵ�ó��������
#include "radix_sort.h"							// ���������㷨
#include "my_radix_sort.h"						// �����Ļ��������㷨

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

	RadixSort(b, size, 10, 5);					// ��������
	time = objTime.ElapsedTime();				// ����ʱ��
	cout << "��������:" << time << "��" << endl;// ��ʾ����ʱ��
	
	for (pos = 0; pos < size; pos++)
		b[pos] = a[pos];						// ����a��b

	objTime.Reset();							// ���ÿ�ʼʱ��
	MyRadixSort(b, size, 10, 5);				// �����Ļ�������
	time = objTime.ElapsedTime();				// ����ʱ��
	cout << "�����Ļ�������:" << time << "��" << endl;// ��ʾ����ʱ��

	delete []a; delete []b;						// �ͷŴ洢�ռ�

	system("PAUSE");							// ���ÿ⺯��system()
	return 0;									// ����ֵ0, ���ز���ϵͳ
}
