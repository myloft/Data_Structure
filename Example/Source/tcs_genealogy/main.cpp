// �ļ�·����: tcs_genealogy\main.cpp 
#include "utility.h"										// ʵ�ó��������
#include "tcs_genealogy.h"									// ������

int main(void)
{
	char select, ch;

	do
	{
		TCSGenealogy obj;									// ���ۼ������ѧ�����׶���
		cout << "��ѡ��" << endl;
		cout << "1. �������Ļ" << endl;
		cout << "2. ������ļ�" << endl;
		cout << "3. �˳�" << endl;
		cin >> select;										// ����ѡ��
		while ((ch = cin.get()) != '\n');					// �������е������ַ�
		switch (select)
		{
		case '1':
			obj.Output(OUTPUT_TO_SCREEN);					// �������Ļ
			break;
		case '2':
			obj.Output(OUTPUT_TO_FILE);						// ������ļ�
			break;
		}
	}
	while (select != '3');

	system("PAUSE");										// ���ÿ⺯��system()
	return 0;												// ����ֵ0, ���ز���ϵͳ
}
