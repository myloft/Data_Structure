// �ļ�·����:my_gen_list\my_gen_node.h
#ifndef __MY_GEN_NODE_H__
#define __MY_GEN_NODE_H__

#include "my_use_space_list.h"			// �����ʹ�ÿռ����

#ifndef __MY_GEN_LIST_NODE_TYPE__
#define __MY_GEN_LIST_NODE_TYPE__
enum MyGenListNodeType {HEAD, ATOM, LIST};
#endif

// ���������
template<class ElemType>
struct MyGenListNode
{
// ���ݳ�Ա:
	MyGenListNodeType tag;				
		// ��־��,HEAD(0):ͷ���, ATOM(1):ԭ�ӽṹ, LIST(2):����
	MyGenListNode<ElemType> *nextLink;	// ָ��ͬһ���е���һ�����ָ����
	union
	{
		int ref;						// tag=HEAD,ͷ���,���������
		ElemType atom;					// tag=ATOM,���ԭ�ӽ���������
		MyGenListNode<ElemType> *subLink;	// tag=LISK,���ָ���ӱ��ָ����
	}; 

// ���캯��:
	MyGenListNode(MyGenListNodeType tg = HEAD, MyGenListNode<ElemType> *next = NULL);
		// �ɱ�־tg��ָ��next����������
};

// ����������ʵ�ֲ���
template<class ElemType>
MyGenListNode<ElemType>::MyGenListNode(MyGenListNodeType tg, 
	MyGenListNode<ElemType> *next)
// ����������ɱ�־tg��ָ��next����������
{
	tag = tg;							// ��־
	nextLink = next;					// ���
	gMyUseSpaceList.Push(this);			// ��ָ��ǰ����ָ����뵽�����ʹ�ÿռ����
}

#endif

 
