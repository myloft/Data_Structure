// 文件路径名:my_gen_list\my_use_space_list.h
#ifndef __MY_USE_SPACE_LIST_H__
#define __MY_USE_SPACE_LIST_H__

#include "node.h"					// 结点类

// 使用空间表类
class MyUseSpaceList
{
protected:
// 数据成员:
	Node<void *> *head;				// 使用空间表头指针

public:
// 方法:
	MyUseSpaceList();				// 无参数的构造函数
	~MyUseSpaceList();				// 析构函数
	void Push(void *nodePtr);		// 将指向结点的指针加入到使用空间表中
	void Delete(void *nodePtr);		// 释放nodePtr所指向的结点
};

// 使用空间表类的实现部分
MyUseSpaceList::MyUseSpaceList()
// 操作结果：构造使用空间表
{
	head = NULL;
}

MyUseSpaceList::~MyUseSpaceList()
// 操作结果：释放结点占用存储空间
{
	while (head != NULL)
	{	// 循环释放结点空间
		if (head->data != NULL)delete head->data;			
			// head->data存储的是指向结点的指针
		Node<void *> *tmpPtr = head;// 暂存head
		head = head->next;			// 新的head
		delete tmpPtr;				// 释放tmpPtr
	}
}

void MyUseSpaceList::Push(void *nodePtr)
// 操作结果：将指向结点的指针加入到使用空间表中
{
	Node<void *> *tmpPtr = new Node<void *>(nodePtr, head);	// 生成新使用空间表结点
	head = tmpPtr;					// tmpPtr为新表头	
}

void MyUseSpaceList::Delete(void *nodePtr)
// 操作结果：释放nodePtr所指向的结点
{
	for (Node<void *> *p = head; p != NULL; p = p->next)
	{	// 查找存储nodePtr的结点
		if (p->data == nodePtr)
		{	// 找到存储nodePtr的结点
			p->data = NULL;			// 将p->data置空,以免重复删除
			delete nodePtr;			// 释放nodePtr所指向的结点
			break;					// 退出循环
		}
	}
}

#ifndef __GLOBAL_MY_USE_SPACE_LIST__
#define __GLOBAL_MY_USE_SPACE_LIST__
static MyUseSpaceList gMyUseSpaceList;	// 全局使用空间表对象
#endif

#endif
