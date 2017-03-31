#pragma once
#ifndef LINK_LIST_NODE_H
#define LINK_LIST_NODE_H
template <class ElemType>
struct Node {
	// ���ݳ�Ա:
	ElemType data;                // ������
	Node<ElemType> *next;        // ָ����
								 //���캯��ģ��
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