// 文件路径名:screw_square_matrix\main.cpp
#include "utility.h"					// 实用程序软件包
#include "matrix.h"						// 矩阵类

int main(void)
{
	int n;								// 矩阵的阶

	cout << "输入矩阵的阶:";
	do
	{
		cin >> n;						// 输入n
		if (n < 1 || n >= 20)
		{	// n不在取值范围内
			cout << "n的值应在1~19之间,重新输入n:";
		}
	}
	while (n < 1 || n >= 20);

	Matrix<int> screwSquareMatrix(n, n);						// n×n阶方阵
	int curValue = 1;											// 当前要填入矩阵的值
	int curSide = n;											// 当前要填写正方形的边长
	int i, j;													// 临时变量

	// 生成n×n阶螺旋方阵
	for (i = 1; i <= (n + 1) / 2; i++)
	{	// 生成第i个正方形, 4个顶点的下标为
		// (i,i),(i+curSide-1,i),(i+curSide-1,i+curSide-1),(i,i+curSide-1)
		if (curSide == 1)
		{	// 边长1的正方形
			screwSquareMatrix(i, i) = curValue++;				// 填入值curValue
		}
		else
		{
			for (j = i; j < i + curSide - 1; j++)
			{	// 填入正方形左面的边(i,i)-(i+curSide-1,i)
				screwSquareMatrix(j, i) = curValue++;			// 填入值curValue
			}
			
			for (j = i; j < i + curSide - 1; j++)
			{	// 填入正方形下面的边(i+curSide-1,i)-(i+curSide-1,i+curSide-1)
				screwSquareMatrix(i+curSide-1, j) = curValue++;	// 填入值curValue
			}

			for (j = i + curSide - 1; j > i; j--)
			{	// 填入正方形右面的边(i+curSide-1,i+curSide-1)-(i,i+curSide-1)
				screwSquareMatrix(j, i+curSide-1) = curValue++;	// 填入值curValue
			}

			for (j = i + curSide - 1; j > i; j--)
			{	// 填入正方形上面的边(i,i+curSide-1)-(i,i)
				screwSquareMatrix(i, j) = curValue++;			// 填入值curValue
			}
		}

		curSide -= 2;											// 下一个正方形的边长自减2
	}

	for(i = 1; i <= n; i++)
	{	// 第i行
		for( j = 1; j <= n; j++)
		{	// 第j列
			cout << setw(4) << screwSquareMatrix(i, j);
		}
		cout << endl;											// 换行
	}

   	system("PAUSE");        									// 调用库函数system()
   	return 0;               									// 返回值0, 返回操作系统
}




