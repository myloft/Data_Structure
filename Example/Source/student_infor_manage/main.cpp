// �ļ�·����: student_infor_manage\main.cpp
#include "utility.h"										// ʵ�ó��������
#include "student_infor_manage.h"							// ѧ��������Ϣ������

int main()
{
	try														// ��try��װ���ܳ����쳣�Ĵ���
	{
		StudentInforManage objStudentInforManage;			// ѧ����Ϣ�������
		objStudentInforManage.Run();						// ����ѧ��������Ϣ����
   	}
	catch (Error err)										// ��׽�������쳣
	{	
		err.Show();											// ��ʾ�쳣��Ϣ
	}
	
	system("PAUSE");										// ���ÿ⺯��system()
	return 0;												// ����ֵ0, ���ز���ϵͳ
}

