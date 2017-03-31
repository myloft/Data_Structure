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
		cout << endl << "1. ����";
		cout << endl << "2. �󳤶�";
		cout << endl << "3. �Ƿ�Ϊ��";
		cout << endl << "4. ��ջ";
		cout << endl << "5. ��ջ";
		cout << endl << "6. ��ջ";
		cout << endl << "7. ����";
		cout << endl << "8. ���";
		cout << endl << "9. ����";
		cout << endl << "10. �˳�";
		cout << endl << "ѡ����(1~10):";
		cin >> c;
		switch (c) {
		case 1:
			ls.Setup();
			cout << "�������";
			break;
		case 2:
			cout << "����Ϊ:" << ls.Length();
			break;
		case 3:
			if (ls.Empty()) {
				cout << "Ϊ��";
				break;
			}
			cout << "��Ϊ��";
			break;
		case 4:
			cout << "������ջԪ��";
			cin >> tmp_value;
			if (ls.Push(tmp_value)) {
				cout << tmp_value << "��ջ�ɹ�";
				break;
			}
			cout << "��ջʧ��";
			break;
		case 5:
			if (ls.Pop(tmp_value)) {
				cout << tmp_value << "��ջ�ɹ�";
				break;
			}
			cout << "��ջʧ��";
		case 6:
			if (ls.Top(tmp_value)) {
				cout << "ջ��Ԫ��Ϊ:" << tmp_value;
				break;
			}
			cout << "��ջʧ��";
			break;
		case 7:
			ls.Traverse();
			break;
		case 8:
			ls.Clear();
			cout << "������";
			break;
		case 9:
			ls.~LinkStack();
			cout << "�������";
			break;
		case 11:
			exit(0);
		}
	}
}