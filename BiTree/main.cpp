﻿//2017.4.25 by iloft
#include "binary_tree.h"
#include <iostream>
using namespace std;
int main() {
	BinaryTree<int> bt;
	int c = 0;
	int tmp1,tmp2,tmp3;
	while (c != 15) {
		cout << endl << "1. 创建二叉树";
		cout << endl << "2. 中序遍历";
		cout << endl << "3. 先序遍历";
		cout << endl << "4. 后序遍历";
		cout << endl << "5. 按层遍历";
		cout << endl << "6. 查找节点";
		cout << endl << "7. 读取左孩子";
		cout << endl << "8. 读取父元素";
		cout << endl << "9. 读取左兄弟";
		cout << endl << "10. 插入左右孩子";
		cout << endl << "11. 更新元素";
		cout << endl << "12. 叶子结点个数";
		cout << endl << "13. 图形显示";
		cout << endl << "14. 销毁二叉树";
		cout << endl << "15. 退出";
		cout << endl << "选择功能(1~15):";
		cin >> c;
		switch (c)
		{
		case 1:
			bt.CreateBiTree();
			break;
		case 2:
			bt.InOrder();
			break;
		case 3:
			bt.PreOrder();
			break;
		case 4:
			bt.PostOrder();
			break;
		case 5:
			bt.LevelOrder();
			break;
		case 6:
			cout << "输入查找节点:";
			cin >> tmp1;
			if (bt.Locate(tmp1)) {
				cout << "存在";
				break;
			}
			cout << "不存在";
			break;
		case 7:
			cout << "输入元素:";
			cin >> tmp1;
			if (bt.GetLeft(tmp1,tmp2)) {
				cout << "左孩子为:" << tmp2;
				break;
			}
			cout << "不存在";
		case 8:
			cout << "输入元素:";
			cin >> tmp1;
			if (bt.GetParent(tmp1,tmp2)) {
				cout << "父元素为:" << tmp2;
				break;
			}
			cout << "不存在";
			break;
		case 9:
			cout << "输入元素:";
			cin >> tmp1;
			if (bt.GetLeftSibling(tmp1,tmp2)) {
				cout << "左兄弟为:" << tmp2;
				break;
			}
			cout << "不存在";
			break;
		case 10:
			cout << "输入元素:";
			cin >> tmp1;
			cout <<"输入左孩子:";
			cin >> tmp2;
			cout << "输入右孩子:";
			cin >> tmp3;
			if (bt.InsertChild(tmp1,tmp2,tmp3)) {
				cout << "修改完成" ;
				break;
			}
			cout << "修改失败";
			break;
		case 11:
			cout << "输入元素:";
			cin >> tmp1;
			cout << "修改为:";
			cin >> tmp2;
			if (bt.SetElem(tmp1, tmp2)) {
				cout << "修改成功";
				break;
			}
			cout << "修改失败";
			break;
		case 12:
			cout << "叶子结点个数:" << bt.Leaf();
			break;
		case 13:
			bt.DisplayTree();
			break;
		case 14:
			bt.~BinaryTree();
			cout << "销毁成功";
			break;
		case 15:
			exit(0);
		}
	}
	return 0;
}