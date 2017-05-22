// 文件路径名:cstring\main.cpp 
#include "utility.h"				// 实用程序软件包
#include "cstring.h"				// 串类

int main(void)
{
	CString s1, s2, s3;
	cout << "输入第1个串s1:";
	cin >> s1;						// 测试>>	
	cout << "输入第1个串s2:";
	cin >> s2;						// 测试>>
	cout << "s3 = s1 + s2" << endl;
	s3 = s1 + s2;					// 测试+
	cout << "s3:" << s3 << endl;	// 测试<<
	
	system("PAUSE");				// 调用库函数system()
	return 0;						// 返回值0, 返回操作系统
}
