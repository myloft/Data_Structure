#pragma once
#include "node.h"
// 链栈类模板
template<class ElemType>
class SqStack
{
private:
	//  顺序栈的数据成员:
	int count=0;			// 栈顶元素下标
	int Size = 0;
	int maxSize=0;		// 栈最大元素个数
	ElemType *elems;	// 元素存储空间
public:             //  抽象数据类型方法声明
	bool	Setup(int size);  //size为栈的长度
	virtual ~SqStack();
	void  Clear();
	bool  Empty();
	int  Length();
	bool Full();
	bool Push(ElemType e); //新元素入栈
	bool Pop(ElemType &e); //出栈，即删除栈顶元素
	bool Top(ElemType &e); //读栈，即读取栈顶元素
	void Traverse();
};

template <class ElemType>
bool SqStack<ElemType>::Setup(int size)
{
	elems = new ElemType[Size];
	if (elems == NULL)
		exit(1);
	maxSize = size;	     // 最大元素个数
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
	if (count == maxSize)  //栈满
		return false;
	elems[count] = e;    //新元素入栈顶
	count++;
	return true;
}

template<class ElemType>
bool SqStack<ElemType>::Pop(ElemType &e)
{
	if (Empty())     return false; // 栈空			
	else                                       // 操作成功
	{
		e = elems[count - 1];            // 用e返回栈顶元素
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
