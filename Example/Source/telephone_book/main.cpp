// 文件路径名: telephone_book\main.cpp
#include "utility.h"						// 实用程序软件包
#include "telephone_book.h"					// 电话号码簿类

int main()
{
	const int m = 3, b = 7;					// m表示桶容量, b表示基桶数

	TelephoneBook<m, b> objTelephoneBook;	// 电话号码簿对象
	objTelephoneBook.Run();					// 运行电话号码簿
	
	system("PAUSE");						// 调用库函数system()
	return 0;								// 返回值0, 返回操作系统
}

