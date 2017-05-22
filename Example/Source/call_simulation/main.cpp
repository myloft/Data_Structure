// 文件路径名:call_simulation\main.cpp 
#include "utility.h"							// 实用程序软件包
#include "call_simulation.h"					// 电话客户服务模拟类

int main(void)
{
	bool bYes;								// 用户接受用户回答是否继续

	do
	{
		CallSimulation objSim;				// 电话客户服务模拟
		objSim.Run();						// 模拟电话客户服务
		cout << "是否继续";
		bYes = UserSaysYes();				// 接受用户回答
	} while (bYes);

	system("PAUSE");							// 调用库函数system()
	return 0;									// 返回值0, 返回操作系统
}
