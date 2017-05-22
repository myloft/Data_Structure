// 文件路径名:my_huffman_compress\main.cpp
#include "utility.h"					// 实用程序软件包
#include "my_huffman_compress.h"		// 哈夫曼压缩算法

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
		MyHuffmanCompress obj;
		int select = 0;
		while (select != 3)  
		{
			cout << endl << "1. 压缩";
			cout << endl << "2. 解压缩";
			cout << endl << "3. 退出";
			cout << endl << "请选择:";
			cin >> select;				// 输入选择
			while (cin.get() != '\n');	// 忽略用户输入的其他字符

			switch (select)
			{
				case 1:   
					obj.Compress();		// 压缩
					break;
				case 2:
					obj.Decompress();	// 解压缩
			}
		}
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}
