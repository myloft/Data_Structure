// �ļ�·����:cstring\main.cpp 
#include "utility.h"				// ʵ�ó��������
#include "cstring.h"				// ����

int main(void)
{
	CString s1, s2, s3;
	cout << "�����1����s1:";
	cin >> s1;						// ����>>	
	cout << "�����1����s2:";
	cin >> s2;						// ����>>
	cout << "s3 = s1 + s2" << endl;
	s3 = s1 + s2;					// ����+
	cout << "s3:" << s3 << endl;	// ����<<
	
	system("PAUSE");				// ���ÿ⺯��system()
	return 0;						// ����ֵ0, ���ز���ϵͳ
}
