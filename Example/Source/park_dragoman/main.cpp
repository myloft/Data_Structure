// 文件路径名: park_dragoman\main.cpp
#include "utility.h"										// 实用程序软件包
#include "park_dragoman.h"									// 课程表类

int main(int argc, char *argv[])
{
	try														// 用try封装可能出现异常的代码
	{
		char parkInforiileName[256];						// 公园信息文件名
		
		if (argc > 1) strcpy(parkInforiileName, argv[1]);	// 存在命令行参数
		else strcpy(parkInforiileName, "park_infor.txt");	// 无命令行参数
		ifstream inFile(parkInforiileName);					// 输入流文件
		if (inFile == NULL) throw Error("不能打开公园信息文件!");	// 抛出异常
		
		ParkDragoman objParkDragoman(&inFile);				// 建立公园导游对象	
		objParkDragoman.Run();								// 执行公园导游
   	}
	catch (Error err)										// 捕捉并处理异常
	{	
		err.Show();											// 显示异常信息
	}
	
	system("PAUSE");										// 调用库函数system()
	return 0;												// 返回值0, 返回操作系统

	
	system("PAUSE");										// 调用库函数system()
	return 0;												// 返回值0, 返回操作系统
}

