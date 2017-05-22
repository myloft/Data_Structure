// 文件路径名: queen\main.cpp
#include "utility.h"						// 实用程序软件包头文件
#include "queen.h"							// 皇后问题算法

int main(void)								// 主函数main(void)
{
	do
	{
		int n;								// 皇后数
		cout << "输入皇后数:";
		cin >> n;
		Queen(n);							// 求解n皇后问题
		while (GetChar() != '\n');			// 跳过当前行后面的字符
		cout << "是否继续:";
	}
	while (UserSaysYes());

    system("PAUSE");						// 调用库函数system()
    return 0; 								// 返回值0
}

