#include "utility.h"							// 实用程序软件包
#include "expression_value.h"					// 表达式求值类的头文件

int main(void)
{
	try											// 用try封装可能出现异常的代码
	{
		bool bYes;								// 用户接受用户回答是否继续

		do
		{
			cout << "输入表达式:" << endl;
			ExpressionValue<double>::Run();				// 求从键盘输入的中缀表达式之值
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