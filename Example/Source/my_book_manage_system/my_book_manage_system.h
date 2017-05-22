// �ļ�·����: my_book_manage\my_book_manage.h
#ifndef __MY_BOOK_MANAGE_SYSTEM_H__
#define __MY_BOOK_MANAGE_SYSTEM_H__

#include "bin_serach.h"					// ���ֲ����㷨
#include "quick_sort.h"					// ��������

// ����
struct DateType
{
	int year, month, day;				// ��,�º���
};

// ͼ��ṹ
struct BookType
{	
	char num[14];						// ���
	char title[21];						// ����
	long titleNext;						// ������ͬ����һ����
	char author[11];					// ������
	float price;						// �۸�
	DateType buyDate;					// ��������
	bool isDeleted;						// ɾ�����
};

// ���������������Ҫ�Ĺ�ϵ�����
bool operator <=(const BookType &first, const BookType &second);	// ���ع�ϵ�����<=
bool operator >=(const BookType &first, const BookType &second);	// ���ع�ϵ�����>=

// ���������ṹ
struct NumIndexItemType
{
	char num[14];						// ���
	long offset;						// ��Ӧ��¼�����ļ��е�λ��
};

// ���������������Ҫ�Ĺ�ϵ�����
bool operator <=(const char num[14], const NumIndexItemType &item);
	// ���ع�ϵ�����<=
bool operator <(const char num[14], const NumIndexItemType &item);
	// ���ع�ϵ�����<
bool operator ==(const char num[14], const NumIndexItemType &item);
	// ���ع�ϵ�����==

// ������������ṹ
struct TitleIndexItemType
{
	char title[21];						// ����
	long head;							// ͷָ��
};

// ���������������Ҫ�Ĺ�ϵ�����
bool operator <=(const char title[21], const TitleIndexItemType &item);	// ���ع�ϵ�����<=
bool operator <(const char title[21], const TitleIndexItemType &item);	// ���ع�ϵ�����<
bool operator ==(const char title[21], const TitleIndexItemType &item);	// ���ع�ϵ�����==

static const long INCREMENT_OF_INDEX_TABLE = 100;// ����������

// ����ͼ�����ϵͳ��
class MyBookManageSystem
{
private:
// ���ݳ�Ա
	fstream bookFile;					// ͼ���ļ�
	NumIndexItemType *pNumIndexTable;	// �����������
	long sizeOfNumIndex;				// �����������ǰ��������
	long maxSizeOfNumIndex;				// ����������������������
	TitleIndexItemType *pTitleIndexTable;// ������������
	long sizeOfTitleIndex;				// ������������ǰ��������
	long maxSizeOfTitleIndex;			// �����������������������

// ��������
	void Display(const BookType &book) const;		// ��ʾͼ����Ϣ
	void InsertHelp(BookType &book, long offset);	// �����¼��������
	void Insert();						// �����¼
	void DeleteHelp(BookType &book, long offset);	// ɾ����¼��������
	void Delete();						// ɾ����¼
	void Update();						// ���¼�¼
	void SerachByTile() ;				// ��������ѯ��¼
	void SerachByAuthor() ;				// ����������ѯ��¼
	void Serach() ;						// ��ѯ��¼
	void SortByAuthor() ;				// ������������
	
public:
// ���캯��, ���������뷽��
	MyBookManageSystem();				// �޲����Ĺ��캯��
	virtual ~MyBookManageSystem();		// ��������
	void Run();							// ����ͼ��
};

// ����ͼ�����ϵͳ�༰��غ�����ʵ��
bool operator <=(const BookType &first, const BookType &second)
// �������: ���ع�ϵ�����<=
{
	return strcmp(first.author, second.author) <= 0;
}

bool operator >=(const BookType &first, const BookType &second)
// �������: ���ع�ϵ�����>=
{
	return strcmp(first.author, second.author) >= 0;
}

bool operator <=(const char num[14], const NumIndexItemType &item)
// �������: ���ع�ϵ�����<=
{
	return strcmp(num, item.num) <= 0;
}

bool operator <(const char num[14], const NumIndexItemType &item)
// �������: ���ع�ϵ�����<
{
	return strcmp(num, item.num) < 0;
}

bool operator ==(const char num[14], const NumIndexItemType &item)
// �������: ���ع�ϵ�����==
{
	return strcmp(num, item.num) == 0;
}

bool operator <=(const char title[21], const TitleIndexItemType &item)
// �������: ���ع�ϵ�����<=
{
	return strcmp(title, item.title) <= 0;
}

bool operator <(const char title[21], const TitleIndexItemType &item)
// �������: ���ع�ϵ�����<
{
	return strcmp(title, item.title) < 0;
}

bool operator ==(const char title[21], const TitleIndexItemType &item)
// �������: ���ع�ϵ�����==
{
	return strcmp(title, item.title) == 0;
}

void MyBookManageSystem::Display(const BookType &book) const
// �������: ��ʾͼ����Ϣ
{
	cout << setw(14) << book.num << setw(21) << book.title 
		<< setw(11) << book.author << setw(8) << book.price 
		<< setw(6) << book.buyDate.year << "-" << setw(2) << book.buyDate.month << "-" 
		<< setw(2) << book.buyDate.day << endl;
}

void MyBookManageSystem::InsertHelp(BookType &book, long offset)
// �������: ���븨������, bookΪҪ����ļ�¼,offsetΪ��¼�����ļ��еĲ���λ��
{
	if (sizeOfNumIndex >= maxSizeOfNumIndex)
	{	// ������������Ѵﵽ�������
		maxSizeOfNumIndex += INCREMENT_OF_INDEX_TABLE;		// �����������
		NumIndexItemType *pTmp;						// ��ʱ������
		pTmp = new NumIndexItemType[maxSizeOfNumIndex];		// ���·���洢�ռ�
		for (int pos = 0; pos < maxSizeOfNumIndex; pos++)
			pTmp[pos] = pNumIndexTable[pos];		// ����������
		delete []pNumIndexTable;					// �ͷ�pNumIndexTable
		pNumIndexTable = pTmp;						// pNumIndexTableָ���´洢�ռ�
	}
	int j;											// ��ʱ����
	for (j = sizeOfNumIndex - 1; j >= 0 && book.num < pNumIndexTable[j]; j--)
	{	// ����book.num�����������������
		pNumIndexTable[j + 1] = pNumIndexTable[j];
	}
	strcpy(pNumIndexTable[j + 1].num, book.num);	// ѧ��
	pNumIndexTable[j + 1].offset = offset;			// ��¼�����ļ��е���Ӧλ��
	sizeOfNumIndex++;								// ���������������Լ�1

	if (sizeOfTitleIndex >= maxSizeOfTitleIndex)
	{	// �������������Ѵﵽ�������
		maxSizeOfTitleIndex += INCREMENT_OF_INDEX_TABLE;	// �����������
		TitleIndexItemType *pTmp;					// ��ʱ������
		pTmp = new TitleIndexItemType[maxSizeOfTitleIndex];	// ���·���洢�ռ�
		for (int pos = 0; pos < sizeOfTitleIndex; pos++)
			pTmp[pos] = pTitleIndexTable[pos];		// ����������
		delete []pTitleIndexTable;					// �ͷ�pNumIndexTable
		pTitleIndexTable = pTmp;					// pNumIndexTableָ���´洢�ռ�
	}
	int pos = BinSerach(pTitleIndexTable, sizeOfTitleIndex, book.title);// ���ֲ���
	if (pos == -1)
	{	// ����ʧ��
		for (j = sizeOfTitleIndex - 1; j >= 0 && book.title < pTitleIndexTable[j]; j--)
		{	// ����book.title������������������
			pTitleIndexTable[j + 1] = pTitleIndexTable[j];
		}
		strcpy(pTitleIndexTable[j + 1].title, book.title);// ����
		pTitleIndexTable[j + 1].head = offset;		// ��¼�����ļ��е���Ӧλ��
		sizeOfTitleIndex++;							// ����������������Լ�1
		book.titleNext = -1;						// ��������ֻ��һ�����, �޺��
	}
	else
	{	// ���ҳɹ�
		book.titleNext = pTitleIndexTable[pos].head;// book���ΪpTitleIndexTable[pos].head
		pTitleIndexTable[pos].head = offset;		// bookΪ���������1���
	}
}

void MyBookManageSystem::Insert()
// �������: �����¼
{
	BookType book;										// ͼ���¼
	book.isDeleted = false;								// ɾ�����

	cout << "�������:";
	cin >> book.num;
	cout << "��������:";
	cin >> book.title;
	cout << "����������:";
	cin >> book.author;
	cout << "����۸�:";
	cin >> book.price;
	cout << "���빺������:";
	cin >> book.buyDate.year >> book.buyDate.month >> book.buyDate.day;
	while (GetChar() != '\n');							// ������ǰ�е������ַ�

	if (BinSerach(pNumIndexTable, sizeOfNumIndex, book.num) >= 0)
	{	// ����ظ�
		cout << "����ظ�, ����ʧ��!" << endl;
	}
	else
	{	// ����ɹ�
		bookFile.clear();								// �����־	
		bookFile.seekg(0, ios::end);					// ��λ���ļ�β
		long offset = bookFile.tellg();					// ���ļ���¼����λ��
		InsertHelp(book, offset);						// ���������в���������
		bookFile.write((char *)&book, sizeof(BookType));// д���ļ�
		cout << "����ɹ�!" << endl;
	}
}

void MyBookManageSystem::DeleteHelp(BookType &book, long offset)
// �������: ɾ����¼��������
{
	int pos = BinSerach(pNumIndexTable, sizeOfNumIndex, book.num);// ���ֲ���
	for (int i = pos + 1; i < sizeOfNumIndex; i++)
	{	// ���������������ɾ��������
		pNumIndexTable[i - 1] = pNumIndexTable[i];
	}
	sizeOfNumIndex--;						// ���������������Լ�1

	pos = BinSerach(pTitleIndexTable, sizeOfTitleIndex, book.title);// ���ֲ���
	long pre = -1, p = pTitleIndexTable[pos].head;	// pָ��ǰ��¼,  preָ��ǰ����¼
	BookType tmp;							// ��ʱ����
	while (p != offset)
	{	// pre��p������
		pre = p;							// pΪpre�ĺ��	
		bookFile.clear();					// �����־	
		bookFile.seekg(p, ios::beg);		// �ļ���λ
		bookFile.read((char *)&tmp, sizeof(BookType));// �����ļ�
		p = tmp.titleNext;					// p������
	}
	if (pre == -1)
	{	// bookΪ����ĵ�1�����
		pTitleIndexTable[pos].head = book.titleNext;	// book���Ϊ��1���
	}
	else
	{	// book��Ϊ��������ĵ�1�����
		bookFile.clear();					// �����־	
		bookFile.seekg(pre, ios::beg);		// �ļ���λ
		bookFile.read((char *)&tmp, sizeof(BookType));// �����ļ�
		tmp.titleNext = book.titleNext;		//pre��̸�Ϊbook�ĺ��
		bookFile.clear();					// �����־	
		bookFile.seekg(pre, ios::beg);		// �ļ���λ
		bookFile.write((char *)&tmp, sizeof(BookType));// д���ļ�
	}
}

void MyBookManageSystem::Delete()
// �������: ɾ����¼
{
	char num[14];							// ���
	cout << "�������:";
	cin >> num;
	while (GetChar() != '\n');				// ������ǰ�е������ַ�
	int pos = BinSerach(pNumIndexTable, sizeOfNumIndex, num);// ���ֲ���
	if (pos == -1)
	{	// ����ʧ��
		cout << "���޴����!" << endl;
	}
	else
	{	// ���ҳɹ�
		BookType book;						// ͼ���¼
		long offset = pNumIndexTable[pos].offset;	// ��¼�����ļ��е�λ��
		bookFile.clear();					// �����־	
		bookFile.seekg(offset, ios::beg);	// ��λ�ļ�
		bookFile.read((char *)&book, sizeof(BookType));// �����ļ�
		cout << setw(14) << "���" << setw(21) << "����" << setw(11) << "������" << 
			setw(8) << "�۸�" << setw(12) << "��������" << endl;
		Display(book);						// ��ʾͼ����Ϣ
		DeleteHelp(book, offset);			// ɾ����������
		bookFile.clear();					// �����־	
		bookFile.seekg(offset, ios::beg);	// ��λ�ļ�
		book.isDeleted = true;				// ɾ�����
		bookFile.write((char *)&book, sizeof(BookType));//д���ļ�
		cout << "ɾ���ɹ�!" << endl;
	}
}

void MyBookManageSystem::Update()
// �������: ���¼�¼
{
	char num[14];							// ���
	cout << "�������:";
	cin >> num;
	while (GetChar() != '\n');				// ������ǰ�е������ַ�
	int pos = BinSerach(pNumIndexTable, sizeOfNumIndex, num);// ���ֲ���
	if (pos == -1)
	{	// ����ʧ��
		cout << "���޴����!" << endl;
	}
	else
	{	// ���ҳɹ�
		BookType bookOld, bookNew;					// ͼ���¼
		long offset = pNumIndexTable[pos].offset;	// ��¼�����ļ��е�λ��
		bookFile.clear();							// �����־	
		bookFile.seekg(offset, ios::beg);			// �ļ���λ
		bookFile.read((char *)&bookOld, sizeof(BookType));// �����ļ�
		cout << setw(14) << "���" << setw(21) << "����" << setw(11) << "������" << 
			setw(8) << "�۸�" << setw(12) << "��������" << endl;
		Display(bookOld);							// ��ʾͼ����Ϣ
		bookNew.isDeleted = false;					// ɾ�����
		cout << "�������:";
		cin >> bookNew.num;
		cout << "��������:";
		cin >> bookNew.title;
		cout << "����������:";
		cin >> bookNew.author;
		cout << "����۸�:";
		cin >> bookNew.price;
		cout << "���빺������:";
		cin >> bookNew.buyDate.year >> bookNew.buyDate.month >> bookNew.buyDate.day;
		while (GetChar() != '\n');					// ������ǰ�е������ַ�

		if (strcmp(bookNew.num, pNumIndexTable[pos].num) == 0)
		{	// ���û�б仯
			DeleteHelp(bookOld, offset);			// ����ɾ������,ɾ�����������Ӧ������
			InsertHelp(bookNew, offset);			// �����������,�������в�����Ӧ������
			bookFile.clear();						// �����־	
			bookFile.seekg(offset, ios::beg);		// �ļ���λ
			bookFile.write((char *)&bookNew, sizeof(BookType));		// д���ļ�
			cout << "���³ɹ�!" << endl;
		}
		else
		{	// ����ѷ����仯
			if (BinSerach(pNumIndexTable, sizeOfNumIndex, bookNew.num) >= 0)
			{	// ���º�, ����ظ�
				cout << "����ظ�, ����ʧ��!" << endl;
			}
			else
			{
				DeleteHelp(bookOld, offset);		// ����ɾ������,ɾ�����������Ӧ������
				InsertHelp(bookNew, offset);		// �����������,�������в�����Ӧ������
				bookFile.clear();					// �����־	
				bookFile.seekg(offset, ios::beg);	// �ļ���λ
				bookFile.write((char *)&bookNew, sizeof(BookType));	// д���ļ�
				cout << "���³ɹ�!" << endl;
			}
		}
	}
}

void MyBookManageSystem::SerachByTile() 
// �������: ��������ѯ��¼
{

	char title[21];												// ����
	cout << "��������:";
	cin >> title;
	int pos = BinSerach(pTitleIndexTable, sizeOfTitleIndex, title);	// ���ֲ���
	if (pos == -1)
	{	// ����ʧ��
		cout << "���޴���!" << endl;
	}
	else
	{	// ���ҳɹ�
		BookType book;											// ͼ���¼
		cout << setw(14) << "���" << setw(21) << "����" << setw(11) << "������" << 
			setw(8) << "�۸�" << setw(12) << "��������" << endl;
		long offset = pTitleIndexTable[pos].head;				// ��¼�����ļ��е�λ��
		while (offset != -1)
		{
			bookFile.clear();									// �����־	
			bookFile.seekg(offset, ios::beg);					// ��λ�ļ�
			bookFile.read((char *)&book, sizeof(BookType));		// �����ļ�
			Display(book);										// ��ʾͼ����Ϣ
			offset = book.titleNext;							// ��һͬ��ͼ��
		}
	}
}

void MyBookManageSystem::SerachByAuthor() 
// �������: ����������ѯ��¼
{
	char author[11];											// ������
	cout << "����������:";
	cin >> author;
	BookType book;												// ͼ���¼
	bookFile.clear();											// �����־	
	bookFile.seekg(0, ios::end);								// ��λ���ļ�β
	long endOffset = bookFile.tellg();							// �ļ�βλ��
	cout << setw(14) << "���" << setw(21) << "����" << setw(11) << "������" << 
		setw(8) << "�۸�" << setw(12) << "��������" << endl;
	bookFile.clear();											// �����־	
	bookFile.seekg(0, ios::beg);								// ��λ���ļ�ͷ
	do
	{
		bookFile.read((char *)&book, sizeof(BookType));			// �����ļ�
		if (strcmp(book.author, author) == 0) Display(book);	// ��ʾͼ����Ϣ
	}
	while (endOffset != bookFile.tellg());
}

void MyBookManageSystem::Serach() 
// �������: ���Ҽ�¼
{
	int select;									// ��ʱ����
	do
	{
		cout << "1.������������ 2.�������������� 3.�˳�����" << endl;
		cout << "����ѡ��:";
		cin >> select;							// ����ѡ��
		while (GetChar() != '\n');				// ������ǰ�е������ַ�
		
		switch (select)
		{
		case 1:
			SerachByTile();						// ������������
			break;
		case 2:
			SerachByAuthor();					// ��������������
			break;
		}
	} while (select != 3);
}

void MyBookManageSystem::SortByAuthor() 
// �������: ������������
{
	BookType *books = new BookType[sizeOfNumIndex];	// ͼ������
	BookType book;									// ͼ���¼
	bookFile.clear();								// �����־	
	bookFile.seekg(0, ios::end);					// ��λ���ļ�β
	long endOffset = bookFile.tellg();				// �ļ�βλ��
	bookFile.clear();								// �����־	
	bookFile.seekg(0, ios::beg);					// ��λ���ļ�ͷ
	int n = 0;										// ��ǰ������δ��ɾ���ļ�¼��
	do
	{
		bookFile.read((char *)&book, sizeof(BookType));		// �����ļ�
		if (!book.isDeleted) 
		{	// ��δ��ɾ���ļ�¼����books
			books[n++] = book;
		}
	}
	while (endOffset != bookFile.tellg());
	QuickSort(books, n);							// ��������
	bookFile.clear();								// �����־	
	bookFile.seekg(0, ios::beg);					// ��λ���ļ�ͷ

	sizeOfNumIndex = sizeOfTitleIndex = 0;			// ���������
	cout << setw(14) << "���" << setw(21) << "����" << setw(11) << "������" << 
		setw(8) << "�۸�" << setw(12) << "��������" << endl;
	for (int pos = 0; pos < n; pos++)
	{	// ���ν�books[]�еļ�¼д��bookFile

		long offset = bookFile.tellg();				// ��¼����λ��
		InsertHelp(books[pos], offset);				// ���������в���books[pos]
		bookFile.write((char *)&books[pos], sizeof(BookType));	// д���ļ�
		Display(books[pos]);						// ��ʾͼ����Ϣ
	}
}

MyBookManageSystem::MyBookManageSystem()
// �������: ��ʼ������ͼ�����ϵͳ
{
	ifstream iFile("book.dat");									// ���������ļ�
	if (iFile.fail())
	{	// ���ļ�ʧ��,��ʾ�������ļ�
		ofstream oFile("book.dat");								// ��������ļ�
		if (oFile.fail()) throw("���ļ�ʧ��!");				// �׳��쳣 
		oFile.close();											// �ر��ļ�
	}
	else
	{	// �����ļ�
		iFile.close();											// �ر��ļ�
	}

	bookFile.open("book.dat", ios::in|ios::out|ios::binary);	// �Զ�д��ʽ���ļ�
	if (bookFile.fail()) throw("���ļ�ʧ��!");				// �׳��쳣 
	
	ifstream numIndexFile("num.idx", ios::in|ios::binary);		// ����������ļ�
	if (numIndexFile.fail()) throw("���ļ�ʧ��!");			// �׳��쳣 

	ifstream titleIndexFile("title.idx", ios::in|ios::binary);	// �����������ļ�
	if (titleIndexFile.fail()) throw("���ļ�ʧ��!");			// �׳��쳣 
	

	int pos;													// ��ʱ����

	numIndexFile.clear();										// �����־	
	numIndexFile.seekg(0, ios::end);							// ��λ���ļ�β
	sizeOfNumIndex = numIndexFile.tellg() / sizeof(NumIndexItemType);	// �����������ǰ��������
	maxSizeOfNumIndex = sizeOfNumIndex + INCREMENT_OF_INDEX_TABLE;		// ����������������������
	pNumIndexTable = new NumIndexItemType[maxSizeOfNumIndex];			// ����洢�ռ�
	numIndexFile.clear();										// �����־	
	numIndexFile.seekg(0, ios::beg);							// ��λ���ļ�ͷ
	for (pos = 0; pos < sizeOfNumIndex; pos++)
	{	// ���������������
		numIndexFile.read((char *)&pNumIndexTable[pos], sizeof(NumIndexItemType));	// �������������
	}

	titleIndexFile.clear();										// �����־	
	titleIndexFile.seekg(0, ios::end);							// ��λ���ļ�β
	sizeOfTitleIndex = titleIndexFile.tellg() / sizeof(TitleIndexItemType);	// ������������ǰ��������
	maxSizeOfTitleIndex = sizeOfTitleIndex + INCREMENT_OF_INDEX_TABLE;		// �����������������������
	pTitleIndexTable = new TitleIndexItemType[maxSizeOfTitleIndex];			// ����洢�ռ�
	titleIndexFile.clear();										// �����־	
	titleIndexFile.seekg(0, ios::beg);							// ��λ���ļ�ͷ
	for (pos = 0; pos < sizeOfTitleIndex; pos++)
	{	// ����������������
		titleIndexFile.read((char *)&pTitleIndexTable[pos], sizeof(TitleIndexItemType));// ��������������
	}
	numIndexFile.close(); titleIndexFile.close();				// �ر������ļ�
}

MyBookManageSystem::~MyBookManageSystem()
// �������: �ر����ļ�,д�����ļ�,�ͷ�������
{
	bookFile.close();											// �ر��ļ�

	int pos;													// ��ʱ����
	fstream numIndexFile("num.idx", ios::out|ios::binary);		// ����������ļ�
	numIndexFile.clear();										// �����־	
	numIndexFile.seekg(0, ios::beg);							// ��λ���ļ�ͷ
	for (pos = 0; pos < sizeOfNumIndex; pos++)
	{	// дȡ�����������
		numIndexFile.write((char *)&pNumIndexTable[pos], sizeof(NumIndexItemType));	// д�����������
	}

	fstream titleIndexFile("title.idx", ios::out|ios::binary);	// �����������ļ�
	titleIndexFile.clear();										// �����־	
	titleIndexFile.seekg(0, ios::beg);							// ��λ���ļ�ͷ
	for (pos = 0; pos < sizeOfTitleIndex; pos++)
	{	// дȡ������������
		titleIndexFile.write((char *)&pTitleIndexTable[pos], sizeof(TitleIndexItemType));	// д������������
	}

	numIndexFile.close(); titleIndexFile.close();				// �ر�����������ļ�
	delete []pNumIndexTable;delete []pTitleIndexTable;			// �ͷŴ洢�ռ�
}

void MyBookManageSystem::Run()
// �������: ���и���ͼ�����ϵͳ��
{
	int select;									// ��ʱ����
	do
	{
		cout << "1.�����¼ 2.ɾ����¼ 3.���¼�¼ 4.���Ҽ�¼ 5.������������ 6.�˳�" << endl;
		cout << "����ѡ��:";
		cin >> select;							// ����ѡ��
		while (GetChar() != '\n');				// ������ǰ�е������ַ�
		
		switch (select)
		{
		case 1:
			Insert();							// �����¼
			break;
		case 2:
			Delete();							// ɾ����¼
			break;
		case 3:
			Update();							// ���¼�¼
			break;
		case 4:
			Serach();							// ���Ҽ�¼
			break;
		case 5:
			SortByAuthor();						// ������������
			break;
		}
	} while (select != 6);
}

#endif
