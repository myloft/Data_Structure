#pragma once
#ifndef LINK_LIST_NODE_H
#define LINK_LIST_NODE_H
template <class ElemType>
struct Node {
	// 数据成员:
	ElemType data;                // 数据域
	Node<ElemType> *next;        // 指针域
								 //构造函数模板
	Node();

	Node(ElemType item, Node<ElemType> *link = NULL);
};

template <class ElemType>
Node<ElemType>::Node()
{
	next = NULL;
}

template <class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
{
	data = item;
	next = link;
}
#endif //LINK_LIST_NODE_H