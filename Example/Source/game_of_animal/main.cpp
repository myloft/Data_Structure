// �ļ�·����: game_of_animal\main.cpp
#include "utility.h"										// ʵ�ó��������
#include "game_of_animal.h"									// ������Ϸ��

int main()
{
	try														// ��try��װ���ܳ����쳣�Ĵ���
	{
		GameOfAnimal objGameOfAnimal;						// ������Ϸ����
		objGameOfAnimal.Run();								// ���ж�����Ϸ
   	}
	catch (Error err)										// ��׽�������쳣
	{	
		err.Show();											// ��ʾ�쳣��Ϣ
	}
	
	system("PAUSE");										// ���ÿ⺯��system()
	return 0;												// ����ֵ0, ���ز���ϵͳ
}

