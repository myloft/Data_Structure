#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

#define LH 1								// ���
#define EH 0								// �ȸ�
#define RH -1								// �Ҹ�

// ����ƽ���������
template <class ElemType>
struct BinAVLTreeNode
{
// ���ݳ�Ա:
	ElemType data;							// ������
	int bf;									// ����ƽ������
	BinAVLTreeNode<ElemType> *leftChild;	// ����ָ����
	BinAVLTreeNode<ElemType> *rightChild;	// �Һ���ָ����

//	���캯��:
	BinAVLTreeNode();						// �޲����Ĺ��캯�� 
	BinAVLTreeNode(const ElemType &val,		// ��֪����Ԫ��ֵ,ƽ�����Ӻ�ָ�����Һ��ӵ�ָ�빹��һ�����
		int bFactor = 0,
		BinAVLTreeNode<ElemType> *lChild = NULL, 
		BinAVLTreeNode<ElemType> *rChild = NULL);
};

// ����ƽ����������ʵ�ֲ���
template <class ElemType>
BinAVLTreeNode<ElemType>::BinAVLTreeNode()
// �������������һ��Ҷ���
{
	bf = 0;							// ƽ������
	leftChild = rightChild = NULL;	// Ҷ������Һ���Ϊ��
}

template <class ElemType>
BinAVLTreeNode<ElemType>::BinAVLTreeNode(const ElemType &val, int bFactor, 
								   BinAVLTreeNode<ElemType> *lChild, 
								   BinAVLTreeNode<ElemType> *rChild)

// �������������һ��������Ϊval,ƽ������ΪbFactor,����ΪlChild,�Һ���ΪrChild�Ľ��
{	
	data = val;						// ����Ԫ��ֵ
	bf = bFactor;					// ƽ������
	leftChild = lChild;				// ����
	rightChild = rChild;			// �Һ���
}

#endif
