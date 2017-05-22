// 文件路径名:my_gen_list\main.cpp
#include "utility.h"				// 实用程序软件包
#include "my_gen_list.h"			// 广义表

int main(void)
{
	
	bool bYes;						// 用户接受用户回答是否继续

	do
	{
		MyGenList<int> gList;
		cout << "请输入广义表eg: (12,(34)):" << endl;
		gList.Input();
		cout << "广义表为:";
		gList.Show();
		cout << endl;
		cout << "深度:" << gList.Depth() << endl << endl;
		cout << "是否继续";
		bYes = UserSaysYes();		// 接受用户回答
	} while (bYes);

	system("PAUSE");				// 调用库函数system()
	return 0;						// 返回值0, 返回操作系统
}


