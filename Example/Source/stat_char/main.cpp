// 文件路径名: stat_char\main.cpp
#include "utility.h"						// 实用程序软件包
#include "stat_char.h"						// 统计字符算法

int main(void)
{
    try										// 用try封装可能出现异常的代码
	{
		char str[256];						// 字符串
		cout << "输入字符串:" << endl;		// 提示信息
		cin >> str;							// 输入字符串
		StatChar(str);						// 统计字符信息
	}
	catch (Error err)						// 捕捉并处理异常
	{
		err.Show();							// 显示异常信息
	}

	system("PAUSE");						// 调用库函数system()
	return 0;								// 返回值0, 返回操作系统
}

