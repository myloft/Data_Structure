//2017.4.25 by iloft
#ifndef __BINNARY_TREE_H__
#define __BINNARY_TREE_H__
#include "bin_tree_node.h"
#include "lk_queue.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// 二叉树类模板
template <class ElemType>
class BinaryTree
{
private:
	//  二叉树的数据成员:
	BinTreeNode<ElemType> *root;
	//  二叉树的私有函数:			
	void PreOrderHelp(BinTreeNode<ElemType> *r);	// 先序遍历
	void InOrderHelp(BinTreeNode<ElemType> *r);	// 中序遍历
	void PostOrderHelp(BinTreeNode<ElemType> *r);// 后序遍历
	void Creat(BinTreeNode<ElemType> *r,
	int flag, ElemType empty, ElemType end);
	//递归创建子树
	BinTreeNode<ElemType> *GetRoot();   //返回根指针
	BinTreeNode<ElemType> *Locate(BinTreeNode<ElemType> *r, ElemType e);  //查找元素值为e的结点,返回指针.
	BinTreeNode<ElemType>* LeftChild(ElemType e);
	//定位指定元素的左孩子，返回其指针。
	BinTreeNode<ElemType>* Parent(BinTreeNode<ElemType>*r, ElemType e); //定位指定元素的父结点
	BinTreeNode<ElemType>* LeftSibling(ElemType e);
	//定位指定元素的左兄弟
	int Size(BinTreeNode<ElemType> *r);
	int Depth(BinTreeNode<ElemType> *r);
	int Leaf(BinTreeNode<ElemType> *r); //统计并返回叶子结点个数
	void Clear(BinTreeNode<ElemType> *r);
	void DisplayTreeeHelp(BinTreeNode<ElemType> *r, int level);
	// 按树状形式显示以r为根的二叉树，level为层次数，可设根结点的层次数为1
	int size;
public:
	//  二叉树公共方法声明:
	BinaryTree();											// 无参数的构造函数模板
	void CreateBiTree();// 构造二叉树
	//BinTreeNode<ElemType> *GetRoot();					// 返回二叉树的根
	void InOrder();	// 二叉树的中序遍历	
	void PreOrder();	// 二叉树的先序遍历
	void PostOrder();	// 二叉树的后序遍历
	void LevelOrder();    //按层遍历
	int Locate(ElemType e);  //查找元素值为e的结点。
	int GetLeft(ElemType e, ElemType &c);
	//读取指定元素的左孩子
	int GetParent(ElemType e, ElemType &f);
	//读取指定元素的父元素
	int GetLeftSibling(ElemType e, ElemType &s);
	//读取指定元素的左兄弟
	int InsertChild(ElemType e, ElemType x, ElemType y);
	//为指定元素 e 插入左、右孩子
	int SetElem(ElemType  e, ElemType  x);
	//更新指定元素
	int Size();
	int Depth();
	int Leaf(); //统计并返回叶子结点个数
	virtual ~BinaryTree();// 销毁二叉树
	void DisplayTree();
};
template <class ElemType>
void BinaryTree<ElemType>::PreOrderHelp(
	BinTreeNode<ElemType> *r)     // private
{
	if (r != NULL)
	{
		cout << r->data << " ";              // 访问根结点
		PreOrderHelp(r->leftChild);      // 遍历左子树
		PreOrderHelp(r->rightChild);   // 遍历右子树
	}
}
template <class ElemType>
void BinaryTree<ElemType>::PreOrder()     // public
{
	PreOrderHelp(root);
}
template <class ElemType>
void BinaryTree<ElemType>::InOrderHelp(
	BinTreeNode<ElemType> *r)     // private
{
	if (r != NULL)
	{
		InOrderHelp(r->leftChild);         // 遍历左子树
		cout << r->data << "  ";                    // 访问根结点
		InOrderHelp(r->rightChild);      // 遍历右子树
	}
}
template <class ElemType>
void BinaryTree<ElemType>::InOrder()      // public
{
	InOrderHelp(root);
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrderHelp(
	BinTreeNode<ElemType> *r)           // private
{
	if (r != NULL)
	{
		PostOrderHelp(r->leftChild);       // 遍历左子树
		PostOrderHelp(r->rightChild);   // 遍历右子树    
		cout << r->data << "  ";                    // 访问根结点
	}
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrder()     // public
{
	PostOrderHelp(root);
}
template <class ElemType>
void BinaryTree<ElemType>::LevelOrder()
{
	LinkQueue<BinTreeNode<ElemType> *> q;
	BinTreeNode<ElemType> *t = root;
	if (t != NULL) q.InQueue(t);	// 如果根非空,则入队
	while (!q.Empty())
	{
		q.OutQueue(t);
		cout << t->data << "  ";      // 
		if (t->leftChild != NULL)	  // 左孩子非空
			q.InQueue(t->leftChild);  // 左孩子入队
		if (t->rightChild != NULL)	  // 右孩子非空
			q.InQueue(t->rightChild); // 右孩子入队
	}
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
	root = NULL;
}
template <class ElemType>
void BinaryTree<ElemType>::CreateBiTree()
{
	BinTreeNode<ElemType>* r;
	ElemType end, empty, x;
	cout << "按先序序列的顺序输入一棵二叉树" << endl;
	cout << "输入的结束标志是：";
	cin >> end;
	cout << "输入的空结点标志是：";
	cin >> empty;
	cout << "请开始输入：" << endl;
	cin >> x;
	r = new BinTreeNode<ElemType>;
	r->data = x;
	r->leftChild = r->rightChild = NULL;
	root = r;
	Creat(r, 0, empty, end);   //创建根结点的左子树
	Creat(r, 1, empty, end);   //创建根结点的右子树
}
template <class ElemType>
void BinaryTree<ElemType>::Creat(BinTreeNode<ElemType> *r,int flag, ElemType empty, ElemType end)
{
	BinTreeNode<ElemType> *p;  ElemType x;
	cin >> x;
	if (x != end&&x != empty)
	{
		p = new BinTreeNode<ElemType>; p->data = x;
		p->leftChild = p->rightChild = NULL;
		if (flag == 0) r->leftChild = p;  //p为左子树
		else r->rightChild = p;       //p为右子树
		size++;
		Creat(p, 0, empty, end);           //递归创建左子树
		Creat(p, 1, empty, end);           //递归创建右子树
	}
}
template <class ElemType>
BinTreeNode<ElemType>*BinaryTree<ElemType>::GetRoot()
{
	return root;
}
template <class ElemType>
BinTreeNode<ElemType>*BinaryTree<ElemType>::
Locate(BinTreeNode<ElemType> *r, ElemType e) //private
{
	if (r == NULL)     return  NULL;
	if (r->data == e)     return r;
	BinTreeNode<ElemType> *p = Locate(r->leftChild, e);
	if (p == NULL)    p = Locate(r->rightChild, e);
	return p;
}
template <class ElemType>
int BinaryTree<ElemType>::Locate(ElemType  e) //public
{
	if (Locate(root, e) == NULL)
		return false;
	else
		return true;
}
template <class ElemType>
BinTreeNode<ElemType>*BinaryTree<ElemType>
::LeftChild(ElemType e)  //private 　
{
	BinTreeNode<ElemType>* ep = Locate(root, e);
	if (ep == NULL) return NULL; //找不到结点e
    if (ep->leftChild == NULL)  //e无左孩子
		return NULL;
	return ep->leftChild;      //返回e左孩子的指针
}
template <class ElemType>
int BinaryTree<ElemType>::GetLeft(ElemType e, ElemType &c)       //Public
{
	BinTreeNode<ElemType>* p = LeftChild(e);
	if (p == NULL) return false;	//e无左孩子
	c = p->data;
	return true;
}
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(BinTreeNode<ElemType>*r, ElemType e) //private
{
	BinTreeNode<ElemType>* p;
	if (r == NULL)return NULL;
	if ((r->leftChild != NULL&&r->leftChild->data == e) ||
		(r->rightChild != NULL&&r->rightChild->data == e))
		return  r;    //r是e的父结点，返回结点r的指针
	p = Parent(r->leftChild, e);    //递归调用r的左子树
		if (p == NULL)    p = Parent(r->rightChild, e);
	return p;
}
template <class ElemType>
int BinaryTree<ElemType>::GetParent(ElemType e, ElemType &f) //public
{
	if (root == NULL || root->data == e)
		return false;
	BinTreeNode<ElemType> *p = Parent(root, e);
	if (p == NULL)  return false;  //树中无元素e
	f = p->data;
	return true;
}
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::
LeftSibling(ElemType e)     //private
{
	if (root->data == e) return NULL;
	BinTreeNode<ElemType> *p = Parent(root, e);
	if (p == NULL)return NULL;   //无e结点
	if (p->leftChild->data == e)   //e是其父亲的左孩子
		return NULL;
	return  p->leftChild; //返回e的左兄弟指针
}
template <class ElemType>
int BinaryTree<ElemType>::
GetLeftSibling(ElemType e, ElemType &s)
{
	if (root->data == e)return false; //根结点无兄弟
	BinTreeNode<ElemType> *p = LeftSibling(e);
	if (p == NULL)return false; //e无左兄弟
	s = p->data;
	return true;
}
template <class ElemType>
int BinaryTree<ElemType>::
InsertChild(ElemType e, ElemType x, ElemType y)
{
	BinTreeNode<ElemType> *ep, *xp, *yp;
	ep = Locate(root, e);  //定位元素e
	if (ep == NULL) return false; //找不到元素e
	xp = new BinTreeNode<ElemType>;
	xp->data = x;
	xp->rightChild = NULL;
	yp = new BinTreeNode<ElemType>;
	yp->data = y;
	yp->leftChild = NULL;
	xp->leftChild = ep->leftChild;
	ep->leftChild = xp; //结点x置为结点e的左孩子
	yp->rightChild = ep->rightChild;
	ep->rightChild = yp; //结点y置为结点e的右孩子
	size = size + 2;
	return true;
}
template <class ElemType>
int BinaryTree<ElemType>::
SetElem(ElemType  e, ElemType  x)
{
	BinTreeNode<ElemType> *p = Locate(root, e);
	if (p == NULL)   return false;
	p->data = x;
	return true;
}
template <class ElemType>
int BinaryTree<ElemType>::Size()  //public
{
	return Size(root);
}
template <class ElemType>
int BinaryTree<ElemType>::
Size(BinTreeNode<ElemType> *r)  //private
{
	if (r == NULL)   return 0;
	else
		return Size(r->leftChild) + Size(r->rightChild) + 1;
	//二叉树的结点总数为左右子树的结点数之和加1
}
template <class ElemType>
int BinaryTree<ElemType>::Depth()  //public
{
	return Depth(root);
}
template <class ElemType>
int BinaryTree<ElemType>::Depth(BinTreeNode<ElemType> *r)  //private
{
	if (r == NULL)   return 0;
	else
	{
		int leftD, rightD;
		leftD = Depth(r->leftChild);
		rightD = Depth(r->rightChild);
		return 1 + (leftD > rightD ? leftD : rightD); //二叉树的深度为左右子树的深度的最大值加1
	}
}
template <class ElemType>
int BinaryTree<ElemType>::Leaf() //public
{
	return Leaf(root);
}
template <class ElemType>
int BinaryTree<ElemType>::Leaf(BinTreeNode<ElemType> *r)  //private
{
	if (r == NULL)return 0;
	if (r->leftChild == NULL&&r->rightChild == NULL)
		return 1;
	return Leaf(r->leftChild) + Leaf(r->rightChild);
	//递归遍历左子树和右子树
}
template <class ElemType>
void BinaryTree<ElemType>::Clear(BinTreeNode<ElemType> *r)    //private
{
	if (r != NULL)
	{
		Clear(r->leftChild); //后序递归
		Clear(r->rightChild);
		delete r;
		size--;
	}
}
template <class ElemType>
BinaryTree<ElemType>:: ~BinaryTree()
{
	Clear(root);
	root = NULL;
}
template <class ElemType>
void BinaryTree<ElemType>::DisplayTreeeHelp(BinTreeNode<ElemType> *r, int level)
{
	if (r != NULL)
	{
		DisplayTreeeHelp(r->rightChild, level + 1);
		//显示右子树
		cout << endl;	                //显示新行	
		for (int i = 0; i < level - 1; i++)
			cout << " ";	     //确保在第level列显示结点
		cout << r->data;	    //显示结点
		DisplayTreeeHelp(r->leftChild, level + 1);
	}
}
template <class ElemType>
void BinaryTree<ElemType>::DisplayTree()
{
	DisplayTreeeHelp(root, 1);
	cout << endl;
}
#endif