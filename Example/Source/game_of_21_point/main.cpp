// �ļ�·����:game_of_21_point\main.h 
#include "utility.h"					// ʵ�ó��������
#include "game_of_21_point.h"			// 21����Ϸ

int main(void)
{
	bool bYes;							// ���ڽ����û��ش��Ƿ��ٴ�����Ϸ
	do
	{
		GameOf21Point objGame;			//  21����Ϸ����
		objGame.Game();					// ������Ϸ
		cout << "��������һ����";
		bYes = UserSaysYes();			// �����û��ش�
	} while (bYes);

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}