// �ļ�·����:game_of_rock_scissor_cloth\main.h 
#include "utility.h"					// ʵ�ó��������
#include "game_of_rock_scissor_cloth.h"	// ʯͷ������������Ϸ

int main(void)
{
	bool bYes;							// ���ڽ����û��ش��Ƿ��ٴ�����Ϸ
	do
	{
		GameOfRockScissorCloth objGame;	// ʯͷ������������Ϸ����
		objGame.Game();					// ������Ϸ
		cout << "�Ƿ�����һ����Ϸ";
		bYes = UserSaysYes();			// �����û��ش�
	} while (bYes);

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}