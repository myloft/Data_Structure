// �ļ�·����: park_dragoman\main.cpp
#include "utility.h"										// ʵ�ó��������
#include "park_dragoman.h"									// �γ̱���

int main(int argc, char *argv[])
{
	try														// ��try��װ���ܳ����쳣�Ĵ���
	{
		char parkInforiileName[256];						// ��԰��Ϣ�ļ���
		
		if (argc > 1) strcpy(parkInforiileName, argv[1]);	// ���������в���
		else strcpy(parkInforiileName, "park_infor.txt");	// �������в���
		ifstream inFile(parkInforiileName);					// �������ļ�
		if (inFile == NULL) throw Error("���ܴ򿪹�԰��Ϣ�ļ�!");	// �׳��쳣
		
		ParkDragoman objParkDragoman(&inFile);				// ������԰���ζ���	
		objParkDragoman.Run();								// ִ�й�԰����
   	}
	catch (Error err)										// ��׽�������쳣
	{	
		err.Show();											// ��ʾ�쳣��Ϣ
	}
	
	system("PAUSE");										// ���ÿ⺯��system()
	return 0;												// ����ֵ0, ���ز���ϵͳ

	
	system("PAUSE");										// ���ÿ⺯��system()
	return 0;												// ����ֵ0, ���ز���ϵͳ
}

