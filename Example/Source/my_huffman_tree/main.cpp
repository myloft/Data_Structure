// 文件路径名:my_huffman_tree\main.cpp
#include "utility.h"					// 实用程序软件包
#include "my_huffman_tree.h"			// 哈夫曼树类

unsigned int CharIndex(const char &ch)
// 操作结果：字符位置映射
{
	unsigned int result;				// 返回结果
	if (ch == 'a') result = 1;			// 'a'存储位置为1
	else if (ch == 'b') result = 2;		// 'b'存储位置为2
	else if (ch == 'c') result = 3;		// 'c'存储位置为3
	return result;						// 返回结果
}

int main(void)
{
	char ch[] = {'a', 'b', 'c'}; 
	int w[] = {10, 20, 10};
	int n = 3;

	MyHuffmanTree<char, int> hmTree1(ch, w, n, CharIndex);
	MyHuffmanTree<char, int> hmTree(hmTree1);	// 复制构造函数
	hmTree = hmTree1;					// 赋值语句重载
	String strText = "abc";				// 文本串
	String strCode = "10011";			// 编码串

	cout << "文本串" << strText.CStr() << "编码为:";
	for (int pos = 0; pos < strText.Length(); pos++)
	{
		String strTmp = hmTree.Encode(strText[pos]);
		cout << strTmp.CStr();
	}
	cout << endl;
	system("PAUSE");					// 调用库函数system()

	cout << "编码串" << strCode.CStr() << "译码为:";
	LinkList<char> lkText = hmTree.Decode(strCode);
	strText = lkText;
	cout << strText.CStr() << endl;

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}
