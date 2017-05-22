// 文件路径名:line_editor\main.cpp
#include "utility.h"					// 实用程序软件包
#include "line_editor.h"				// 文本编辑类

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
		char infName[256], outfName[256];

		cout << "请输入文件名(缺省: file_in.txt):";
		strcpy(infName, Read(cin).CStr());
		if (strlen(infName) == 0)
		{	// infName为空
			strcpy(infName, "file_in.txt");
		}
		
		cout << "请输出文件名(缺省: file_out.txt):";
		strcpy(outfName, Read(cin).CStr());
		if (strlen(outfName) == 0)
		{	// outfName为空
			strcpy(outfName, "file_out.txt");
		}

		LineEditor text(infName, outfName);	// 定义文本对象
		text.Run();						// 运行编辑器
  	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

   	system("PAUSE");        			// 调用库函数system()
   	return 0;               			// 返回值0, 返回操作系统
}
