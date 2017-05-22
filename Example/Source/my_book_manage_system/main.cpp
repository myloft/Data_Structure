// 文件路径名: my_book_manage_system\main.cpp
#include "utility.h"							// 实用程序软件包
#include "my_book_manage_system.h"				// 个人图书管理系统类

int main()
{
	MyBookManageSystem objMyBookManageSystem;	// 个人图书管理对象
	objMyBookManageSystem.Run();				// 运行个人图书管理
	
	system("PAUSE");							// 调用库函数system()
	return 0;									// 返回值0, 返回操作系统
}

