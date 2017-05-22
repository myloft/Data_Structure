// 文件路径名: tcs_genealogy\main.cpp 
#include "utility.h"										// 实用程序软件包
#include "tcs_genealogy.h"									// 加密类

int main(void)
{
	char select, ch;

	do
	{
		TCSGenealogy obj;									// 理论计算机科学家族谱对象
		cout << "请选择" << endl;
		cout << "1. 输出到屏幕" << endl;
		cout << "2. 输出到文件" << endl;
		cout << "3. 退出" << endl;
		cin >> select;										// 输入选择
		while ((ch = cin.get()) != '\n');					// 跳过此行的其它字符
		switch (select)
		{
		case '1':
			obj.Output(OUTPUT_TO_SCREEN);					// 输出到屏幕
			break;
		case '2':
			obj.Output(OUTPUT_TO_FILE);						// 输出到文件
			break;
		}
	}
	while (select != '3');

	system("PAUSE");										// 调用库函数system()
	return 0;												// 返回值0, 返回操作系统
}
