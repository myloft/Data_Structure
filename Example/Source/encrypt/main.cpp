// �ļ�·����: encrypt\main.cpp 
#include "utility.h"										// ʵ�ó��������
#include "Encrypt.h"										// ������

int main(void)
{
	int select = 1;											// �û�����ѡ���
	char source[256], destination[256];						// Դ����Ŀ�괮
	Encrypt objEncrypt;										// ���������
	
	while (select != 3)
	{	
		// ѡ��˵�
		cout << "��ѡ��" << endl;
		cout << "1. ����--��������ı������м��ܺ����" << endl;
		cout << "2. ����--��������Ѽ��ܵ��ı����н��ܺ����" << endl;
		cout << "3. �˳�--�˳�����" << endl;
		cin >> select;

		switch (select)
		{
		case 1:												// ����
			cout << "�������ı���:";
			cin >> source;									// �����ı���
			strcpy(destination, objEncrypt.Encode(source).CStr());	// ����
			cout << "���ܴ�:" << destination << endl << endl;// ������ܴ�
			break;
		case 2:												// ����
			cout << "��������ܴ�:";
			cin >> source;									// �����ı���
			strcpy(destination, objEncrypt.Decode(source).CStr());	// ����
			cout << "���ܴ�:" << destination << endl << endl;// ������ܴ�
			break;
		}
	}

	system("PAUSE");										// ���ÿ⺯��system()
	return 0;												// ����ֵ0, ���ز���ϵͳ
}
