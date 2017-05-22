// �ļ�·����:line_editor\main.cpp
#include "utility.h"					// ʵ�ó��������
#include "line_editor.h"				// �ı��༭��

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		char infName[256], outfName[256];

		cout << "�������ļ���(ȱʡ: file_in.txt):";
		strcpy(infName, Read(cin).CStr());
		if (strlen(infName) == 0)
		{	// infNameΪ��
			strcpy(infName, "file_in.txt");
		}
		
		cout << "������ļ���(ȱʡ: file_out.txt):";
		strcpy(outfName, Read(cin).CStr());
		if (strlen(outfName) == 0)
		{	// outfNameΪ��
			strcpy(outfName, "file_out.txt");
		}

		LineEditor text(infName, outfName);	// �����ı�����
		text.Run();						// ���б༭��
  	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

   	system("PAUSE");        			// ���ÿ⺯��system()
   	return 0;               			// ����ֵ0, ���ز���ϵͳ
}
