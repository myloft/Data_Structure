// �ļ�·����: telephone_book\main.cpp
#include "utility.h"						// ʵ�ó��������
#include "telephone_book.h"					// �绰���벾��

int main()
{
	const int m = 3, b = 7;					// m��ʾͰ����, b��ʾ��Ͱ��

	TelephoneBook<m, b> objTelephoneBook;	// �绰���벾����
	objTelephoneBook.Run();					// ���е绰���벾
	
	system("PAUSE");						// ���ÿ⺯��system()
	return 0;								// ����ֵ0, ���ز���ϵͳ
}

