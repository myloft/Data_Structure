// 文件路径名: my_book_manage\my_book_manage.h
#ifndef __MY_BOOK_MANAGE_SYSTEM_H__
#define __MY_BOOK_MANAGE_SYSTEM_H__

#include "bin_serach.h"					// 二分查找算法
#include "quick_sort.h"					// 快速排序

// 日期
struct DateType
{
	int year, month, day;				// 年,月和日
};

// 图书结构
struct BookType
{	
	char num[14];						// 书号
	char title[21];						// 书名
	long titleNext;						// 书名相同的下一本书
	char author[11];					// 作者名
	float price;						// 价格
	DateType buyDate;					// 购买日期
	bool isDeleted;						// 删除标记
};

// 重载排序与查找需要的关系运算符
bool operator <=(const BookType &first, const BookType &second);	// 重载关系运算符<=
bool operator >=(const BookType &first, const BookType &second);	// 重载关系运算符>=

// 书号索引项结构
struct NumIndexItemType
{
	char num[14];						// 书号
	long offset;						// 对应记录在主文件中的位置
};

// 重载排序与查找需要的关系运算符
bool operator <=(const char num[14], const NumIndexItemType &item);
	// 重载关系运算符<=
bool operator <(const char num[14], const NumIndexItemType &item);
	// 重载关系运算符<
bool operator ==(const char num[14], const NumIndexItemType &item);
	// 重载关系运算符==

// 书名次索引项结构
struct TitleIndexItemType
{
	char title[21];						// 书名
	long head;							// 头指针
};

// 重载排序与查找需要的关系运算符
bool operator <=(const char title[21], const TitleIndexItemType &item);	// 重载关系运算符<=
bool operator <(const char title[21], const TitleIndexItemType &item);	// 重载关系运算符<
bool operator ==(const char title[21], const TitleIndexItemType &item);	// 重载关系运算符==

static const long INCREMENT_OF_INDEX_TABLE = 100;// 索引表增量

// 个人图书管理系统类
class MyBookManageSystem
{
private:
// 数据成员
	fstream bookFile;					// 图书文件
	NumIndexItemType *pNumIndexTable;	// 书号主索引表
	long sizeOfNumIndex;				// 书号主索引表当前索引项数
	long maxSizeOfNumIndex;				// 书号主索引表最大索引项数
	TitleIndexItemType *pTitleIndexTable;// 书名次索引表
	long sizeOfTitleIndex;				// 书名次索引表当前索引项数
	long maxSizeOfTitleIndex;			// 书名次索引表最大索引项数

// 辅助函数
	void Display(const BookType &book) const;		// 显示图书信息
	void InsertHelp(BookType &book, long offset);	// 插入记录辅助函数
	void Insert();						// 插入记录
	void DeleteHelp(BookType &book, long offset);	// 删除记录辅助函数
	void Delete();						// 删除记录
	void Update();						// 更新记录
	void SerachByTile() ;				// 按书名查询记录
	void SerachByAuthor() ;				// 按作者名查询记录
	void Serach() ;						// 查询记录
	void SortByAuthor() ;				// 按作者名排序
	
public:
// 构造函数, 析构函数与方法
	MyBookManageSystem();				// 无参数的构造函数
	virtual ~MyBookManageSystem();		// 析构函数
	void Run();							// 处理图书
};

// 个人图书管理系统类及相关函数的实现
bool operator <=(const BookType &first, const BookType &second)
// 操作结果: 重载关系运算符<=
{
	return strcmp(first.author, second.author) <= 0;
}

bool operator >=(const BookType &first, const BookType &second)
// 操作结果: 重载关系运算符>=
{
	return strcmp(first.author, second.author) >= 0;
}

bool operator <=(const char num[14], const NumIndexItemType &item)
// 操作结果: 重载关系运算符<=
{
	return strcmp(num, item.num) <= 0;
}

bool operator <(const char num[14], const NumIndexItemType &item)
// 操作结果: 重载关系运算符<
{
	return strcmp(num, item.num) < 0;
}

bool operator ==(const char num[14], const NumIndexItemType &item)
// 操作结果: 重载关系运算符==
{
	return strcmp(num, item.num) == 0;
}

bool operator <=(const char title[21], const TitleIndexItemType &item)
// 操作结果: 重载关系运算符<=
{
	return strcmp(title, item.title) <= 0;
}

bool operator <(const char title[21], const TitleIndexItemType &item)
// 操作结果: 重载关系运算符<
{
	return strcmp(title, item.title) < 0;
}

bool operator ==(const char title[21], const TitleIndexItemType &item)
// 操作结果: 重载关系运算符==
{
	return strcmp(title, item.title) == 0;
}

void MyBookManageSystem::Display(const BookType &book) const
// 操作结果: 显示图书信息
{
	cout << setw(14) << book.num << setw(21) << book.title 
		<< setw(11) << book.author << setw(8) << book.price 
		<< setw(6) << book.buyDate.year << "-" << setw(2) << book.buyDate.month << "-" 
		<< setw(2) << book.buyDate.day << endl;
}

void MyBookManageSystem::InsertHelp(BookType &book, long offset)
// 操作结果: 插入辅助函数, book为要插入的记录,offset为记录在主文件中的插入位置
{
	if (sizeOfNumIndex >= maxSizeOfNumIndex)
	{	// 书号主索引项已达到最大容量
		maxSizeOfNumIndex += INCREMENT_OF_INDEX_TABLE;		// 扩大最大容量
		NumIndexItemType *pTmp;						// 临时索引表
		pTmp = new NumIndexItemType[maxSizeOfNumIndex];		// 重新分配存储空间
		for (int pos = 0; pos < maxSizeOfNumIndex; pos++)
			pTmp[pos] = pNumIndexTable[pos];		// 复制索引项
		delete []pNumIndexTable;					// 释放pNumIndexTable
		pNumIndexTable = pTmp;						// pNumIndexTable指向新存储空间
	}
	int j;											// 临时变量
	for (j = sizeOfNumIndex - 1; j >= 0 && book.num < pNumIndexTable[j]; j--)
	{	// 将比book.num大的书号主索引项后移
		pNumIndexTable[j + 1] = pNumIndexTable[j];
	}
	strcpy(pNumIndexTable[j + 1].num, book.num);	// 学号
	pNumIndexTable[j + 1].offset = offset;			// 记录在主文件中的相应位置
	sizeOfNumIndex++;								// 书号主索引项个数自加1

	if (sizeOfTitleIndex >= maxSizeOfTitleIndex)
	{	// 书名次索引项已达到最大容量
		maxSizeOfTitleIndex += INCREMENT_OF_INDEX_TABLE;	// 扩大最大容量
		TitleIndexItemType *pTmp;					// 临时索引表
		pTmp = new TitleIndexItemType[maxSizeOfTitleIndex];	// 重新分配存储空间
		for (int pos = 0; pos < sizeOfTitleIndex; pos++)
			pTmp[pos] = pTitleIndexTable[pos];		// 复制索引项
		delete []pTitleIndexTable;					// 释放pNumIndexTable
		pTitleIndexTable = pTmp;					// pNumIndexTable指向新存储空间
	}
	int pos = BinSerach(pTitleIndexTable, sizeOfTitleIndex, book.title);// 二分查找
	if (pos == -1)
	{	// 查找失败
		for (j = sizeOfTitleIndex - 1; j >= 0 && book.title < pTitleIndexTable[j]; j--)
		{	// 将比book.title大的书名次索引项后移
			pTitleIndexTable[j + 1] = pTitleIndexTable[j];
		}
		strcpy(pTitleIndexTable[j + 1].title, book.title);// 书名
		pTitleIndexTable[j + 1].head = offset;		// 记录在主文件中的相应位置
		sizeOfTitleIndex++;							// 书名次索引项个数自加1
		book.titleNext = -1;						// 书名链表只有一个结点, 无后继
	}
	else
	{	// 查找成功
		book.titleNext = pTitleIndexTable[pos].head;// book后继为pTitleIndexTable[pos].head
		pTitleIndexTable[pos].head = offset;		// book为书名链表第1结点
	}
}

void MyBookManageSystem::Insert()
// 操作结果: 输入记录
{
	BookType book;										// 图书记录
	book.isDeleted = false;								// 删除标记

	cout << "输入书号:";
	cin >> book.num;
	cout << "输入书名:";
	cin >> book.title;
	cout << "输入作者名:";
	cin >> book.author;
	cout << "输入价格:";
	cin >> book.price;
	cout << "输入购买日期:";
	cin >> book.buyDate.year >> book.buyDate.month >> book.buyDate.day;
	while (GetChar() != '\n');							// 跳过当前行的其它字符

	if (BinSerach(pNumIndexTable, sizeOfNumIndex, book.num) >= 0)
	{	// 书号重复
		cout << "书号重复, 插入失败!" << endl;
	}
	else
	{	// 插入成功
		bookFile.clear();								// 清除标志	
		bookFile.seekg(0, ios::end);					// 定位到文件尾
		long offset = bookFile.tellg();					// 主文件记录插入位置
		InsertHelp(book, offset);						// 在索引表中插入索引项
		bookFile.write((char *)&book, sizeof(BookType));// 写主文件
		cout << "插入成功!" << endl;
	}
}

void MyBookManageSystem::DeleteHelp(BookType &book, long offset)
// 操作结果: 删除记录辅助函数
{
	int pos = BinSerach(pNumIndexTable, sizeOfNumIndex, book.num);// 二分查找
	for (int i = pos + 1; i < sizeOfNumIndex; i++)
	{	// 在书号主索引表中删除索引项
		pNumIndexTable[i - 1] = pNumIndexTable[i];
	}
	sizeOfNumIndex--;						// 书号主索引项个数自减1

	pos = BinSerach(pTitleIndexTable, sizeOfTitleIndex, book.title);// 二分查找
	long pre = -1, p = pTitleIndexTable[pos].head;	// p指向当前记录,  pre指向前驱记录
	BookType tmp;							// 临时变量
	while (p != offset)
	{	// pre与p移向后继
		pre = p;							// p为pre的后继	
		bookFile.clear();					// 清除标志	
		bookFile.seekg(p, ios::beg);		// 文件定位
		bookFile.read((char *)&tmp, sizeof(BookType));// 读主文件
		p = tmp.titleNext;					// p移向后继
	}
	if (pre == -1)
	{	// book为链表的第1个结点
		pTitleIndexTable[pos].head = book.titleNext;	// book后继为第1结点
	}
	else
	{	// book不为书名链表的第1个结点
		bookFile.clear();					// 清除标志	
		bookFile.seekg(pre, ios::beg);		// 文件定位
		bookFile.read((char *)&tmp, sizeof(BookType));// 读主文件
		tmp.titleNext = book.titleNext;		//pre后继改为book的后继
		bookFile.clear();					// 清除标志	
		bookFile.seekg(pre, ios::beg);		// 文件定位
		bookFile.write((char *)&tmp, sizeof(BookType));// 写主文件
	}
}

void MyBookManageSystem::Delete()
// 操作结果: 删除记录
{
	char num[14];							// 书号
	cout << "输入书号:";
	cin >> num;
	while (GetChar() != '\n');				// 跳过当前行的其它字符
	int pos = BinSerach(pNumIndexTable, sizeOfNumIndex, num);// 二分查找
	if (pos == -1)
	{	// 查找失败
		cout << "查无此书号!" << endl;
	}
	else
	{	// 查找成功
		BookType book;						// 图书记录
		long offset = pNumIndexTable[pos].offset;	// 记录在主文件中的位置
		bookFile.clear();					// 清除标志	
		bookFile.seekg(offset, ios::beg);	// 定位文件
		bookFile.read((char *)&book, sizeof(BookType));// 读主文件
		cout << setw(14) << "书号" << setw(21) << "书名" << setw(11) << "作者名" << 
			setw(8) << "价格" << setw(12) << "购买日期" << endl;
		Display(book);						// 显示图书信息
		DeleteHelp(book, offset);			// 删除辅助操作
		bookFile.clear();					// 清除标志	
		bookFile.seekg(offset, ios::beg);	// 定位文件
		book.isDeleted = true;				// 删除标记
		bookFile.write((char *)&book, sizeof(BookType));//写主文件
		cout << "删除成功!" << endl;
	}
}

void MyBookManageSystem::Update()
// 操作结果: 更新记录
{
	char num[14];							// 书号
	cout << "输入书号:";
	cin >> num;
	while (GetChar() != '\n');				// 跳过当前行的其它字符
	int pos = BinSerach(pNumIndexTable, sizeOfNumIndex, num);// 二分查找
	if (pos == -1)
	{	// 查找失败
		cout << "查无此书号!" << endl;
	}
	else
	{	// 查找成功
		BookType bookOld, bookNew;					// 图书记录
		long offset = pNumIndexTable[pos].offset;	// 记录在主文件中的位置
		bookFile.clear();							// 清除标志	
		bookFile.seekg(offset, ios::beg);			// 文件定位
		bookFile.read((char *)&bookOld, sizeof(BookType));// 读主文件
		cout << setw(14) << "书号" << setw(21) << "书名" << setw(11) << "作者名" << 
			setw(8) << "价格" << setw(12) << "购买日期" << endl;
		Display(bookOld);							// 显示图书信息
		bookNew.isDeleted = false;					// 删除标记
		cout << "输入书号:";
		cin >> bookNew.num;
		cout << "输入书名:";
		cin >> bookNew.title;
		cout << "输入作者名:";
		cin >> bookNew.author;
		cout << "输入价格:";
		cin >> bookNew.price;
		cout << "输入购买日期:";
		cin >> bookNew.buyDate.year >> bookNew.buyDate.month >> bookNew.buyDate.day;
		while (GetChar() != '\n');					// 跳过当前行的其它字符

		if (strcmp(bookNew.num, pNumIndexTable[pos].num) == 0)
		{	// 书号没有变化
			DeleteHelp(bookOld, offset);			// 辅助删除操作,删除索引表的相应索引项
			InsertHelp(bookNew, offset);			// 辅助插入操作,索引表中插入相应索引项
			bookFile.clear();						// 清除标志	
			bookFile.seekg(offset, ios::beg);		// 文件定位
			bookFile.write((char *)&bookNew, sizeof(BookType));		// 写主文件
			cout << "更新成功!" << endl;
		}
		else
		{	// 书号已发生变化
			if (BinSerach(pNumIndexTable, sizeOfNumIndex, bookNew.num) >= 0)
			{	// 更新后, 书号重复
				cout << "书号重复, 更新失败!" << endl;
			}
			else
			{
				DeleteHelp(bookOld, offset);		// 辅助删除操作,删除索引表的相应索引项
				InsertHelp(bookNew, offset);		// 辅助插入操作,索引表中插入相应索引项
				bookFile.clear();					// 清除标志	
				bookFile.seekg(offset, ios::beg);	// 文件定位
				bookFile.write((char *)&bookNew, sizeof(BookType));	// 写主文件
				cout << "更新成功!" << endl;
			}
		}
	}
}

void MyBookManageSystem::SerachByTile() 
// 操作结果: 按书名查询记录
{

	char title[21];												// 书名
	cout << "输入书名:";
	cin >> title;
	int pos = BinSerach(pTitleIndexTable, sizeOfTitleIndex, title);	// 二分查找
	if (pos == -1)
	{	// 查找失败
		cout << "查无此书!" << endl;
	}
	else
	{	// 查找成功
		BookType book;											// 图书记录
		cout << setw(14) << "书号" << setw(21) << "书名" << setw(11) << "作者名" << 
			setw(8) << "价格" << setw(12) << "购买日期" << endl;
		long offset = pTitleIndexTable[pos].head;				// 记录在主文件中的位置
		while (offset != -1)
		{
			bookFile.clear();									// 清除标志	
			bookFile.seekg(offset, ios::beg);					// 定位文件
			bookFile.read((char *)&book, sizeof(BookType));		// 读主文件
			Display(book);										// 显示图书信息
			offset = book.titleNext;							// 下一同名图书
		}
	}
}

void MyBookManageSystem::SerachByAuthor() 
// 操作结果: 按作者名查询记录
{
	char author[11];											// 作者名
	cout << "输入作者名:";
	cin >> author;
	BookType book;												// 图书记录
	bookFile.clear();											// 清除标志	
	bookFile.seekg(0, ios::end);								// 定位到文件尾
	long endOffset = bookFile.tellg();							// 文件尾位置
	cout << setw(14) << "书号" << setw(21) << "书名" << setw(11) << "作者名" << 
		setw(8) << "价格" << setw(12) << "购买日期" << endl;
	bookFile.clear();											// 清除标志	
	bookFile.seekg(0, ios::beg);								// 定位到文件头
	do
	{
		bookFile.read((char *)&book, sizeof(BookType));			// 读主文件
		if (strcmp(book.author, author) == 0) Display(book);	// 显示图书信息
	}
	while (endOffset != bookFile.tellg());
}

void MyBookManageSystem::Serach() 
// 操作结果: 查找记录
{
	int select;									// 临时变量
	do
	{
		cout << "1.按照书名查找 2.按照作者名查找 3.退出查找" << endl;
		cout << "输入选择:";
		cin >> select;							// 输入选择
		while (GetChar() != '\n');				// 跳过当前行的其它字符
		
		switch (select)
		{
		case 1:
			SerachByTile();						// 按照书名查找
			break;
		case 2:
			SerachByAuthor();					// 按照作者名查找
			break;
		}
	} while (select != 3);
}

void MyBookManageSystem::SortByAuthor() 
// 操作结果: 按作者名排序
{
	BookType *books = new BookType[sizeOfNumIndex];	// 图书数组
	BookType book;									// 图书记录
	bookFile.clear();								// 清除标志	
	bookFile.seekg(0, ios::end);					// 定位到文件尾
	long endOffset = bookFile.tellg();				// 文件尾位置
	bookFile.clear();								// 清除标志	
	bookFile.seekg(0, ios::beg);					// 定位到文件头
	int n = 0;										// 当前读到的未被删除的记录数
	do
	{
		bookFile.read((char *)&book, sizeof(BookType));		// 读主文件
		if (!book.isDeleted) 
		{	// 将未被删除的记录存入books
			books[n++] = book;
		}
	}
	while (endOffset != bookFile.tellg());
	QuickSort(books, n);							// 快速排序
	bookFile.clear();								// 清除标志	
	bookFile.seekg(0, ios::beg);					// 定位到文件头

	sizeOfNumIndex = sizeOfTitleIndex = 0;			// 清空索引表
	cout << setw(14) << "书号" << setw(21) << "书名" << setw(11) << "作者名" << 
		setw(8) << "价格" << setw(12) << "购买日期" << endl;
	for (int pos = 0; pos < n; pos++)
	{	// 依次将books[]中的记录写入bookFile

		long offset = bookFile.tellg();				// 记录插入位置
		InsertHelp(books[pos], offset);				// 在索引表中插入books[pos]
		bookFile.write((char *)&books[pos], sizeof(BookType));	// 写主文件
		Display(books[pos]);						// 显示图书信息
	}
}

MyBookManageSystem::MyBookManageSystem()
// 操作结果: 初始化个人图书管理系统
{
	ifstream iFile("book.dat");									// 建立输入文件
	if (iFile.fail())
	{	// 打开文件失败,表示不存在文件
		ofstream oFile("book.dat");								// 建立输出文件
		if (oFile.fail()) throw("打开文件失败!");				// 抛出异常 
		oFile.close();											// 关闭文件
	}
	else
	{	// 存在文件
		iFile.close();											// 关闭文件
	}

	bookFile.open("book.dat", ios::in|ios::out|ios::binary);	// 以读写方式打开文件
	if (bookFile.fail()) throw("打开文件失败!");				// 抛出异常 
	
	ifstream numIndexFile("num.idx", ios::in|ios::binary);		// 书号主索引文件
	if (numIndexFile.fail()) throw("打开文件失败!");			// 抛出异常 

	ifstream titleIndexFile("title.idx", ios::in|ios::binary);	// 书名次索引文件
	if (titleIndexFile.fail()) throw("打开文件失败!");			// 抛出异常 
	

	int pos;													// 临时变量

	numIndexFile.clear();										// 清除标志	
	numIndexFile.seekg(0, ios::end);							// 定位到文件尾
	sizeOfNumIndex = numIndexFile.tellg() / sizeof(NumIndexItemType);	// 书号主索引表当前索引项数
	maxSizeOfNumIndex = sizeOfNumIndex + INCREMENT_OF_INDEX_TABLE;		// 书号主索引表最大索引项数
	pNumIndexTable = new NumIndexItemType[maxSizeOfNumIndex];			// 分配存储空间
	numIndexFile.clear();										// 清除标志	
	numIndexFile.seekg(0, ios::beg);							// 定位到文件头
	for (pos = 0; pos < sizeOfNumIndex; pos++)
	{	// 读出书号主索引项
		numIndexFile.read((char *)&pNumIndexTable[pos], sizeof(NumIndexItemType));	// 读书号主索引项
	}

	titleIndexFile.clear();										// 清除标志	
	titleIndexFile.seekg(0, ios::end);							// 定位到文件尾
	sizeOfTitleIndex = titleIndexFile.tellg() / sizeof(TitleIndexItemType);	// 书名次索引表当前索引项数
	maxSizeOfTitleIndex = sizeOfTitleIndex + INCREMENT_OF_INDEX_TABLE;		// 书名次索引表最大索引项数
	pTitleIndexTable = new TitleIndexItemType[maxSizeOfTitleIndex];			// 分配存储空间
	titleIndexFile.clear();										// 清除标志	
	titleIndexFile.seekg(0, ios::beg);							// 定位到文件头
	for (pos = 0; pos < sizeOfTitleIndex; pos++)
	{	// 读出书名次索引项
		titleIndexFile.read((char *)&pTitleIndexTable[pos], sizeof(TitleIndexItemType));// 读书名次索引项
	}
	numIndexFile.close(); titleIndexFile.close();				// 关闭索引文件
}

MyBookManageSystem::~MyBookManageSystem()
// 操作结果: 关闭主文件,写索引文件,释放索引表
{
	bookFile.close();											// 关闭文件

	int pos;													// 临时变量
	fstream numIndexFile("num.idx", ios::out|ios::binary);		// 书号主索引文件
	numIndexFile.clear();										// 清除标志	
	numIndexFile.seekg(0, ios::beg);							// 定位到文件头
	for (pos = 0; pos < sizeOfNumIndex; pos++)
	{	// 写取书号主索引项
		numIndexFile.write((char *)&pNumIndexTable[pos], sizeof(NumIndexItemType));	// 写书号主索引项
	}

	fstream titleIndexFile("title.idx", ios::out|ios::binary);	// 书名次索引文件
	titleIndexFile.clear();										// 清除标志	
	titleIndexFile.seekg(0, ios::beg);							// 定位到文件头
	for (pos = 0; pos < sizeOfTitleIndex; pos++)
	{	// 写取书名次索引项
		titleIndexFile.write((char *)&pTitleIndexTable[pos], sizeof(TitleIndexItemType));	// 写书名次索引项
	}

	numIndexFile.close(); titleIndexFile.close();				// 关闭书号主索引文件
	delete []pNumIndexTable;delete []pTitleIndexTable;			// 释放存储空间
}

void MyBookManageSystem::Run()
// 操作结果: 运行个人图书管理系统类
{
	int select;									// 临时变量
	do
	{
		cout << "1.插入记录 2.删除记录 3.更新记录 4.查找记录 5.按作者名排序 6.退出" << endl;
		cout << "输入选择:";
		cin >> select;							// 输入选择
		while (GetChar() != '\n');				// 跳过当前行的其它字符
		
		switch (select)
		{
		case 1:
			Insert();							// 输入记录
			break;
		case 2:
			Delete();							// 删除记录
			break;
		case 3:
			Update();							// 更新记录
			break;
		case 4:
			Serach();							// 查找记录
			break;
		case 5:
			SortByAuthor();						// 按作者名排序
			break;
		}
	} while (select != 6);
}

#endif
