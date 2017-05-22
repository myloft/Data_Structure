// 文件路径名: dictionary_anagram_search_system\main.cpp
#include "utility.h"							// 实用程序软件包头文件
#include "dictionary_anagram_search_system.h"	// 词典变位词检索系统

int main(void)									// 主函数main(void)
{
	try											// 用try封装可能出现异常的代码
	{
		DictionaryAnagramSearchSystem objDicAnaSearch;	// 词典变位词检索系统对象
		objDicAnaSearch.Run();					// 运行词典变位词检索系统
  	}
	catch (Error err)							// 捕捉并处理异常
	{
		err.Show();								// 显示异常信息
	}

    system("PAUSE");							// 调用库函数system()
    return 0; 									// 返回值0
}

