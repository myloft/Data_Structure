#include "utility.h"							// ʵ�ó��������
#include "expression_value.h"					// ���ʽ��ֵ���ͷ�ļ�

int main(void)
{
	try											// ��try��װ���ܳ����쳣�Ĵ���
	{
		bool bYes;								// �û������û��ش��Ƿ����

		do
		{
			cout << "������ʽ:" << endl;
			ExpressionValue<double>::Run();				// ��Ӽ����������׺���ʽֵ֮
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