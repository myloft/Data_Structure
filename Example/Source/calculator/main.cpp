// �ļ�·����:calculator\main.h 
#include "utility.h"							// ʵ�ó��������
#include "calculator.h"							// ��������

int main(void)
{
	try											// ��try��װ���ܳ����쳣�Ĵ���
	{
		bool bYes;								// �û������û��ش��Ƿ����

		do
		{
			Calculator<double> objExpression;	// ���ʽ����
			cout << "������ʽ:" << endl;
			objExpression.Run();				// ���б��ʽ
			cout << "�Ƿ����";
			bYes = UserSaysYes();				// �����û��ش�
		} while (bYes);
  	}
	catch (Error err)							// ��׽�������쳣
	{	
		err.Show();								// ��ʾ�쳣��Ϣ
	}
	
	system("PAUSE");							// ���ÿ⺯��system()
	return 0;									// ����ֵ0, ���ز���ϵͳ
}
