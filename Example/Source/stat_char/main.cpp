// �ļ�·����: stat_char\main.cpp
#include "utility.h"						// ʵ�ó��������
#include "stat_char.h"						// ͳ���ַ��㷨

int main(void)
{
    try										// ��try��װ���ܳ����쳣�Ĵ���
	{
		char str[256];						// �ַ���
		cout << "�����ַ���:" << endl;		// ��ʾ��Ϣ
		cin >> str;							// �����ַ���
		StatChar(str);						// ͳ���ַ���Ϣ
	}
	catch (Error err)						// ��׽�������쳣
	{
		err.Show();							// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");						// ���ÿ⺯��system()
	return 0;								// ����ֵ0, ���ز���ϵͳ
}

