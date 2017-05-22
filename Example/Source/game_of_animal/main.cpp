// 文件路径名: game_of_animal\main.cpp
#include "utility.h"										// 实用程序软件包
#include "game_of_animal.h"									// 动物游戏类

int main()
{
	try														// 用try封装可能出现异常的代码
	{
		GameOfAnimal objGameOfAnimal;						// 动物游戏对象
		objGameOfAnimal.Run();								// 运行动物游戏
   	}
	catch (Error err)										// 捕捉并处理异常
	{	
		err.Show();											// 显示异常信息
	}
	
	system("PAUSE");										// 调用库函数system()
	return 0;												// 返回值0, 返回操作系统
}

