// �ļ�·����: my_huffman_compress\my_huffman_tree.h 
#ifndef __MY_HUFFMAN_TREE_H__
#define __MY_HUFFMAN_TREE_H__

#include "min_priority_heap_queue.h"		// ��С���ȶѶ�����
#include "string.h"							// ����

// �����������ĳ������
template <class CharType, class WeightType>
class MyHuffNode 
{    
public:
// �����������ķ���:
	virtual WeightType Weight() = 0;		// ���ؽ���Ȩֵ
	virtual bool IsLeaf() = 0;				// �жϽ���Ƿ�ΪҶ���
	virtual MyHuffNode<CharType, WeightType> *Left() = 0;	// ���ؽ�������
	virtual MyHuffNode<CharType, WeightType> *Right() = 0;	// ���ؽ����Һ���
	virtual void SetLeft(MyHuffNode<CharType, WeightType> *child) = 0;
		// ���ý�������
	virtual void SetRight(MyHuffNode<CharType, WeightType> *child) = 0;
		// ���ý����Һ���
};





// �����������ĳ�����ศ���ṹ
template <class CharType, class WeightType>
struct MyHuffNodehelp
{
	MyHuffNode<CharType, WeightType> *ptr;	// �����������ĳ������ָ��
};





// ��������Ҷ���������
template <class CharType, class WeightType>
class MyLeafNode : public MyHuffNode<CharType, WeightType> 
{
private:
// ��������Ҷ�������������ݳ�Ա:
	CharType cha;							// Ҷ���������ַ�
	WeightType weight;						// Ȩֵ

public:
// ��������Ҷ��㷽�����������ر���ϵͳĬ�Ϸ�������:
	MyLeafNode(const CharType &ch, const WeightType &w);	// ���캯��
	virtual ~MyLeafNode(){}					// ��������			
	CharType Char();						// ����Ҷ�����ַ�
	WeightType Weight();					// ���ؽ���Ȩֵ
	bool IsLeaf();							// �жϽ���Ƿ�ΪҶ���
	MyHuffNode<CharType, WeightType> *Left();	// ���ؽ�������
	MyHuffNode<CharType, WeightType> *Right();	// ���ؽ����Һ���
	void SetLeft(MyHuffNode<CharType, WeightType> *child){}
		// ���ý�������
	void SetRight(MyHuffNode<CharType, WeightType> *child){}
		// ���ý����Һ���
};

// ��������Ҷ����������ʵ�ֲ���
template <class CharType, class WeightType>
MyLeafNode<CharType, WeightType>::MyLeafNode(const CharType &ch, const WeightType &w)
// �������: ���ַ�ch, Ȩֵch�����������Ҷ���
{
	cha = ch;								// �ַ�
	weight = w;								// Ȩֵ
}

template <class CharType, class WeightType>
CharType MyLeafNode<CharType, WeightType>::Char()
// �������: ����Ҷ�����ַ�
{
	return cha;								// �ַ�
}

template <class CharType, class WeightType>
WeightType MyLeafNode<CharType, WeightType>::Weight()
// �������: ���ؽ���Ȩֵ
{
	return weight;							// Ȩֵ
}

template <class CharType, class WeightType>
bool MyLeafNode<CharType, WeightType>::IsLeaf()
// �������: �жϽ���Ƿ�ΪҶ���
{
	return true;							// Ҷ���
}

template <class CharType, class WeightType>
MyHuffNode<CharType, WeightType> *MyLeafNode<CharType, WeightType>::Left()
// �������: ���ؽ�������
{
	return NULL;							// Ҷ����޺���
}

template <class CharType, class WeightType>
MyHuffNode<CharType, WeightType> *MyLeafNode<CharType, WeightType>::Right()
// �������: ���ؽ����Һ���
{
	return NULL;							// Ҷ����޺���
}




// ���������ڲ����������
template <class CharType, class WeightType>
class MyIntlNode : public MyHuffNode<CharType, WeightType> 
{
private:
// ��������Ҷ�������������ݳ�Ա:
	MyHuffNode<CharType, WeightType> *lChild;	// ����
	MyHuffNode<CharType, WeightType> *rChild;	// �Һ���
	WeightType weight;						// Ȩֵ

public:
// ���������ڲ���㷽�����������ر���ϵͳĬ�Ϸ�������:
	MyIntlNode(const WeightType &w, 
		MyHuffNode<CharType, WeightType> *lc, MyHuffNode<CharType, WeightType> *rc);
		// ���캯��
	virtual ~MyIntlNode(){}					// ��������			
	WeightType Weight();					// ���ؽ���Ȩֵ
	bool IsLeaf();							// �жϽ���Ƿ�ΪҶ���
	MyHuffNode<CharType, WeightType> *Left();	// ���ؽ�������
	MyHuffNode<CharType, WeightType> *Right();	// ���ؽ����Һ���
	void SetLeft(MyHuffNode<CharType, WeightType> *child);
		// ���ý�������
	void SetRight(MyHuffNode<CharType, WeightType> *child);
		// ���ý����Һ���
};

// ���������ڲ�����������ʵ�ֲ���
template <class CharType, class WeightType>
MyIntlNode<CharType, WeightType>::MyIntlNode(const WeightType &w, 
		MyHuffNode<CharType, WeightType> *lc, MyHuffNode<CharType, WeightType> *rc)
// �������: ��Ȩֵw, ����Ϊlc, �Һ���Ϊrc������������ڲ����
{
	weight = w;								// Ȩֵ
	lChild = lc;							// ����
	rChild = rc;							// �Һ���
}

template <class CharType, class WeightType>
WeightType MyIntlNode<CharType, WeightType>::Weight()
// �������: ���ؽ���Ȩֵ
{
	return weight;							// Ȩֵ
}

template <class CharType, class WeightType>
bool MyIntlNode<CharType, WeightType>::IsLeaf()
// �������: �жϽ���Ƿ�ΪҶ���
{
	return false;							// �ڲ����
}

template <class CharType, class WeightType>
MyHuffNode<CharType, WeightType> *MyIntlNode<CharType, WeightType>::Left()
// �������: ���ؽ�������
{
	return lChild;							// ����
}

template <class CharType, class WeightType>
MyHuffNode<CharType, WeightType> *MyIntlNode<CharType, WeightType>::Right()
// �������: ���ؽ����Һ���
{
	return rChild;							// �Һ���
}

template <class CharType, class WeightType>
void MyIntlNode<CharType, WeightType>::SetLeft(MyHuffNode<CharType, WeightType> *child)
// �������: ���ý�������
{
	lChild = child;							// ����
}

template <class CharType, class WeightType>
void MyIntlNode<CharType, WeightType>::SetRight(MyHuffNode<CharType, WeightType> *child)
// �������: ���ý����Һ���
{
	rChild = child;							// �Һ���
}




// ����������
template <class CharType, class WeightType>
class MyHuffmanTree
{
protected:
// �������������ݳ�Ա:
	MyHuffNode<CharType, WeightType> *root;		// ��
	String *charCodes;							// �ַ�������Ϣ
	MyHuffNode<CharType, WeightType> *pCurNode;	// ����ʱ�Ӹ���㵽Ҷ���·���ĵ�ǰ���
	int num;									// Ҷ������
	unsigned int (*CharIndex)(const CharType &);// �ַ�λ��ӳ��

// ��������:
	void CreatCode(MyHuffNode<CharType, WeightType> *r, char code[], int len = 0);
		// �����ַ�����
	void Clear(MyHuffNode<CharType, WeightType> *r);	// �ͷ���rΪ��������ռ�ÿռ�

public:
// ���������������������ر���ϵͳĬ�Ϸ�������:
	MyHuffmanTree(CharType ch[], WeightType w[], int n, unsigned int (*ChIndex)(const CharType &));
		// ���ַ�,Ȩֵ,�ַ��������ַ�λ��ӳ�乹���������
	virtual ~MyHuffmanTree();					// ��������
	String Encode(CharType ch);					// ����
	LinkList<CharType> Decode(String strCode);	// ����
};

// ��ϵ���������
template <class CharType, class WeightType>
bool operator <(const MyHuffNodehelp<CharType, WeightType> &first, const MyHuffNodehelp<CharType, WeightType> &second);
	// ���ع�ϵ�����<
template <class CharType, class WeightType>
bool operator >(const MyHuffNodehelp<CharType, WeightType> &first, const MyHuffNodehelp<CharType, WeightType> &second);
	// ���ع�ϵ�����>
template <class CharType, class WeightType>
bool operator <=(const MyHuffNodehelp<CharType, WeightType> &first, const MyHuffNodehelp<CharType, WeightType> &second);
	// ���ع�ϵ�����<=

// ���������༰��غ�����ʵ�ֲ���
template <class CharType, class WeightType>
bool operator <(const MyHuffNodehelp<CharType, WeightType> &first, 
	const MyHuffNodehelp<CharType, WeightType> &second)
// ������������ع�ϵ�����<
{
	return first.ptr->Weight() < second.ptr->Weight();	// �Ƚ�Ȩֵ
}

template <class CharType, class WeightType>
bool operator >(const MyHuffNodehelp<CharType, WeightType> &first, 
	const MyHuffNodehelp<CharType, WeightType> &second)
// ������������ع�ϵ�����>
{
	return first.ptr->Weight() > second.ptr->Weight();	// �Ƚ�Ȩֵ
}

template <class CharType, class WeightType>
bool operator <=(const MyHuffNodehelp<CharType, WeightType> &first, 
	const MyHuffNodehelp<CharType, WeightType> &second)
// ������������ع�ϵ�����<=
{
	return first.ptr->Weight() <= second.ptr->Weight();	// �Ƚ�Ȩֵ
}

template <class CharType, class WeightType>
void MyHuffmanTree<CharType, WeightType>::CreatCode(MyHuffNode<CharType, WeightType> *r, 
	char code[], int len)
// ��������������ַ�����
{
	if (r->IsLeaf())
	{	// ����Ҷ���
		CharType ch = ((MyLeafNode<CharType, WeightType> *)r)->Char();	// Ҷ�����ַ�
		code[len] = '\0';								// �ַ���������
		String strCode(code);							// ���봮
		charCodes[(*CharIndex)(ch)] = strCode;			// ���ַ��������charCodes
	}
	else
	{	// �ڲ����
		code[len] = '0';								// ���֧����Ϊ'0' 
		CreatCode(r->Left(), code, len + 1);			// �����֧����

		code[len] = '1';								// ���֧����Ϊ'1' 
		CreatCode(r->Right(), code, len + 1);			// ���ҷ�֧����
	}
}

template <class CharType, class WeightType>
MyHuffmanTree<CharType, WeightType>::MyHuffmanTree(CharType ch[], WeightType w[], int n, 
	unsigned int (*ChIndex)(const CharType &))
// ������������ַ�,Ȩֵ���ַ����������������
{
	CharIndex = ChIndex;			// �ַ�λ��ӳ��
	num = n;						// Ҷ������
	charCodes = new String[num];	// �ַ�������Ϣ
	MinPriorityHeapQueue<MyHuffNodehelp<CharType, WeightType> > minHeap;	// С����
	int i;							// ��ʱ����
	
	for (i = 0; i < num; i++)
	{	// ����ɭ��
		MyHuffNodehelp<CharType, WeightType> tem;		// �����������ĳ�����ศ���ṹ����
		tem.ptr = new MyLeafNode<CharType, WeightType>(ch[i], w[i]);
		minHeap.InQueue(tem);
			// ɭ����ÿ����Ϊֻ��һ�����Ķ�����
	}

	for (i = 0; i < num - 1; i++)
	{	// ������������
		MyHuffNodehelp<CharType, WeightType> r, r1, r2;	// ��ʱ����
		minHeap.OutQueue(r1);		// ��1�ö�����
		minHeap.OutQueue(r2);		// ��2�ö�����
		r.ptr = new MyIntlNode<CharType, WeightType>(r1.ptr->Weight() + r2.ptr->Weight(),
			r1.ptr, r2.ptr);		// �ϲ�r1��r2��r
		minHeap.InQueue(r);			// ���
	}
	
	MyHuffNodehelp<CharType, WeightType> rt;			// ��ʱ����
	minHeap.OutQueue(rt);			// ɭ���еĶ�����Ϊ�����Huffman��
	root = rt.ptr;					// ɭ���еĶ�����Ϊ�����Huffman��
	pCurNode = root;				// ����ʱ�Ӹ���㿪ʼ
	char *code = new char[num];		// �ַ�������Ϣ
	CreatCode(root, code);			// �����ַ�����
	delete []code;					// �ͷŴ洢�ռ�
}

template <class CharType, class WeightType>
void MyHuffmanTree<CharType, WeightType>::Clear(MyHuffNode<CharType, WeightType> *r)
// ����������ͷ���rΪ��������ռ�ÿռ�
{
	if (r != NULL)
	{
		Clear(r->Left());			// �ͷ�������
		Clear(r->Right());			// �ͷ�������
		delete r;					// �ͷŸ����
	}
}

template <class CharType, class WeightType>
MyHuffmanTree<CharType, WeightType>::~MyHuffmanTree()
// ������������ٹ�������
{	
	Clear(root);					// �ͷ���rootΪ�������Ľ����ռ�ÿռ�
}

template <class CharType, class WeightType>
String MyHuffmanTree<CharType, WeightType>::Encode(CharType ch)
// ��������������ַ�����
{
	return charCodes[(*CharIndex)(ch)];	// �����ַ�����
}

template <class CharType, class WeightType>
LinkList<CharType> MyHuffmanTree<CharType, WeightType>::Decode(String strCode)
// ����������Ա��봮strCode��������,���ر���ǰ���ַ�����
{
	LinkList<CharType> charList;						// ����ǰ���ַ�����
	
	for (int pos = 0; pos < strCode.Length(); pos++)
	{	// ����ÿλ����
		if (strCode[pos] == '0') pCurNode = pCurNode->Left();	// '0'��ʾ���֧	
		else pCurNode = pCurNode->Right();				// '1'��ʾ���֧	

		if (pCurNode->IsLeaf())
		{	// ����ʱ�Ӹ���㵽Ҷ���·���ĵ�ǰ���ΪҶ���
			charList.Insert(charList.Length() + 1, 
				((MyLeafNode<CharType, WeightType> *)pCurNode)->Char());
			pCurNode = root;							// pCurNode�ع�����
		}
	}
	return charList;									// ���ر���ǰ���ַ�����
}

#endif