#pragma once
#include<iostream>
using namespace std;
#include "link_stack.h"
int main() {
	LinkStack<int> ls;
	int c = 0;
	int tmp_size = 0;
	int tmp_value = 0;

	while (c != 10) {
		cout << endl << "1. 创建";
		cout << endl << "2. 求长度";
		cout << endl << "3. 是否为空";
		cout << endl << "4. 入栈";
		cout << endl << "5. 出栈";
		cout << endl << "6. 读栈";
		cout << endl << "7. 遍历";
		cout << endl << "8. 清空";
		cout << endl << "9. 销毁";
		cout << endl << "10. 退出";
		cout << endl << "选择功能(1~10):";
		cin >> c;
		switch (c) {
		case 1:
			ls.Setup();
			cout << "创建完成";
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
			cout << "输入入栈元素";
			cin >> tmp_value;
			if (ls.Push(tmp_value)) {
				cout << tmp_value << "入栈成功";
				break;
			}
			cout << "入栈失败";
			break;
		case 5:
			if (ls.Pop(tmp_value)) {
				cout << tmp_value << "出栈成功";
				break;
			}
			cout << "出栈失败";
		case 6:
			if (ls.Top(tmp_value)) {
				cout << "栈顶元素为:" << tmp_value;
				break;
			}
			cout << "读栈失败";
			break;
		case 7:
			ls.Traverse();
			break;
		case 8:
			ls.Clear();
			cout << "清空完成";
			break;
		case 9:
			ls.~LinkStack();
			cout << "销毁完成";
			break;
		case 11:
			exit(0);
		}
	}
}