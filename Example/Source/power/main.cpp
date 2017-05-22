#include "utility.h"				// 实用程序软件包
#include "large_int.h"				// 大非负整数类的头文件
#include "power.h"					// 计算任意大正整数的任意大正整数次方

int main(void)
{
	Timer tm;						// 计时器对象
	CLargeInt largeInt(0);			// 定义一个大非负整数
	largeInt = Power(8, 0);			// 求任意大正整数的任意大正整数次方
	cout << "8^0="	
		 << largeInt << endl;		// 显示任意大正整数的任意大正整数次方值

	largeInt = Power(2, 10);		// 求任意大正整数的任意大正整数次方
	cout << "2^10="	
		 << largeInt << endl;		// 显示任意大正整数的任意大正整数次方值

	largeInt = Power(189, 200);		// 求任意大正整数的任意大正整数次方
	cout << "189^200="	
		 << largeInt << endl;		// 显示任意大正整数的任意大正整数次方值
	printf("用时%.3f秒!\n", tm.ElapsedTime());

	system("PAUSE");				// 调用库函数system()
	return 0;						// 返回值0, 返回操作系统
}