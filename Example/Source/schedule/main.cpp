// 文件路径名:schedule\main.cpp
#include "utility.h"										// 实用程序软件包
#include "schedule.h"										// 课程表类

int main(int argc, char *argv[])
{
	try														// 用try封装可能出现异常的代码
	{

		char inFileName[256],outFileName[256];
		
		if (argc > 1) strcpy(inFileName, argv[1]);			// 存在命令行参数
		else strcpy(inFileName, "course_inf.txt");			// 无命令行参数
		ifstream inFile(inFileName);						// 输入流文件

		if (inFile == 0) throw Error("不能打开课程信息文件!");	// 抛出异常
   
		if (argc > 2) strcpy(outFileName,argv[2]);			// 存在命令行参数
		else strcpy(outFileName,"curriculum_scedule.txt");	// 无命令行参数
		ofstream outFile(outFileName);						// 输出流文件
		if (outFile == 0)  throw Error("不能打开课程表文件!");	// 抛出异常

		cout << "课程信息文件为: " << inFileName << endl << endl;
		cout << "正在排课，请稍候..." << endl << endl;

		Schedule<8> rc(&inFile, &outFile);					// 表示排8学期课(从第1学期到第8学期)
		rc.Read();								// 输入课程信息
		rc.TopologicalOrder();					// 用拓扑排的思进行排课
		rc.Write();								// 输出课表

		cout<<"排课结束，课表文件为: "<<outFileName<<endl;
  	}
	catch (Error err)							// 捕捉并处理异常
	{	
		err.Show();								// 显示异常信息
	}
	
	system("PAUSE");							// 调用库函数system()
	return 0;									// 返回值0, 返回操作系统

	
	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}
