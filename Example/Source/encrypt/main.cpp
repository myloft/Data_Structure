// 文件路径名: encrypt\main.cpp 
#include "utility.h"										// 实用程序软件包
#include "Encrypt.h"										// 加密类

int main(void)
{
	int select = 1;											// 用户功能选择号
	char source[256], destination[256];						// 源串与目标串
	Encrypt objEncrypt;										// 加密类对象
	
	while (select != 3)
	{	
		// 选择菜单
		cout << "请选择" << endl;
		cout << "1. 加密--将输入的文本串进行加密后输出" << endl;
		cout << "2. 解密--将输入的已加密的文本进行解密后输出" << endl;
		cout << "3. 退出--退出运行" << endl;
		cin >> select;

		switch (select)
		{
		case 1:												// 加密
			cout << "请输入文本串:";
			cin >> source;									// 输入文本串
			strcpy(destination, objEncrypt.Encode(source).CStr());	// 加密
			cout << "加密串:" << destination << endl << endl;// 输出加密串
			break;
		case 2:												// 解密
			cout << "请输入加密串:";
			cin >> source;									// 输入文本串
			strcpy(destination, objEncrypt.Decode(source).CStr());	// 解密
			cout << "解密串:" << destination << endl << endl;// 输出解密串
			break;
		}
	}

	system("PAUSE");										// 调用库函数system()
	return 0;												// 返回值0, 返回操作系统
}
