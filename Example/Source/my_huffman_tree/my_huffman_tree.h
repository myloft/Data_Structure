// �ļ�·����:my_huffman_tree\my_huffman_tree.h
#ifndef __MY_HUFFMAN_TREE_H__
#define __MY_HUFFMAN_TREE_H__

#include "string.h"								// ����
#include "huffman_tree_node.h"					// �������������

// ����������
template <class CharType, class WeightType>
class MyHuffmanTree
{
protected:
//  �������������ݳ�Ա:
	HuffmanTreeNode<WeightType> *nodes;			// �洢�����Ϣ,nodes[0]δ��
	CharType *LeafChars;						// Ҷ����ַ���Ϣ,LeafChars[0]δ��
	String *LeafCharCodes;						// Ҷ����ַ�������Ϣ,LeafCharCodes[0]δ��
	int curPos;									// ����ʱ�Ӹ���㵽Ҷ���·���ĵ�ǰ���
	int num;									// Ҷ������
	unsigned int (*CharIndex)(const CharType &);// �ַ�λ��ӳ��

//	��������:
	void Select(int cur, int &r1, int &r2);		// nodes[1 ~ cur]��ѡ��˫��Ϊ0,Ȩֵ��С���������r1,r2
	void CreatMyHuffmanTree(CharType ch[], WeightType w[], int n);
		// ���ַ�,Ȩֵ���ַ��������ַ�λ��ӳ�乹���������

public:
//  ���������������������ر���ϵͳĬ�Ϸ�������:
	MyHuffmanTree(CharType ch[], WeightType w[], int n, unsigned int (*ChIndex)(const CharType &));	
		// ���ַ�,Ȩֵ���ַ����������������
	virtual ~MyHuffmanTree();					// ��������
	String Encode(CharType ch);					// ����
	LinkList<CharType> Decode(String strCode);	// ����
	MyHuffmanTree(const MyHuffmanTree<CharType, WeightType> &copy);	// ���ƹ��캯��
	MyHuffmanTree<CharType, WeightType> &operator=(const MyHuffmanTree<CharType, 
		WeightType>& copy);						// ��ֵ���������
};

// �����ֵܱ�ʾ�����������ʵ�ֲ���
template <class CharType, class WeightType>
void MyHuffmanTree<CharType, WeightType>::Select(int cur, int &r1, int &r2)
// ���������nodes[1 ~ cur]��ѡ��˫��Ϊ0,Ȩֵ��С���������r1,r2
{
	r1 = r2 = 0;								// 0��ʾ�ս��
	for (int pos = 1; pos <= cur; pos++)
	{	// ����Ȩֵ��С���������
		if (nodes[pos].parent != 0) continue;	// ֻ����˫�ײ�Ϊ0�Ľ��
		if (r1 == 0)
		{	// r1Ϊ��,��pos��ֵ��r1
			r1 = pos;
		}
		else if (r2 == 0)
		{	// r2Ϊ��,��pos��ֵ��r2
			r2 = pos;
		}
		else if	(nodes[pos].weight < nodes[r1].weight)
		{	// nodes[pos]Ȩֵ��nodes[r1]��С,��pos��Ϊr1
			r1 = pos;
		}
		else if (nodes[pos].weight < nodes[r2].weight)
		{	// nodes[pos]Ȩֵ��nodes[r2]��С,��pos��Ϊr2
			r2 = pos;
		}
	}
}

template <class CharType, class WeightType>
void MyHuffmanTree<CharType, WeightType>::CreatMyHuffmanTree(CharType ch[], 
	WeightType w[], int n)
// ������������ַ�,Ȩֵ���ַ����������������
{
	num = n;									// Ҷ������
	int m = 2 * n - 1;							// ������

	nodes = new HuffmanTreeNode<WeightType>[m + 1];	// nodes[0]δ��
	LeafChars = new CharType[n + 1];			// LeafChars[0]δ��
	LeafCharCodes = new String[n + 1];			// LeafCharCodes[0]δ��

	int pos;									// ��ʱ���� 
	for (pos = 1; pos <= n; pos++)
	{	// �洢Ҷ�����Ϣ
		nodes[pos].weight = w[pos - 1];			// Ȩֵ
		LeafChars[pos] = ch[pos - 1];			// �ַ�
	}

	for (pos = n + 1; pos <= m; pos++)
	{	// ������������
		int r1, r2;
		Select(pos - 1, r1, r2);	// nodes[1 ~ pos - 1]��ѡ��˫��Ϊ0,Ȩֵ��С���������r1,r2

		// �ϲ���r1,r2Ϊ������
		nodes[r1].parent = nodes[r2].parent = pos;	// r1,r2˫��Ϊpos
		nodes[pos].leftChild = r1;					// r1Ϊpos������
		nodes[pos].rightChild = r2;					// r2Ϊpos���Һ���
		nodes[pos].weight = nodes[r1].weight + nodes[r2].weight;//pos��ȨΪr1,r2��Ȩֵ֮��
	}

	for (pos = 1; pos <= n; pos++)
	{	// ��n��Ҷ����ַ��ı���
		LinkList<char> charCode;			// �ݴ�Ҷ����ַ�������Ϣ
		for (unsigned int child = pos, parent = nodes[child].parent; parent != 0; 
			child = parent, parent = nodes[child].parent)
		{	// ��Ҷ��㵽��������������
			if (nodes[parent].leftChild == child) charCode.Insert(1, '0');// ���֧����Ϊ'0'
			else charCode.Insert(1, '1');	// �ҷ�֧����Ϊ'1'
		}
		LeafCharCodes[pos] = charCode;		// charCode�д洢�ַ�����
	}
	
	curPos = m;								// ����ʱ�Ӹ���㿪ʼ,mΪ��
}

template <class CharType, class WeightType>
MyHuffmanTree<CharType, WeightType>::MyHuffmanTree(CharType ch[], WeightType w[], int n, 
	unsigned int (*ChIndex)(const CharType &))
// ������������ַ�,Ȩֵ���ַ��������ַ�λ��ӳ�乹���������
{
	CharIndex = ChIndex;					// �ַ�λ��ӳ��
	CreatMyHuffmanTree(ch, w, n);			// ���ַ�,Ȩֵ���ַ����������������
}

template <class CharType, class WeightType>
MyHuffmanTree<CharType, WeightType>::~MyHuffmanTree()
// ������������ٹ�������
{	
	if (nodes != NULL) delete []nodes;					// �ͷŽ����Ϣ
	if (LeafChars != NULL) delete []LeafChars;			// �ͷ�Ҷ����ַ���Ϣ
	if (LeafCharCodes != NULL) delete []LeafCharCodes;	// �ͷ�Ҷ����ַ�������Ϣ
}

template <class CharType, class WeightType>
String MyHuffmanTree<CharType, WeightType>::Encode(CharType ch)
// ��������������ַ�����
{
	return LeafCharCodes[(*CharIndex)(ch)];				// �����ַ�����
}

template <class CharType, class WeightType>
LinkList<CharType> MyHuffmanTree<CharType, WeightType>::Decode(String strCode)
// ����������Ա��봮strCode��������,���ر���ǰ���ַ�����
{
	LinkList<CharType> charList;						// ����ǰ���ַ�����
	
	for (int pos = 0; pos < strCode.Length(); pos++)
	{	// ����ÿλ����
		if (strCode[pos] == '0') curPos = nodes[curPos].leftChild;	// '0'��ʾ���֧	
		else curPos = nodes[curPos].rightChild;			// '1'��ʾ���֧	

		if (nodes[curPos].leftChild == 0 && nodes[curPos].rightChild == 0)
		{	// ����ʱ�Ӹ���㵽Ҷ���·���ĵ�ǰ���ΪҶ���
			charList.Insert(charList.Length() + 1, LeafChars[curPos]);
			curPos = 2 * num - 1;						// curPos�ع�����
		}
	}
	return charList;									// ���ر���ǰ���ַ�����
}

template <class CharType, class WeightType>
MyHuffmanTree<CharType, WeightType>::MyHuffmanTree(
	const MyHuffmanTree<CharType, WeightType> &copy)
// ����������ɹ�������copy�����¹��������������ƹ��캯��
{
	num = copy.num;									// Ҷ������
	curPos = copy.curPos;							// ����ʱ�Ӹ���㵽Ҷ���·���ĵ�ǰ���
	int m = 2 * num - 1;							// ������� 
	nodes = new HuffmanTreeNode<WeightType>[m + 1];	// nodes[0]δ��
	LeafChars = new CharType[num + 1];				// LeafChars[0]δ��
	LeafCharCodes = new String[num + 1];			// LeafCharCodes[0]δ��
	CharIndex = copy.CharIndex;						// �ַ�λ��ӳ��

	int pos;										// ��ʱ���� 
	for (pos = 1; pos <= m; pos++)
	{	// ���ƽ����Ϣ
		nodes[pos] = copy.nodes[pos];				// �����Ϣ
	}
	
	for (pos = 1; pos <= num; pos++)
	{	// ����Ҷ����ַ���Ϣ��Ҷ����ַ�������Ϣ
		LeafChars[pos] = copy.LeafChars[pos];		// Ҷ����ַ���Ϣ
		LeafCharCodes[pos] = copy.LeafCharCodes[pos];// Ҷ����ַ�������Ϣ
	}
}

template <class CharType, class WeightType>
MyHuffmanTree<CharType, WeightType> &MyHuffmanTree<CharType, WeightType>::operator=(
	const MyHuffmanTree<CharType, WeightType>& copy)	
// �������������������copy��ֵ����ǰ��������������ֵ���������
{
	if (&copy != this)
	{
		if (nodes != NULL) delete []nodes;					// �ͷŽ����Ϣ
		if (LeafChars != NULL) delete []LeafChars;			// �ͷ�Ҷ����ַ���Ϣ
		if (LeafCharCodes != NULL) delete []LeafCharCodes;	// �ͷ�Ҷ����ַ�������Ϣ

		num = copy.num;						// Ҷ������
		curPos = copy.curPos;				// ����ʱ�Ӹ���㵽Ҷ���·���ĵ�ǰ���
		int m = 2 * num - 1;				// ������� 
		nodes = new HuffmanTreeNode<WeightType>[m + 1];	// nodes[0]δ��
		LeafChars = new CharType[num + 1];				// LeafChars[0]δ��
		LeafCharCodes = new String[num + 1];			// LeafCharCodes[0]δ��
		CharIndex = copy.CharIndex;						// �ַ�λ��ӳ��

		int pos;										// ��ʱ���� 
		for (pos = 1; pos <= m; pos++)
		{	// ���ƽ����Ϣ
			nodes[pos] = copy.nodes[pos];				// �����Ϣ
		}
		
		for (pos = 1; pos <= num; pos++)
		{	// ����Ҷ����ַ���Ϣ��Ҷ����ַ�������Ϣ
			LeafChars[pos] = copy.LeafChars[pos];		// Ҷ����ַ���Ϣ
			LeafCharCodes[pos] = copy.LeafCharCodes[pos];// Ҷ����ַ�������Ϣ
		}	
	}
	return *this;
}

#endif
