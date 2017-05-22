// �ļ�·����:my_huffman_tree\main.cpp
#include "utility.h"					// ʵ�ó��������
#include "my_huffman_tree.h"			// ����������

unsigned int CharIndex(const char &ch)
// ����������ַ�λ��ӳ��
{
	unsigned int result;				// ���ؽ��
	if (ch == 'a') result = 1;			// 'a'�洢λ��Ϊ1
	else if (ch == 'b') result = 2;		// 'b'�洢λ��Ϊ2
	else if (ch == 'c') result = 3;		// 'c'�洢λ��Ϊ3
	return result;						// ���ؽ��
}

int main(void)
{
	char ch[] = {'a', 'b', 'c'}; 
	int w[] = {10, 20, 10};
	int n = 3;

	MyHuffmanTree<char, int> hmTree1(ch, w, n, CharIndex);
	MyHuffmanTree<char, int> hmTree(hmTree1);	// ���ƹ��캯��
	hmTree = hmTree1;					// ��ֵ�������
	String strText = "abc";				// �ı���
	String strCode = "10011";			// ���봮

	cout << "�ı���" << strText.CStr() << "����Ϊ:";
	for (int pos = 0; pos < strText.Length(); pos++)
	{
		String strTmp = hmTree.Encode(strText[pos]);
		cout << strTmp.CStr();
	}
	cout << endl;
	system("PAUSE");					// ���ÿ⺯��system()

	cout << "���봮" << strCode.CStr() << "����Ϊ:";
	LinkList<char> lkText = hmTree.Decode(strCode);
	strText = lkText;
	cout << strText.CStr() << endl;

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}
