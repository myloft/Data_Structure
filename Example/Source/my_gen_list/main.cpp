// �ļ�·����:my_gen_list\main.cpp
#include "utility.h"				// ʵ�ó��������
#include "my_gen_list.h"			// �����

int main(void)
{
	
	bool bYes;						// �û������û��ش��Ƿ����

	do
	{
		MyGenList<int> gList;
		cout << "����������eg: (12,(34)):" << endl;
		gList.Input();
		cout << "�����Ϊ:";
		gList.Show();
		cout << endl;
		cout << "���:" << gList.Depth() << endl << endl;
		cout << "�Ƿ����";
		bYes = UserSaysYes();		// �����û��ش�
	} while (bYes);

	system("PAUSE");				// ���ÿ⺯��system()
	return 0;						// ����ֵ0, ���ز���ϵͳ
}


