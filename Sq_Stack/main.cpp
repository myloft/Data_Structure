#include<iostream>
using namespace std;
#include "sql_stack.h"
int main() {
	SqStack<int> ls;
	int c = 0;
	int tmp_size = 0;
	int tmp_value = 0;

	while (c != 11) {
		cout << endl << "1. 创建";
		cout << endl << "2. 求长度";
		cout << endl << "3. 是否为空";
		cout << endl << "4. 是否已满";
		cout << endl << "5. 入栈";
		cout << endl << "6. 出栈";
		cout << endl << "7. 读栈";
		cout << endl << "8. 遍历";
		cout << endl << "9. 清空";
		cout << endl << "10. 销毁";
		cout << endl << "11. 退出";
		cout << endl << "选择功能(1~11):";
		cin >> c;
		switch (c) {
		case 1:
			cout << "请输入长度:";
			cin >> tmp_size;
			ls.Setup(tmp_size);
			break;
		case 2:
			cout << "长度为:" << ls.Length();
			break;
		case 3:
			if (ls.Empty()) {
				cout << "为空";
				break;
			}
			cout << "不为空";
			break;
		case 4:
			if (ls.Full()) {
				cout << "已满";
				break;
			}
			cout << "不满";
			break;
		case 5:
			cout << "输入入栈元素";
			cin >> tmp_value;
			if (ls.Push(tmp_value)) {
				cout << tmp_value << "入栈成功";
				break;
			}
			cout << "入栈失败";
			break;
		case 6:
			if (ls.Pop(tmp_value)) {
				cout << tmp_value << "出栈成功";
				break;
			}
			cout << "出栈失败";
		case 7:
			if (ls.Top(tmp_value)) {
				cout << "栈顶元素为:" << tmp_value;
				break;
			}
			cout << "读栈失败";
			break;
		case 8:
			ls.Traverse();
			break;
		case 9:
			ls.Clear();
			cout << "清空完成";
			break;
		case 10:
			ls.~SqStack();
			cout << "销毁完成";
			break;
		case 11:
			exit(0);
		}
	}
}