// �ļ�·����:my_gen_list\my_use_space_list.h
#ifndef __MY_USE_SPACE_LIST_H__
#define __MY_USE_SPACE_LIST_H__

#include "node.h"					// �����

// ʹ�ÿռ����
class MyUseSpaceList
{
protected:
// ���ݳ�Ա:
	Node<void *> *head;				// ʹ�ÿռ��ͷָ��

public:
// ����:
	MyUseSpaceList();				// �޲����Ĺ��캯��
	~MyUseSpaceList();				// ��������
	void Push(void *nodePtr);		// ��ָ�����ָ����뵽ʹ�ÿռ����
	void Delete(void *nodePtr);		// �ͷ�nodePtr��ָ��Ľ��
};

// ʹ�ÿռ�����ʵ�ֲ���
MyUseSpaceList::MyUseSpaceList()
// �������������ʹ�ÿռ��
{
	head = NULL;
}

MyUseSpaceList::~MyUseSpaceList()
// ����������ͷŽ��ռ�ô洢�ռ�
{
	while (head != NULL)
	{	// ѭ���ͷŽ��ռ�
		if (head->data != NULL)delete head->data;			
			// head->data�洢����ָ�����ָ��
		Node<void *> *tmpPtr = head;// �ݴ�head
		head = head->next;			// �µ�head
		delete tmpPtr;				// �ͷ�tmpPtr
	}
}

void MyUseSpaceList::Push(void *nodePtr)
// �����������ָ�����ָ����뵽ʹ�ÿռ����
{
	Node<void *> *tmpPtr = new Node<void *>(nodePtr, head);	// ������ʹ�ÿռ����
	head = tmpPtr;					// tmpPtrΪ�±�ͷ	
}

void MyUseSpaceList::Delete(void *nodePtr)
// ����������ͷ�nodePtr��ָ��Ľ��
{
	for (Node<void *> *p = head; p != NULL; p = p->next)
	{	// ���Ҵ洢nodePtr�Ľ��
		if (p->data == nodePtr)
		{	// �ҵ��洢nodePtr�Ľ��
			p->data = NULL;			// ��p->data�ÿ�,�����ظ�ɾ��
			delete nodePtr;			// �ͷ�nodePtr��ָ��Ľ��
			break;					// �˳�ѭ��
		}
	}
}

#ifndef __GLOBAL_MY_USE_SPACE_LIST__
#define __GLOBAL_MY_USE_SPACE_LIST__
static MyUseSpaceList gMyUseSpaceList;	// ȫ��ʹ�ÿռ�����
#endif

#endif
