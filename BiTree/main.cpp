//2017.4.25 by iloft
#include "binary_tree.h"
#include <iostream>
using namespace std;
int main() {
	BinaryTree<int> bt;
	int c = 0;
	int tmp1,tmp2;
	while (c != 16) {
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
		cout << endl << "12. 读取父元素";
		cout << endl << "13. 叶子结点个数";
		cout << endl << "14. 图形显示";
		cout << endl << "15. 销毁二叉树";
		cout << endl << "16. 退出";
		cout << endl << "选择功能(1~16):";
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
		//case 8:
		}
	}
	return 0;
}