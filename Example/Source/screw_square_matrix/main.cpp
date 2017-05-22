// �ļ�·����:screw_square_matrix\main.cpp
#include "utility.h"					// ʵ�ó��������
#include "matrix.h"						// ������

int main(void)
{
	int n;								// ����Ľ�

	cout << "�������Ľ�:";
	do
	{
		cin >> n;						// ����n
		if (n < 1 || n >= 20)
		{	// n����ȡֵ��Χ��
			cout << "n��ֵӦ��1~19֮��,��������n:";
		}
	}
	while (n < 1 || n >= 20);

	Matrix<int> screwSquareMatrix(n, n);						// n��n�׷���
	int curValue = 1;											// ��ǰҪ��������ֵ
	int curSide = n;											// ��ǰҪ��д�����εı߳�
	int i, j;													// ��ʱ����

	// ����n��n����������
	for (i = 1; i <= (n + 1) / 2; i++)
	{	// ���ɵ�i��������, 4��������±�Ϊ
		// (i,i),(i+curSide-1,i),(i+curSide-1,i+curSide-1),(i,i+curSide-1)
		if (curSide == 1)
		{	// �߳�1��������
			screwSquareMatrix(i, i) = curValue++;				// ����ֵcurValue
		}
		else
		{
			for (j = i; j < i + curSide - 1; j++)
			{	// ��������������ı�(i,i)-(i+curSide-1,i)
				screwSquareMatrix(j, i) = curValue++;			// ����ֵcurValue
			}
			
			for (j = i; j < i + curSide - 1; j++)
			{	// ��������������ı�(i+curSide-1,i)-(i+curSide-1,i+curSide-1)
				screwSquareMatrix(i+curSide-1, j) = curValue++;	// ����ֵcurValue
			}

			for (j = i + curSide - 1; j > i; j--)
			{	// ��������������ı�(i+curSide-1,i+curSide-1)-(i,i+curSide-1)
				screwSquareMatrix(j, i+curSide-1) = curValue++;	// ����ֵcurValue
			}

			for (j = i + curSide - 1; j > i; j--)
			{	// ��������������ı�(i,i+curSide-1)-(i,i)
				screwSquareMatrix(i, j) = curValue++;			// ����ֵcurValue
			}
		}

		curSide -= 2;											// ��һ�������εı߳��Լ�2
	}

	for(i = 1; i <= n; i++)
	{	// ��i��
		for( j = 1; j <= n; j++)
		{	// ��j��
			cout << setw(4) << screwSquareMatrix(i, j);
		}
		cout << endl;											// ����
	}

   	system("PAUSE");        									// ���ÿ⺯��system()
   	return 0;               									// ����ֵ0, ���ز���ϵͳ
}




