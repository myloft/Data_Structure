// 文件路径名: my_hash_table\main.cpp
#include "utility.h"						// 实用程序软件包
#include "my_hash_table.h"					// 散列表类

int main(void)
{
    try										// 用try封装可能出现异常的代码
	{
		int elems[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79};
		int n = 12;							// 元素个数
		int m = 6;							// 散列表长度
		MyHashTable<int, int> ht(m);		// 散列表	
		
		for (int i = 0; i < n; i++)
			ht.Insert(elems[i]);			// 插入结点

		cout << "遍历Hash表:" << endl;
	    ht.Traverse(Write);
		cout << endl;
		system("PAUSE");					// 调用库函数system()	
		
		int e = 79;
		ht.Delete(e);						// 删除
		cout << "删除79后:" << endl;
	    ht.Traverse(Write);
		cout << endl;
		system("PAUSE");					// 调用库函数system()

		MyHashTable<int, int> htNew(ht);	// 复制构造新散列表
		cout << "复制构造新Hash表:" << endl;
	    htNew.Traverse(Write);
		cout << endl;
		system("PAUSE");					// 调用库函数system()

		htNew = ht;							// 赋值生成新散列表
		cout << "赋值构造新Hash表:" << endl;
	    htNew.Traverse(Write);
		cout << endl;
	}
	catch (Error err)						// 捕捉并处理异常
	{
		err.Show();							// 显示异常信息
	}

	system("PAUSE");						// 调用库函数system()
	return 0;								// 返回值0, 返回操作系统
}



