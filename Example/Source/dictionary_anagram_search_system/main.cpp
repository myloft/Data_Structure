// �ļ�·����: dictionary_anagram_search_system\main.cpp
#include "utility.h"							// ʵ�ó��������ͷ�ļ�
#include "dictionary_anagram_search_system.h"	// �ʵ��λ�ʼ���ϵͳ

int main(void)									// ������main(void)
{
	try											// ��try��װ���ܳ����쳣�Ĵ���
	{
		DictionaryAnagramSearchSystem objDicAnaSearch;	// �ʵ��λ�ʼ���ϵͳ����
		objDicAnaSearch.Run();					// ���дʵ��λ�ʼ���ϵͳ
  	}
	catch (Error err)							// ��׽�������쳣
	{
		err.Show();								// ��ʾ�쳣��Ϣ
	}

    system("PAUSE");							// ���ÿ⺯��system()
    return 0; 									// ����ֵ0
}

