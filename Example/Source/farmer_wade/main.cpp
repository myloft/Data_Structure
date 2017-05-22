// 文件路径名: farmer_wade\main.cpp
#include "utility.h"						// 实用程序软件包头文件
#include "farmer_wade.h"					// 农夫过河

int main(void)								// 主函数main(void)
{
	FarmerWade objFarmerWade;				// 农夫过河对象
	objFarmerWade.Run();					// 运行农夫过河

    system("PAUSE");						// 调用库函数system()
    return 0; 								// 返回值0
}

