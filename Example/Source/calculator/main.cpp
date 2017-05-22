// 文件路径名:calculator\main.h 
#include "utility.h"							// 实用程序软件包
#include "calculator.h"							// 计算器类

int main(void)
{
	try											// 用try封装可能出现异常的代码
	{
		bool bYes;								// 用户接受用户回答是否继续

		do
		{
			Calculator<double> objExpression;	// 表达式对象
			cout << "输入表达式:" << endl;
			objExpression.Run();				// 运行表达式
			cout << "是否继续";
			bYes = UserSaysYes();				// 接受用户回答
		} while (bYes);
  	}
	catch (Error err)							// 捕捉并处理异常
	{	
		err.Show();								// 显示异常信息
	}
	
	system("PAUSE");							// 调用库函数system()
	return 0;									// 返回值0, 返回操作系统
}
