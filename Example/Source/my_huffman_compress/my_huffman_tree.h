// 文件路径名: my_huffman_compress\my_huffman_tree.h 
#ifndef __MY_HUFFMAN_TREE_H__
#define __MY_HUFFMAN_TREE_H__

#include "min_priority_heap_queue.h"		// 最小优先堆队列类
#include "string.h"							// 串类

// 哈夫曼树结点的抽象基类
template <class CharType, class WeightType>
class MyHuffNode 
{    
public:
// 哈夫曼树结点的方法:
	virtual WeightType Weight() = 0;		// 返回结点的权值
	virtual bool IsLeaf() = 0;				// 判断结点是否为叶结点
	virtual MyHuffNode<CharType, WeightType> *Left() = 0;	// 返回结点的左孩子
	virtual MyHuffNode<CharType, WeightType> *Right() = 0;	// 返回结点的右孩子
	virtual void SetLeft(MyHuffNode<CharType, WeightType> *child) = 0;
		// 设置结点的左孩子
	virtual void SetRight(MyHuffNode<CharType, WeightType> *child) = 0;
		// 设置结点的右孩子
};





// 哈夫曼树结点的抽象基类辅助结构
template <class CharType, class WeightType>
struct MyHuffNodehelp
{
	MyHuffNode<CharType, WeightType> *ptr;	// 哈夫曼树结点的抽象基类指针
};





// 哈夫曼树叶结点派生类
template <class CharType, class WeightType>
class MyLeafNode : public MyHuffNode<CharType, WeightType> 
{
private:
// 哈夫曼树叶结点派生类的数据成员:
	CharType cha;							// 叶结点包含的字符
	WeightType weight;						// 权值

public:
// 哈夫曼树叶结点方法声明及重载编译系统默认方法声明:
	MyLeafNode(const CharType &ch, const WeightType &w);	// 构造函数
	virtual ~MyLeafNode(){}					// 析构函数			
	CharType Char();						// 返回叶结点的字符
	WeightType Weight();					// 返回结点的权值
	bool IsLeaf();							// 判断结点是否为叶结点
	MyHuffNode<CharType, WeightType> *Left();	// 返回结点的左孩子
	MyHuffNode<CharType, WeightType> *Right();	// 返回结点的右孩子
	void SetLeft(MyHuffNode<CharType, WeightType> *child){}
		// 设置结点的左孩子
	void SetRight(MyHuffNode<CharType, WeightType> *child){}
		// 设置结点的右孩子
};

// 哈夫曼树叶结点派生类的实现部分
template <class CharType, class WeightType>
MyLeafNode<CharType, WeightType>::MyLeafNode(const CharType &ch, const WeightType &w)
// 操作结果: 由字符ch, 权值ch构造哈夫曼树叶结点
{
	cha = ch;								// 字符
	weight = w;								// 权值
}

template <class CharType, class WeightType>
CharType MyLeafNode<CharType, WeightType>::Char()
// 操作结果: 返回叶结点的字符
{
	return cha;								// 字符
}

template <class CharType, class WeightType>
WeightType MyLeafNode<CharType, WeightType>::Weight()
// 操作结果: 返回结点的权值
{
	return weight;							// 权值
}

template <class CharType, class WeightType>
bool MyLeafNode<CharType, WeightType>::IsLeaf()
// 操作结果: 判断结点是否为叶结点
{
	return true;							// 叶结点
}

template <class CharType, class WeightType>
MyHuffNode<CharType, WeightType> *MyLeafNode<CharType, WeightType>::Left()
// 操作结果: 返回结点的左孩子
{
	return NULL;							// 叶结点无孩子
}

template <class CharType, class WeightType>
MyHuffNode<CharType, WeightType> *MyLeafNode<CharType, WeightType>::Right()
// 操作结果: 返回结点的右孩子
{
	return NULL;							// 叶结点无孩子
}




// 哈夫曼树内部结点派生类
template <class CharType, class WeightType>
class MyIntlNode : public MyHuffNode<CharType, WeightType> 
{
private:
// 哈夫曼树叶结点派生类的数据成员:
	MyHuffNode<CharType, WeightType> *lChild;	// 左孩子
	MyHuffNode<CharType, WeightType> *rChild;	// 右孩子
	WeightType weight;						// 权值

public:
// 哈夫曼树内部结点方法声明及重载编译系统默认方法声明:
	MyIntlNode(const WeightType &w, 
		MyHuffNode<CharType, WeightType> *lc, MyHuffNode<CharType, WeightType> *rc);
		// 构造函数
	virtual ~MyIntlNode(){}					// 析构函数			
	WeightType Weight();					// 返回结点的权值
	bool IsLeaf();							// 判断结点是否为叶结点
	MyHuffNode<CharType, WeightType> *Left();	// 返回结点的左孩子
	MyHuffNode<CharType, WeightType> *Right();	// 返回结点的右孩子
	void SetLeft(MyHuffNode<CharType, WeightType> *child);
		// 设置结点的左孩子
	void SetRight(MyHuffNode<CharType, WeightType> *child);
		// 设置结点的右孩子
};

// 哈夫曼树内部结点派生类的实现部分
template <class CharType, class WeightType>
MyIntlNode<CharType, WeightType>::MyIntlNode(const WeightType &w, 
		MyHuffNode<CharType, WeightType> *lc, MyHuffNode<CharType, WeightType> *rc)
// 操作结果: 由权值w, 左孩子为lc, 右孩子为rc构造哈夫曼树内部结点
{
	weight = w;								// 权值
	lChild = lc;							// 左孩子
	rChild = rc;							// 右孩子
}

template <class CharType, class WeightType>
WeightType MyIntlNode<CharType, WeightType>::Weight()
// 操作结果: 返回结点的权值
{
	return weight;							// 权值
}

template <class CharType, class WeightType>
bool MyIntlNode<CharType, WeightType>::IsLeaf()
// 操作结果: 判断结点是否为叶结点
{
	return false;							// 内部结点
}

template <class CharType, class WeightType>
MyHuffNode<CharType, WeightType> *MyIntlNode<CharType, WeightType>::Left()
// 操作结果: 返回结点的左孩子
{
	return lChild;							// 左孩子
}

template <class CharType, class WeightType>
MyHuffNode<CharType, WeightType> *MyIntlNode<CharType, WeightType>::Right()
// 操作结果: 返回结点的右孩子
{
	return rChild;							// 右孩子
}

template <class CharType, class WeightType>
void MyIntlNode<CharType, WeightType>::SetLeft(MyHuffNode<CharType, WeightType> *child)
// 操作结果: 设置结点的左孩子
{
	lChild = child;							// 左孩子
}

template <class CharType, class WeightType>
void MyIntlNode<CharType, WeightType>::SetRight(MyHuffNode<CharType, WeightType> *child)
// 操作结果: 设置结点的右孩子
{
	rChild = child;							// 右孩子
}




// 哈夫曼树类
template <class CharType, class WeightType>
class MyHuffmanTree
{
protected:
// 哈夫曼树的数据成员:
	MyHuffNode<CharType, WeightType> *root;		// 根
	String *charCodes;							// 字符编码信息
	MyHuffNode<CharType, WeightType> *pCurNode;	// 译码时从根结点到叶结点路径的当前结点
	int num;									// 叶结点个数
	unsigned int (*CharIndex)(const CharType &);// 字符位置映射

// 辅助函数:
	void CreatCode(MyHuffNode<CharType, WeightType> *r, char code[], int len = 0);
		// 生成字符编码
	void Clear(MyHuffNode<CharType, WeightType> *r);	// 释放以r为根的树所占用空间

public:
// 哈夫曼树方法声明及重载编译系统默认方法声明:
	MyHuffmanTree(CharType ch[], WeightType w[], int n, unsigned int (*ChIndex)(const CharType &));
		// 由字符,权值,字符个数及字符位置映射构造哈夫曼树
	virtual ~MyHuffmanTree();					// 析构函数
	String Encode(CharType ch);					// 编码
	LinkList<CharType> Decode(String strCode);	// 译码
};

// 关系运算符重载
template <class CharType, class WeightType>
bool operator <(const MyHuffNodehelp<CharType, WeightType> &first, const MyHuffNodehelp<CharType, WeightType> &second);
	// 重载关系运算符<
template <class CharType, class WeightType>
bool operator >(const MyHuffNodehelp<CharType, WeightType> &first, const MyHuffNodehelp<CharType, WeightType> &second);
	// 重载关系运算符>
template <class CharType, class WeightType>
bool operator <=(const MyHuffNodehelp<CharType, WeightType> &first, const MyHuffNodehelp<CharType, WeightType> &second);
	// 重载关系运算符<=

// 哈夫曼树类及相关函数的实现部分
template <class CharType, class WeightType>
bool operator <(const MyHuffNodehelp<CharType, WeightType> &first, 
	const MyHuffNodehelp<CharType, WeightType> &second)
// 操作结果：重载关系运算符<
{
	return first.ptr->Weight() < second.ptr->Weight();	// 比较权值
}

template <class CharType, class WeightType>
bool operator >(const MyHuffNodehelp<CharType, WeightType> &first, 
	const MyHuffNodehelp<CharType, WeightType> &second)
// 操作结果：重载关系运算符>
{
	return first.ptr->Weight() > second.ptr->Weight();	// 比较权值
}

template <class CharType, class WeightType>
bool operator <=(const MyHuffNodehelp<CharType, WeightType> &first, 
	const MyHuffNodehelp<CharType, WeightType> &second)
// 操作结果：重载关系运算符<=
{
	return first.ptr->Weight() <= second.ptr->Weight();	// 比较权值
}

template <class CharType, class WeightType>
void MyHuffmanTree<CharType, WeightType>::CreatCode(MyHuffNode<CharType, WeightType> *r, 
	char code[], int len)
// 操作结果：生成字符编码
{
	if (r->IsLeaf())
	{	// 到达叶结点
		CharType ch = ((MyLeafNode<CharType, WeightType> *)r)->Char();	// 叶结点的字符
		code[len] = '\0';								// 字符串结束符
		String strCode(code);							// 编码串
		charCodes[(*CharIndex)(ch)] = strCode;			// 将字符编码存入charCodes
	}
	else
	{	// 内部结点
		code[len] = '0';								// 左分支编码为'0' 
		CreatCode(r->Left(), code, len + 1);			// 向左分支搜索

		code[len] = '1';								// 左分支编码为'1' 
		CreatCode(r->Right(), code, len + 1);			// 向右分支搜索
	}
}

template <class CharType, class WeightType>
MyHuffmanTree<CharType, WeightType>::MyHuffmanTree(CharType ch[], WeightType w[], int n, 
	unsigned int (*ChIndex)(const CharType &))
// 操作结果：由字符,权值和字符个数构造哈夫曼树
{
	CharIndex = ChIndex;			// 字符位置映射
	num = n;						// 叶结点个数
	charCodes = new String[num];	// 字符编码信息
	MinPriorityHeapQueue<MyHuffNodehelp<CharType, WeightType> > minHeap;	// 小顶堆
	int i;							// 临时变量
	
	for (i = 0; i < num; i++)
	{	// 生成森林
		MyHuffNodehelp<CharType, WeightType> tem;		// 哈夫曼树结点的抽象基类辅助结构变量
		tem.ptr = new MyLeafNode<CharType, WeightType>(ch[i], w[i]);
		minHeap.InQueue(tem);
			// 森林中每棵树为只含一个结点的二叉树
	}

	for (i = 0; i < num - 1; i++)
	{	// 建立哈夫曼树
		MyHuffNodehelp<CharType, WeightType> r, r1, r2;	// 临时变量
		minHeap.OutQueue(r1);		// 第1棵二叉树
		minHeap.OutQueue(r2);		// 第2棵二叉树
		r.ptr = new MyIntlNode<CharType, WeightType>(r1.ptr->Weight() + r2.ptr->Weight(),
			r1.ptr, r2.ptr);		// 合并r1与r2成r
		minHeap.InQueue(r);			// 入队
	}
	
	MyHuffNodehelp<CharType, WeightType> rt;			// 临时变量
	minHeap.OutQueue(rt);			// 森林中的二叉树为所求的Huffman树
	root = rt.ptr;					// 森林中的二叉树为所求的Huffman树
	pCurNode = root;				// 译码时从根结点开始
	char *code = new char[num];		// 字符编码信息
	CreatCode(root, code);			// 生成字符编码
	delete []code;					// 释放存储空间
}

template <class CharType, class WeightType>
void MyHuffmanTree<CharType, WeightType>::Clear(MyHuffNode<CharType, WeightType> *r)
// 操作结果：释放以r为根的树所占用空间
{
	if (r != NULL)
	{
		Clear(r->Left());			// 释放左子树
		Clear(r->Right());			// 释放右子树
		delete r;					// 释放根结点
	}
}

template <class CharType, class WeightType>
MyHuffmanTree<CharType, WeightType>::~MyHuffmanTree()
// 操作结果：销毁哈夫曼树
{	
	Clear(root);					// 释放以root为根的树的结点所占用空间
}

template <class CharType, class WeightType>
String MyHuffmanTree<CharType, WeightType>::Encode(CharType ch)
// 操作结果：返回字符编码
{
	return charCodes[(*CharIndex)(ch)];	// 返回字符编码
}

template <class CharType, class WeightType>
LinkList<CharType> MyHuffmanTree<CharType, WeightType>::Decode(String strCode)
// 操作结果：对编码串strCode进行译码,返回编码前的字符序列
{
	LinkList<CharType> charList;						// 编码前的字符序列
	
	for (int pos = 0; pos < strCode.Length(); pos++)
	{	// 处理每位编码
		if (strCode[pos] == '0') pCurNode = pCurNode->Left();	// '0'表示左分支	
		else pCurNode = pCurNode->Right();				// '1'表示左分支	

		if (pCurNode->IsLeaf())
		{	// 译码时从根结点到叶结点路径的当前结点为叶结点
			charList.Insert(charList.Length() + 1, 
				((MyLeafNode<CharType, WeightType> *)pCurNode)->Char());
			pCurNode = root;							// pCurNode回归根结点
		}
	}
	return charList;									// 返回编码前的字符序列
}

#endif