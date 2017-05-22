// 文件路径名:game_of_rock_scissor_cloth\main.h 
#include "utility.h"					// 实用程序软件包
#include "game_of_rock_scissor_cloth.h"	// 石头、剪刀、布游戏

int main(void)
{
	bool bYes;							// 用于接受用户回答是否再次玩游戏
	do
	{
		GameOfRockScissorCloth objGame;	// 石头、剪刀、布游戏对象
		objGame.Game();					// 运行游戏
		cout << "是否再玩一次游戏";
		bYes = UserSaysYes();			// 接受用户回答
	} while (bYes);

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}