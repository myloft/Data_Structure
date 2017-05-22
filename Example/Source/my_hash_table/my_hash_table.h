// �ļ�·����: my_hash_table\my_hash_table.h
#ifndef __MY_HASH_TABLE_H__
#define __MY_HASH_TABLE_H__

#include "lk_list.h"							// ��������

// ɢ�б���
template <class ElemType, class KeyType>
class MyHashTable
{
protected:
//  ɢ�б�ĵ����ݳ�Ա:
	LinkList<ElemType> *ht;						// ɢ�б�
	int m;										// ɢ�б���

public:
//  �������������������ر���ϵͳĬ�Ϸ�������:
    MyHashTable(int size);						// ���캯��
    virtual ~MyHashTable();						// ���캯��
    void Traverse(void (*Visit)(const ElemType &)) const;	// ����ɢ�б�
	bool Search(const KeyType &key, int &pos);	// ���ҹؼ���Ϊkey��Ԫ�ص�λ��
	bool Insert(const ElemType &e);				// ����Ԫ��e
	bool Delete(const KeyType &key);			// ɾ���ؼ���Ϊkey��Ԫ��
    MyHashTable(const MyHashTable<ElemType, KeyType> &copy);// ���ƹ��캯��
    MyHashTable<ElemType, KeyType> &operator=
		(const MyHashTable<ElemType, KeyType> &copy);		// ��ֵ���������
};

// ɢ�б����ʵ�ֲ���
template <class ElemType, class KeyType>
MyHashTable<ElemType, KeyType>::MyHashTable(int size)
// �������: ��sizeΪɢ�б��ȹ���һ���յ�ɢ���
{
	m = size;									// ��ֵɢ�б�����
	ht = new LinkList<ElemType>[m];				// ����洢�ռ�
}

template <class ElemType, class KeyType>
MyHashTable<ElemType, KeyType>::~MyHashTable()
// �������: ����ɢ�б�
{
	delete []ht;								// �ͷ�ht
}

template <class ElemType, class KeyType>
void MyHashTable<ElemType, KeyType>::Traverse(void (*Visit)(const ElemType &)) const
// �������: ���ζ�ɢ�б��ÿ��Ԫ�ص��ú���(*Visit)
{
	for (int pos = 0; pos < m; pos++)
	{	// ����ɢ�б��ÿ������
		ht[pos].Traverse(Visit);				// ��������ht[pos]
	}
}

template <class ElemType, class KeyType>
bool MyHashTable<ElemType, KeyType>::Search(const KeyType &key, int &pos)
// �������: ���ҹؼ���Ϊkey��Ԫ�ص�λ��,������ҳɹ�,����true,����posָʾ��
//	������Ԫ����ɢ�б������е�λ��,���򷵻�false
{	
	int index = key % m;						// ɢ�б��±�

	for (pos = 1; pos <= ht[index].Length(); pos++)
	{	// ��������ht[index]
		ElemType e;								// ����Ԫ��
		ht[index].GetElem(pos, e);				// ȡ��Ԫ��
		if (e == key) return true;				// ���ҳɹ� 
	}
	return false;								// ����ʧ��
}

template <class ElemType, class KeyType>
bool MyHashTable<ElemType, KeyType>::Insert(const ElemType &e)
// �������: ��ɢ�б��в�������Ԫ��e,����ɹ�����true,���򷵻�false
{
	int pos;									// ����λ��
	int index = (KeyType)e % m;					// ɢ�б��±�

	if (!Search(e, pos))
	{	// ����ɹ�
		ht[index].Insert(ht[index].Length() + 1, e);	// ����Ԫ��
		return true;							// ����ɹ�
	}
	return false;								// ����ʧ��
}

template <class ElemType, class KeyType>
bool MyHashTable<ElemType, KeyType>::Delete(const KeyType &key)
// �������: ɾ���ؼ���Ϊkey������Ԫ��,ɾ���ɹ�����true,���򷵻�false
{
	int pos;									// ����Ԫ���������е�λ��
	int index = key % m;						// ɢ�б��±�
	ElemType e;									// ����Ԫ��
	
	if (Search(key, pos))
	{	// ɾ���ɹ�
		ht[index].Delete(pos, e);				// ɾ��Ԫ��
		return true;							// ɾ���ɹ�
	}
	return false;								// ɾ��ʧ��
}

template <class ElemType, class KeyType>
MyHashTable<ElemType, KeyType>::MyHashTable(const MyHashTable<ElemType, KeyType> &copy)
// �����������ɢ�б�copy������ɢ�б�--���ƹ��캯��
{
	m = copy.m;									// ɢ�б�����
	ht = new LinkList<ElemType>[m];				// ����洢�ռ�

	for (int pos = 0; pos < m; pos++)
	{	// ��������Ԫ��
		ht[pos] = copy.ht[pos];					// ��������
	}
}

template <class ElemType, class KeyType>
MyHashTable<ElemType, KeyType> &MyHashTable<ElemType, KeyType>::
operator=(const MyHashTable<ElemType, KeyType> &copy)
// �����������ɢ�б�copy��ֵ����ǰɢ�б�--��ֵ�������
{
	if (&copy != this)
	{	// ����ɢ�б�
		delete []ht;							// �ͷŵ�ǰɢ�б�洢�ռ�
		m = copy.m;								// ɢ�б�����
		ht = new LinkList<ElemType>[m];			// ����洢�ռ�

		for (int pos = 0; pos < m; pos++)
		{	// ��������
			ht[pos] = copy.ht[pos];				// ��������
		}
	}
	return *this;
}

#endif