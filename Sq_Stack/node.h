#pragma once
#ifndef __NODE_H__
#define __NODE_H__

// 结点类模板
template <class ElemType>
struct Node
{
	// 数据成员:
	ElemType data;			// 数据域
	Node<ElemType> *next;		// 指针域
};
#endif