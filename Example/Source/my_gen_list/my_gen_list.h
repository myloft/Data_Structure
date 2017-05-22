// �ļ�·����:my_gen_list\my_gen_list.h
#ifndef __MY_GEN_LIST_H__
#define __MY_GEN_LIST_H__

#include "my_use_space_list.h"				// �����ʹ�ÿռ����
#include "my_gen_node.h"					// ���������

// �������
template<class ElemType>
class MyGenList
{
protected:
// �����������ݳ�Ա:
	MyGenListNode<ElemType> *head;			// �����ͷָ��
	
// ��������
	void ShowHelp(MyGenListNode<ElemType> *hd) const;	
		// ��ʾ��hdΪͷ���Ĺ����
	int DepthHelp(const MyGenListNode<ElemType> *hd);	
		// ������hdΪ��ͷ�Ĺ��������
	void ClearHelp(MyGenListNode<ElemType> *hd);		
		// �ͷ���hdΪ��ͷ�Ĺ����ṹ
	void CopyHelp(const MyGenListNode<ElemType> *sourceHead, 
		 MyGenListNode<ElemType> *&destHead);	
		// ����destHeadΪͷ���Ĺ�����Ƴ���sourceHeadΪͷ���Ĺ����
	void CreateHelp(MyGenListNode<ElemType> *&first);
		// ������firstΪͷ���Ĺ����

public:
// �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	MyGenList();							// �޲����Ĺ��캯��
	MyGenList(MyGenListNode<ElemType> *hd);	// ��ͷ���ָ�빹������
	~MyGenList();							// ��������
	MyGenListNode<ElemType> *First() const;	// ���ع����ĵ�һ��Ԫ��
	MyGenListNode<ElemType> *Next(MyGenListNode<ElemType> *elemPtr) const;	                                                                               
		// ����elemPtrָ��Ĺ����Ԫ�صĺ��
	bool Empty() const;						// �жϹ�����Ƿ�Ϊ��
	void Push(const ElemType &e);			// ��ԭ��Ԫ��e��Ϊ��ͷ���뵽�������ǰ��
	void Push(MyGenList<ElemType> &subList);	
		// ���ӱ�subList��Ϊ��ͷ���뵽�������ǰ��
	int Depth();							// �����������
	MyGenList(const MyGenList<ElemType> &copy);	// ���ƹ��캯��
	MyGenList<ElemType> &operator =(const MyGenList<ElemType> &copy);// ��ֵ�������
	void Input(void);						// ��������	
	void Show(void);						// ��ʾ�����	
};

// ��������ʵ�ֲ���
template <class ElemType>
MyGenList<ElemType>::MyGenList()
// �������������һ���չ����
{
	head = new MyGenListNode<ElemType>(HEAD);
	head->ref = 1;							// ������
}

template <class ElemType>
MyGenList<ElemType>::MyGenList(MyGenListNode<ElemType> *hd)
// �����������ͷ���ָ�빹������
{
	head = hd;								// ͷ���
}

template <class ElemType>
MyGenListNode<ElemType> *MyGenList<ElemType>::First() const
// ������������ع����ĵ�һ��Ԫ��
{
	return head->nextLink;
}

template <class ElemType>
MyGenListNode<ElemType> *MyGenList<ElemType>::Next(MyGenListNode<ElemType> *elemPtr) const
// �������������elemPtrָ��Ĺ����Ԫ�صĺ��
{
	return elemPtr->nextLink;
}

template <class ElemType>
bool MyGenList<ElemType>::Empty() const
// ���������������Ϊ�գ��򷵻�true�����򷵻�false
{
	return head->nextLink == NULL;
}

template <class ElemType>
void MyGenList<ElemType>::Push(const ElemType &e)
// �����������ԭ��Ԫ��e��Ϊ��ͷ���뵽�������ǰ��
{
	MyGenListNode<ElemType> *tmpPtr = new MyGenListNode<ElemType>(ATOM, head->nextLink);
	tmpPtr->atom = e;					// ������
	head->nextLink = tmpPtr;			// ��tmpPtr������head��head->nextLink֮�� 
}

template <class ElemType>
void MyGenList<ElemType>::Push(MyGenList<ElemType> &subList)
// ������������ӱ�subList��Ϊ��ͷ���뵽�������ǰ��
{
	MyGenListNode<ElemType> *tmpPtr = new MyGenListNode<ElemType>(LIST, head->nextLink);
	tmpPtr->subLink = subList.head;		// �ӱ�
	subList.head->ref++;				// subList�������Լ�1
	head->nextLink = tmpPtr;			// ��tmpPtr������head��head->nextLink֮�� 
}

template <class ElemType>
void MyGenList<ElemType>::ShowHelp(MyGenListNode<ElemType> *hd) const
// �����������ʾ��hdΪͷ���Ĺ����
{
	bool frist = true;
	cout << "(";						// �������(��ʼ
	for (MyGenListNode<ElemType> *tmpPtr = hd->nextLink; tmpPtr != NULL; 
		tmpPtr = tmpPtr->nextLink)
	{	// ���δ��������Ԫ�� 
		if (frist) frist = false;		// ��һ��Ԫ��
		else cout << ",";				// ��ͬԪ������ö��Ÿ���
		if (tmpPtr->tag == ATOM)
		{	// ԭ�ӽ��
			cout << tmpPtr->atom;
		}
		else
		{	// ����
			ShowHelp(tmpPtr->subLink);
		}
	}
	cout << ")";						// �������)����
}

template <class ElemType>
void MyGenList<ElemType>::Show(void)
// �����������ʾ�����	
{
	ShowHelp(head);						// ���ø���������ʾ�����
}


template <class ElemType>
int MyGenList<ElemType>::DepthHelp(const MyGenListNode<ElemType> *hd)
// ���������������hdΪ��ͷ�Ĺ��������
{
	if (hd->nextLink == NULL) return 1;// �չ��������Ϊ1
	
	int subMaxDepth = 0;				// �ӱ�������
	for (MyGenListNode<ElemType> *tmpPtr = hd->nextLink; tmpPtr != NULL; 
		tmpPtr = tmpPtr->nextLink)
	{	// ���ӱ��������
		if (tmpPtr->tag == LIST)
		{	// �ӱ�
			int curSubDepth = DepthHelp(tmpPtr->subLink);	// �ӱ����
			if (subMaxDepth < curSubDepth) subMaxDepth = curSubDepth;
		}
	}
	return subMaxDepth + 1;				// ��������Ϊ�ӱ������ȼ�1
}

template <class ElemType>
int MyGenList<ElemType>::Depth()
// ������������ع�������
{
	return DepthHelp(head);
}

template <class ElemType>
void MyGenList<ElemType>::ClearHelp(MyGenListNode<ElemType> *hd)
// ����������ͷ���hdΪ��ͷ�Ĺ����ṹ
{
	hd->ref--;								// �������Լ�1
	
	if (hd->ref == 0)
	{	// ������Ϊ0,�ͷŽ����ռ�ÿռ�
		MyGenListNode<ElemType> *tmpPre, *tmpPtr;	// ��ʱ���� 
		for (tmpPre = hd, tmpPtr = hd->nextLink; 
			tmpPtr != NULL; tmpPre = tmpPtr, tmpPtr = tmpPtr->nextLink)
		{	// ɨ������hd�Ķ���
			gMyUseSpaceList.Delete(tmpPre);	// �ͷ�tmpPre
			if (tmpPtr->tag == LIST)
			{	// tmpPtrΪ�ӱ�
				ClearHelp(tmpPtr->subLink);	// �ͷ��ӱ�
			}
		}
		gMyUseSpaceList.Delete(tmpPre);		// �ͷ�β���tmpPre
	}
}

template <class ElemType>
MyGenList<ElemType>::~MyGenList()
// ����������ͷŹ����ṹ������������
{
	ClearHelp(head);
}

template <class ElemType>
void MyGenList<ElemType>::CopyHelp(const MyGenListNode<ElemType> *sourceHead, 
	MyGenListNode<ElemType> *&destHead)	
// ��ʼ����: ��sourceHeadΪͷ���Ĺ����Ϊ�ǵݹ�����
// �������: ����sourceHeadΪͷ���Ĺ�����Ƴ���destHeadΪͷ����
//	�����
{
	destHead = new MyGenListNode<ElemType>(HEAD);		// ����ͷ���
	MyGenListNode<ElemType> *destPtr = destHead;		// destHead�ĵ�ǰ���
	destHead->ref = 1;									// ������Ϊ1
	for (MyGenListNode<ElemType> *tmpPtr = sourceHead->nextLink; tmpPtr != NULL; 
		tmpPtr = tmpPtr->nextLink)
	{	// ɨ������sourceHead�Ķ���
		destPtr = destPtr->nextLink = new MyGenListNode<ElemType>(tmpPtr->tag);	
			// �����½��
		if (tmpPtr->tag == LIST)
		{	// �ӱ�
			CopyHelp(tmpPtr->subLink, destPtr->subLink);// �����ӱ�
		}
		else
		{	// ԭ�ӽ��
			destPtr->atom = tmpPtr->atom;				// ����ԭ�ӽ��
		}
	}
}

template <class ElemType>
MyGenList<ElemType>::MyGenList(const MyGenList<ElemType> &copy)
// ����������ɹ����copy�����¹����--���ƹ��캯��
{
	CopyHelp(copy.head, head);
}

template<class ElemType>
MyGenList<ElemType> &MyGenList<ElemType>::operator =(const MyGenList<ElemType> &copy)
// ����������������copy��ֵ����ǰ�����--��ֵ�������
{
	if (&copy != this)
	{
		ClearHelp(head);				// ��յ�ǰ�����
		CopyHelp(copy.head, head);		// ���ƹ����
	}
	return *this;
}

template<class ElemType>
void MyGenList<ElemType>::CreateHelp(MyGenListNode<ElemType> *&first)
// ���������������firstΪͷ���Ĺ����
{
	char ch = GetChar();					// �����ַ�
	switch (ch)
	{
	case ')':								// ����������
		return;								// ����
	case '(':								// �ӱ�
		// ��ͷΪ�ӱ�
		first = new MyGenListNode<ElemType>(LIST);// ���ɱ���
		
		MyGenListNode<ElemType> *subHead;	// �ӱ�ָ��
		subHead = new MyGenListNode<ElemType>(HEAD);// �����ӱ��ͷ���
		subHead->ref = 1;					// ������Ϊ1	
		first->subLink = subHead;			// subHeadΪ�ӱ�
		CreateHelp(subHead->nextLink);		// �ݹ齨���ӱ�
		
		ch = GetChar();						// ����','
		if (ch != ',') cin.putback(ch);		// �粻��','����ch���˵�������
		CreateHelp(first->nextLink);		// �����������һ���
		break;
	default:								// ԭ��
		// ��ͷΪԭ��
		cin.putback(ch);					// ��ch���˵�������
		ElemType amData;					// ԭ�ӽ������
		cin >> amData;						// ����ԭ�ӽ������
		first = new MyGenListNode<ElemType>(ATOM);// ����ԭ����
		first->atom = amData;				// ԭ�ӽ������
		
		ch = GetChar();						// ����','
		if (ch != ',') cin.putback(ch);		// �粻��','����ch���˵�������
		CreateHelp(first->nextLink);		// �����������һ���
		break;
	}
}

template<class ElemType>
void MyGenList<ElemType>::Input(void)
// �����������������
{
	head = new MyGenListNode<ElemType>(HEAD);	// ���ɹ����ͷ���
	head->ref = 1;								// ������Ϊ1
	
	GetChar();									// �����һ��'('
	MyGenList<ElemType>::CreateHelp(head->nextLink);
		// ������head->nextLinkΪ��ͷ�Ĺ����
}

#endif
