// �ļ�·����:call_simulation\main.cpp 
#include "utility.h"							// ʵ�ó��������
#include "call_simulation.h"					// �绰�ͻ�����ģ����

int main(void)
{
	bool bYes;								// �û������û��ش��Ƿ����

	do
	{
		CallSimulation objSim;				// �绰�ͻ�����ģ��
		objSim.Run();						// ģ��绰�ͻ�����
		cout << "�Ƿ����";
		bYes = UserSaysYes();				// �����û��ش�
	} while (bYes);

	system("PAUSE");							// ���ÿ⺯��system()
	return 0;									// ����ֵ0, ���ز���ϵͳ
}
