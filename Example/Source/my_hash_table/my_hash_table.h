// 文件路径名: my_hash_table\my_hash_table.h
#ifndef __MY_HASH_TABLE_H__
#define __MY_HASH_TABLE_H__

#include "lk_list.h"							// 线性链表

// 散列表类
template <class ElemType, class KeyType>
class MyHashTable
{
protected:
//  散列表的的数据成员:
	LinkList<ElemType> *ht;						// 散列表
	int m;										// 散列表长度

public:
//  二叉树方法声明及重载编译系统默认方法声明:
    MyHashTable(int size);						// 构造函数
    virtual ~MyHashTable();						// 析造函数
    void Traverse(void (*Visit)(const ElemType &)) const;	// 遍历散列表
	bool Search(const KeyType &key, int &pos);	// 查找关键字为key的元素的位置
	bool Insert(const ElemType &e);				// 插入元素e
	bool Delete(const KeyType &key);			// 删除关键字为key的元素
    MyHashTable(const MyHashTable<ElemType, KeyType> &copy);// 复制构造函数
    MyHashTable<ElemType, KeyType> &operator=
		(const MyHashTable<ElemType, KeyType> &copy);		// 赋值运算符重载
};

// 散列表类的实现部分
template <class ElemType, class KeyType>
MyHashTable<ElemType, KeyType>::MyHashTable(int size)
// 操作结果: 以size为散列表长度构造一个空的散表表
{
	m = size;									// 赋值散列表容量
	ht = new LinkList<ElemType>[m];				// 分配存储空间
}

template <class ElemType, class KeyType>
MyHashTable<ElemType, KeyType>::~MyHashTable()
// 操作结果: 销毁散列表
{
	delete []ht;								// 释放ht
}

template <class ElemType, class KeyType>
void MyHashTable<ElemType, KeyType>::Traverse(void (*Visit)(const ElemType &)) const
// 操作结果: 依次对散列表的每个元素调用函数(*Visit)
{
	for (int pos = 0; pos < m; pos++)
	{	// 遍历散列表的每个链表
		ht[pos].Traverse(Visit);				// 遍历链表ht[pos]
	}
}

template <class ElemType, class KeyType>
bool MyHashTable<ElemType, KeyType>::Search(const KeyType &key, int &pos)
// 操作结果: 查找关键字为key的元素的位置,如果查找成功,返回true,并用pos指示待
//	查数据元素在散列表链表中的位置,否则返回false
{	
	int index = key % m;						// 散列表下标

	for (pos = 1; pos <= ht[index].Length(); pos++)
	{	// 查找链表ht[index]
		ElemType e;								// 链表元素
		ht[index].GetElem(pos, e);				// 取出元素
		if (e == key) return true;				// 查找成功 
	}
	return false;								// 查找失败
}

template <class ElemType, class KeyType>
bool MyHashTable<ElemType, KeyType>::Insert(const ElemType &e)
// 操作结果: 在散列表中插入数据元素e,插入成功返回true,否则返回false
{
	int pos;									// 插入位置
	int index = (KeyType)e % m;					// 散列表下标

	if (!Search(e, pos))
	{	// 插入成功
		ht[index].Insert(ht[index].Length() + 1, e);	// 插入元素
		return true;							// 插入成功
	}
	return false;								// 插入失败
}

template <class ElemType, class KeyType>
bool MyHashTable<ElemType, KeyType>::Delete(const KeyType &key)
// 操作结果: 删除关键字为key的数据元素,删除成功返回true,否则返回false
{
	int pos;									// 数据元素在链表中的位置
	int index = key % m;						// 散列表下标
	ElemType e;									// 链表元素
	
	if (Search(key, pos))
	{	// 删除成功
		ht[index].Delete(pos, e);				// 删除元素
		return true;							// 删除成功
	}
	return false;								// 删除失败
}

template <class ElemType, class KeyType>
MyHashTable<ElemType, KeyType>::MyHashTable(const MyHashTable<ElemType, KeyType> &copy)
// 操作结果：由散列表copy构造新散列表--复制构造函数
{
	m = copy.m;									// 散列表容量
	ht = new LinkList<ElemType>[m];				// 分配存储空间

	for (int pos = 0; pos < m; pos++)
	{	// 复制数据元素
		ht[pos] = copy.ht[pos];					// 复制链表
	}
}

template <class ElemType, class KeyType>
MyHashTable<ElemType, KeyType> &MyHashTable<ElemType, KeyType>::
operator=(const MyHashTable<ElemType, KeyType> &copy)
// 操作结果：将散列表copy赋值给当前散列表--赋值语句重载
{
	if (&copy != this)
	{	// 复制散列表
		delete []ht;							// 释放当前散列表存储空间
		m = copy.m;								// 散列表容量
		ht = new LinkList<ElemType>[m];			// 分配存储空间

		for (int pos = 0; pos < m; pos++)
		{	// 复制链表
			ht[pos] = copy.ht[pos];				// 复制链表
		}
	}
	return *this;
}

#endif