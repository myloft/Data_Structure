#pragma once
#include <iostream>
#include "node.h"
using namespace std;

template<class ElemType>
class LinkStack
{
private:     //  ��ջʵ�ֵ����ݳ�Ա:
	Node<ElemType> *top; // ջ��ָ��
	int count = 0;	//ջ����
public:             //  �����������ͷ�������
	bool Setup();
	virtual ~LinkStack();
	void  Clear();
	bool  Empty();
	int  Length();
	bool Push(ElemType e); //��Ԫ����ջ
	bool Pop(ElemType &e); //��ջ����ɾ��ջ��Ԫ��
	bool Top(ElemType &e); //��ջ������ȡջ��Ԫ��
	void Traverse();
};

template <class ElemType>
bool LinkStack<ElemType>::Setup()
{
	top = NULL;
	count = 0;
	return true;
}

template<class ElemType>
void LinkStack<ElemType>::Clear()
{
	Node<ElemType> *p;
	while (top != NULL)
	{
		p = top;
		top = top->next;
		delete p;
	}
	count = 0;
}

template<class ElemType>
bool LinkStack<ElemType>::Empty()
{
	return top == NULL;
}

template <class ElemType>
int LinkStack<ElemType>::Length()
{
	return count;
}

template<class ElemType>
bool LinkStack<ElemType>::Push(ElemType e)
{
	Node<ElemType> *newtop = new
		Node<ElemType>(e, top);
	if (newtop == NULL)   return false;
	else
	{
		top = newtop;
		count++;
		return true;
	}
}

template<class ElemType>
bool LinkStack<ElemType>::Pop(ElemType &e)
{
	if (Empty())    return false;
	else
	{
		Node<ElemType> *old_top = top;
		e = old_top->data;
		top = old_top->next;
		delete old_top;	count--;
		return true;
	}
}

template<class ElemType>
bool LinkStack<ElemType>::Top(ElemType &e)
{
	if (Empty())    return false;
	else
	{
		e = top->data;
		return true;
	}
}

template <class ElemType>
void LinkStack<ElemType>::Traverse()
{
	Node<ElemType> *tmpPtr;
	for (tmpPtr = top; tmpPtr != NULL;
		tmpPtr = tmpPtr->next)
	{
		cout << tmpPtr->data << " ";
	}
}

template <class ElemType>
LinkStack<ElemType>:: ~LinkStack()
{
	Clear();
}



