// 文件路径名:game_of_21_point\main.h 
#include "utility.h"					// 实用程序软件包
#include "game_of_21_point.h"			// 21点游戏

int main(void)
{
	bool bYes;							// 用于接受用户回答是否再次玩游戏
	do
	{
		GameOf21Point objGame;			//  21点游戏对象
		objGame.Game();					// 运行游戏
		cout << "你想再玩一次吗";
		bYes = UserSaysYes();			// 接受用户回答
	} while (bYes);

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}