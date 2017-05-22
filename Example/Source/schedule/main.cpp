// �ļ�·����:schedule\main.cpp
#include "utility.h"										// ʵ�ó��������
#include "schedule.h"										// �γ̱���

int main(int argc, char *argv[])
{
	try														// ��try��װ���ܳ����쳣�Ĵ���
	{

		char inFileName[256],outFileName[256];
		
		if (argc > 1) strcpy(inFileName, argv[1]);			// ���������в���
		else strcpy(inFileName, "course_inf.txt");			// �������в���
		ifstream inFile(inFileName);						// �������ļ�

		if (inFile == 0) throw Error("���ܴ򿪿γ���Ϣ�ļ�!");	// �׳��쳣
   
		if (argc > 2) strcpy(outFileName,argv[2]);			// ���������в���
		else strcpy(outFileName,"curriculum_scedule.txt");	// �������в���
		ofstream outFile(outFileName);						// ������ļ�
		if (outFile == 0)  throw Error("���ܴ򿪿γ̱��ļ�!");	// �׳��쳣

		cout << "�γ���Ϣ�ļ�Ϊ: " << inFileName << endl << endl;
		cout << "�����ſΣ����Ժ�..." << endl << endl;

		Schedule<8> rc(&inFile, &outFile);					// ��ʾ��8ѧ�ڿ�(�ӵ�1ѧ�ڵ���8ѧ��)
		rc.Read();								// ����γ���Ϣ
		rc.TopologicalOrder();					// �������ŵ�˼�����ſ�
		rc.Write();								// ����α�

		cout<<"�ſν������α��ļ�Ϊ: "<<outFileName<<endl;
  	}
	catch (Error err)							// ��׽�������쳣
	{	
		err.Show();								// ��ʾ�쳣��Ϣ
	}
	
	system("PAUSE");							// ���ÿ⺯��system()
	return 0;									// ����ֵ0, ���ز���ϵͳ

	
	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}
