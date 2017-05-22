// �ļ�·����: my_hash_table\main.cpp
#include "utility.h"						// ʵ�ó��������
#include "my_hash_table.h"					// ɢ�б���

int main(void)
{
    try										// ��try��װ���ܳ����쳣�Ĵ���
	{
		int elems[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79};
		int n = 12;							// Ԫ�ظ���
		int m = 6;							// ɢ�б���
		MyHashTable<int, int> ht(m);		// ɢ�б�	
		
		for (int i = 0; i < n; i++)
			ht.Insert(elems[i]);			// ������

		cout << "����Hash��:" << endl;
	    ht.Traverse(Write);
		cout << endl;
		system("PAUSE");					// ���ÿ⺯��system()	
		
		int e = 79;
		ht.Delete(e);						// ɾ��
		cout << "ɾ��79��:" << endl;
	    ht.Traverse(Write);
		cout << endl;
		system("PAUSE");					// ���ÿ⺯��system()

		MyHashTable<int, int> htNew(ht);	// ���ƹ�����ɢ�б�
		cout << "���ƹ�����Hash��:" << endl;
	    htNew.Traverse(Write);
		cout << endl;
		system("PAUSE");					// ���ÿ⺯��system()

		htNew = ht;							// ��ֵ������ɢ�б�
		cout << "��ֵ������Hash��:" << endl;
	    htNew.Traverse(Write);
		cout << endl;
	}
	catch (Error err)						// ��׽�������쳣
	{
		err.Show();							// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");						// ���ÿ⺯��system()
	return 0;								// ����ֵ0, ���ز���ϵͳ
}



