// �ļ�·����:my_huffman_compress\my_huffman_compress.h
#ifndef __MY_HUFFMAN_COMPRESS_H__
#define __MY_HUFFMAN_COMPRESS_H__

#include "my_huffman_tree.h"					// ����������

// �ַ�������
struct BufferType
{	
	char ch;									// �ַ�
	unsigned int bits;							// ʵ�ʱ�����     
};

// ������ѹ����
class MyHuffmanCompress
{
protected:
//  ������ѹ��������ݳ�Ա:
	MyHuffmanTree<char, unsigned long> *pMyHuffmanTree;
	FILE *infp, *outfp;							// ����/���ļ�
	BufferType buf;								// �ַ�����

//	��������:
	void Write(unsigned int bit);				// ��Ŀ���ļ���д��һ������
	void WriteToOutfp();						// ǿ�н��ַ�����д��Ŀ���ļ�

public:
//  ������ѹ���෽�����������ر���ϵͳĬ�Ϸ�������:
	MyHuffmanCompress();						// �޲����Ĺ��캯��
	~MyHuffmanCompress();						// ��������
	void Compress();							// ѹ���㷨
	void Decompress();							// ��ѹ���㷨
};

// ��غ���
unsigned int CharIndex(const char &ch);			// �ַ�λ��ӳ��

// ������ѹ���༰��غ�����ʵ�ֲ���
unsigned int CharIndex(const char &ch)
// ����������ַ�λ��ӳ��
{
	return (unsigned char)ch;
}

MyHuffmanCompress::MyHuffmanCompress()
// �������������һ���յĹ�����ѹ������󡪡��޲����Ĺ��캯��
{
	pMyHuffmanTree = NULL;						// �չ�������
}

MyHuffmanCompress::~MyHuffmanCompress()
// ������������ٹ�����ѹ������󡪡���������
{
	if (pMyHuffmanTree != NULL) delete []pMyHuffmanTree;	// �ͷſռ�
}

void MyHuffmanCompress::Write(unsigned int bit)				
// �����������Ŀ���ļ���д��һ������
{
	buf.bits++;								// �������������1
	buf.ch = (buf.ch << 1) | bit;			// ��bit���뵽�����ַ���
	if (buf.bits == 8)
	{	// ����������,д��Ŀ���ļ�
		fputc(buf.ch, outfp);				// д��Ŀ���ļ�
		buf.bits = 0;						// ��ʼ��bits
		buf.ch = 0;							// ��ʼ��ch
	}
}

void MyHuffmanCompress::WriteToOutfp()			
// ���������ǿ�н��ַ�����д��Ŀ���ļ�
{
	unsigned int len = buf.bits;			// ����ʵ�ʱ�����
	if (len > 0)
	{	// ����ǿ�, ������ı��ظ������ӵ�8, �Զ�д��Ŀ���ļ�
		for (unsigned int i = 0; i < 8 - len; i++) Write(0);
	}
}

void MyHuffmanCompress::Compress()
// ����������ù���������ѹ���ļ�
{
	char infName[256], outfName[256];				// ����(Դ)/��(Ŀ��)�ļ���
	
	cout << "������Դ�ļ���(�ļ�С��4GB):";			// ��ѹ���ļ�С��4GB
	cin >> infName;									// ����Դ�ļ���
	if ((infp = fopen(infName, "rb")) == NULL)
		throw Error("��Դ�ļ�ʧ��!");				// �׳��쳣

    fgetc(infp);									// ȡ��Դ�ļ���һ���ַ�
	if (feof(infp))
		throw Error("��Դ�ļ�!");					// �׳��쳣

	cout << "������Ŀ���ļ�:";
	cin >> outfName;                  
	if ((outfp = fopen(outfName, "wb")) == NULL)
		throw Error("��Ŀ���ļ�ʧ��!");			// �׳��쳣
	
	cout << "���ڴ������Ժ�..." << endl;

	const unsigned long n = 256;					// �ַ�����
    char ch[n];										// �ַ�����
	unsigned long w[n];								// �ַ�����Ƶ��(Ȩ)
	unsigned long i, size = 0;
	char cha;

	for (i = 0; i < n; i++)
	{	// ��ʼ��ch[]��w[]
		ch[i] = (char)i;				// ��ʼ��ch[i]
		w[i] = 0;						// ��ʼ��w[i]
	}

	rewind(infp);						// ʹԴ�ļ�ָ��ָ���ļ���ʼ��
	cha = fgetc(infp);					// ȡ��Դ�ļ���һ���ַ�
	while (!feof(infp))					
	{	// ͳ���ַ�����Ƶ��
		w[(unsigned char)cha]++;		// �ַ�cha����Ƶ���Լ�1
		size++;							// �ļ���С�Լ�1	
		cha=fgetc(infp);				// ȡ��Դ�ļ���һ���ַ�
	}

	if (pMyHuffmanTree != NULL) delete []pMyHuffmanTree;	// �ͷſռ�
	pMyHuffmanTree = new MyHuffmanTree<char, unsigned long>(ch, w, n, CharIndex); 
		// ���ɹ�������
    rewind(outfp);						// ʹĿ���ļ�ָ��ָ���ļ���ʼ��
	fwrite(&size, sizeof(unsigned long), 1, outfp);	// ��Ŀ���ļ�д��Դ�ļ���С
	for (i = 0; i < n; i++)				
	{	// ��Ŀ���ļ�д���ַ�����Ƶ��
		fwrite(&w[i], sizeof(unsigned long), 1, outfp);
	}

	buf.bits = 0;						// ��ʼ��bits
	buf.ch = 0;							// ��ʼ��ch
	rewind(infp);						// ʹԴ�ļ�ָ��ָ���ļ���ʼ��
	cha = fgetc(infp);					// ȡ��Դ�ļ��ĵ�һ���ַ�
    while (!feof(infp))
	{	// ��Դ�ļ��ַ����б��룬��������д��Ŀ���ļ�
		String strTmp = pMyHuffmanTree->Encode(cha);// �ַ�����
		for (i = 0; i < strTmp.Length(); i++)
		{	// ��Ŀ���ļ�д�����
			if (strTmp[i] == '0') Write(0);	// ��Ŀ���ļ�д��0
			else Write(1);				// ��Ŀ���ļ�д��1
		} 
		cha = fgetc(infp);				// ȡ��Դ�ļ�����һ���ַ�
	}
	WriteToOutfp();						// ǿ��д��Ŀ���ļ�
	
	fclose(infp); fclose(outfp);		// �ر��ļ�
	cout << "�������." << endl;
}

void MyHuffmanCompress::Decompress()
// �����������ѹ���ù���������ѹ�����ļ�
{
	char infName[256], outfName[256];					// ����(ѹ��)/��(Ŀ��)�ļ���
	
	cout << "������ѹ���ļ���:";
	cin >> infName;                  
	if ((infp = fopen(infName, "rb")) == NULL)
		throw Error("��ѹ���ļ�ʧ��!");				// �׳��쳣

    fgetc(infp);										// ȡ��ѹ���ļ���һ���ַ�
	if (feof(infp))
		throw Error("ѹ���ļ�Ϊ��!");					// �׳��쳣

	cout << "������Ŀ���ļ���:";
	cin >> outfName;                  
	if ((outfp = fopen(outfName, "wb")) == NULL)
		throw Error("��Ŀ���ļ�ʧ��!");				// �׳��쳣
	
	cout << "���ڴ������Ժ�..." << endl;

	const unsigned long n = 256;						// �ַ�����
    char ch[n];											// �ַ�����
	unsigned long w[n];									// Ȩ
	unsigned long i, size = 0;
	char cha;

	rewind(infp);										// ʹԴ�ļ�ָ��ָ���ļ���ʼ��
	fread(&size, sizeof(unsigned long), 1, infp);		// ��ȡĿ���ļ��Ĵ�С	
	for (i = 0; i < n; i++)
	{
		ch[i] = (char)i;								// ��ʼ��ch[i]
		fread(&w[i], sizeof(unsigned long), 1, infp);	// ��ȡ�ַ�Ƶ��
	}
	if (pMyHuffmanTree != NULL) delete []pMyHuffmanTree;// �ͷſռ�
	pMyHuffmanTree = new MyHuffmanTree<char, unsigned long>(ch, w, n, CharIndex); 
		// ���ɹ�������

	unsigned long len = 0;						// ��ѹ���ַ���
	cha = fgetc(infp);							// ȡ��Դ�ļ��ĵ�һ���ַ�
	while (!feof(infp))
	{	// ��ѹ���ļ��ַ����н��룬����������ַ�д��Ŀ���ļ�
		String strTmp = "";						// ��chaת����������ʽ�Ĵ�
		unsigned char c = (unsigned char)cha;	// ��chaת����unsigned char����
		for (i = 0; i < 8; i++)
		{	// ��cת���ɶ����ƴ�
			if (c < 128) Concat(strTmp, "0");	// ���λΪ0
			else Concat(strTmp, "1");			// ���λΪ1
			c = c << 1;							// ����һλ
		}

		LinkList<char> lkText = pMyHuffmanTree->Decode(strTmp);// ����
		String strTemp(lkText);
		for (i = 0; i < strTemp.Length(); i++)
		{	// ��Ŀ���ļ�д���ַ�
			len++;								// Ŀ���ļ������Լ�1
			fputc(strTemp[i], outfp);			// ���ַ�д��Ŀ���ļ���
			if (len == size) break;				// ��ѹ����˳���ѭ��
		} 
		if (len == size) break;					// ��ѹ����˳���ѭ��
		cha = fgetc(infp);						// ȡ��Դ�ļ�����һ���ַ�
	}

	fclose(infp); fclose(outfp);				// �ر��ļ�
	cout << "�������." << endl;
}

#endif
