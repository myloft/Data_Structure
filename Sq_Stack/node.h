#pragma once
#ifndef __NODE_H__
#define __NODE_H__

// �����ģ��
template <class ElemType>
struct Node
{
	// ���ݳ�Ա:
	ElemType data;			// ������
	Node<ElemType> *next;		// ָ����
};
#endif