// �ļ�·����: queen\main.cpp
#include "utility.h"						// ʵ�ó��������ͷ�ļ�
#include "queen.h"							// �ʺ������㷨

int main(void)								// ������main(void)
{
	do
	{
		int n;								// �ʺ���
		cout << "����ʺ���:";
		cin >> n;
		Queen(n);							// ���n�ʺ�����
		while (GetChar() != '\n');			// ������ǰ�к�����ַ�
		cout << "�Ƿ����:";
	}
	while (UserSaysYes());

    system("PAUSE");						// ���ÿ⺯��system()
    return 0; 								// ����ֵ0
}

