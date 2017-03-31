#pragma once
#include "node.h"
// ��ջ��ģ��
template<class ElemType>
class SqStack
{
private:
	//  ˳��ջ�����ݳ�Ա:
	int count=0;			// ջ��Ԫ���±�
	int Size = 0;
	int maxSize=0;		// ջ���Ԫ�ظ���
	ElemType *elems;	// Ԫ�ش洢�ռ�
public:             //  �����������ͷ�������
	bool	Setup(int size);  //sizeΪջ�ĳ���
	virtual ~SqStack();
	void  Clear();
	bool  Empty();
	int  Length();
	bool Full();
	bool Push(ElemType e); //��Ԫ����ջ
	bool Pop(ElemType &e); //��ջ����ɾ��ջ��Ԫ��
	bool Top(ElemType &e); //��ջ������ȡջ��Ԫ��
	void Traverse();
};

template <class ElemType>
bool SqStack<ElemType>::Setup(int size)
{
	elems = new ElemType[Size];
	if (elems == NULL)
		exit(1);
	maxSize = size;	     // ���Ԫ�ظ���
	count = 0;
}

template <class ElemType>
SqStack<ElemType>:: ~SqStack()
{
	delete[]elems;
	maxSize = 0;
	count = 0;
}

template <class ElemType>
void SqStack<ElemType>::Clear()
{
	count = 0;
}

template<class ElemType>
bool SqStack<ElemType>::Empty()
{
	return count == 0;
}

template <class ElemType>
bool SqStack<ElemType>::Full()
{
	return  count == maxSize;
}

template <class ElemType>
int SqStack<ElemType>::Length()
{
	return  count;
}

template<class ElemType>
bool SqStack<ElemType>::Push(ElemType e){
	if (count == maxSize)  //ջ��
		return false;
	elems[count] = e;    //��Ԫ����ջ��
	count++;
	return true;
}

template<class ElemType>
bool SqStack<ElemType>::Pop(ElemType &e)
{
	if (Empty())     return false; // ջ��			
	else                                       // �����ɹ�
	{
		e = elems[count - 1];            // ��e����ջ��Ԫ��
		count--;
		return true;
	}
}

template<class ElemType>
bool SqStack<ElemType>::Top(ElemType &e)
{
	if (Empty())    return false;
	else
	{
		e = elems[count - 1];
		return true;
	}
}

template <class ElemType>
void SqStack<ElemType>::Traverse()
{
	for (int curPosition = 1; curPosition <= count;
		curPosition++)
	{
		cout << elems[curPosition - 1] << " ";
	}
}
