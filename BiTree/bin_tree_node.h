//2017.4.25 by iloft
template <class ElemType>
struct BinTreeNode
{
	// 数据成员:
	ElemType data;				   	// 数据域
	BinTreeNode<ElemType>  *leftChild;	// 左孩子
	BinTreeNode<ElemType>  *rightChild;	// 右孩子
};
