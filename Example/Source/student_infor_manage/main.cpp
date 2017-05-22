// 文件路径名: student_infor_manage\main.cpp
#include "utility.h"										// 实用程序软件包
#include "student_infor_manage.h"							// 学生基本信息管理类

int main()
{
	try														// 用try封装可能出现异常的代码
	{
		StudentInforManage objStudentInforManage;			// 学生信息管理对象
		objStudentInforManage.Run();						// 运行学生基本信息管理
   	}
	catch (Error err)										// 捕捉并处理异常
	{	
		err.Show();											// 显示异常信息
	}
	
	system("PAUSE");										// 调用库函数system()
	return 0;												// 返回值0, 返回操作系统
}

