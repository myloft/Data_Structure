// �ļ�·����:my_huffman_compress\main.cpp
#include "utility.h"					// ʵ�ó��������
#include "my_huffman_compress.h"		// ������ѹ���㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		MyHuffmanCompress obj;
		int select = 0;
		while (select != 3)  
		{
			cout << endl << "1. ѹ��";
			cout << endl << "2. ��ѹ��";
			cout << endl << "3. �˳�";
			cout << endl << "��ѡ��:";
			cin >> select;				// ����ѡ��
			while (cin.get() != '\n');	// �����û�����������ַ�

			switch (select)
			{
				case 1:   
					obj.Compress();		// ѹ��
					break;
				case 2:
					obj.Decompress();	// ��ѹ��
			}
		}
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}
