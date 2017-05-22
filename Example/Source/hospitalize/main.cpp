#include "utility.h"				// 实用程序软件包
#include "hospitalize.h"			// 行医类的头文件

int main(void)
{
	Hospitalize obj;				// 行医类对象
	obj.Work();						// 医生工作

	system("PAUSE");				// 调用库函数system()
	return 0;						// 返回值0, 返回操作系统
}