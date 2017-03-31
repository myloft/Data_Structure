#include <iostream>
#include "link_list.h"

using namespace std;

int main() {
    LinkList<int> ll;
    int c = 0;
    int num;
    int tmp_position;
    int tmp_value;
    int tmp_value2;
    while (c != 13) {
        cout << endl << "1. 创建线性链表";
        cout << endl << "2. 判断线性链表是否为空";
        cout << endl << "3. 修改线性链表某元素值";
        cout << endl << "4. 求线性链表某位置元素值";
        cout << endl << "5. 在线性链表中查找元素";
        cout << endl << "6. 在线性链表中插入元素";
        cout << endl << "7. 在线性链表中删除元素";
        cout << endl << "8. 遍历线性链表";
        cout << endl << "9. 求前驱";
        cout << endl << "10. 求后继";
        cout << endl << "11. 清空线性链表";
        cout << endl << "12. 销毁线性链表";
        cout << endl << "13. 退出";
        cout << endl << "选择功能(1~13):";
        cin >> c;
        switch (c) {
            default:
                break;
            case 1:
                cout << "请输入线性链表长度:";
                cin >> num;
                ll.Init();
                ll.CreateList(num);
                break;
            case 2:
                if (ll.Empty()) {
                    cout << "线性链表为空";
                    break;
                }
                cout << "线性链表不为空";
                break;
            case 3:
                cout << "请输入元素位置";
                cin >> tmp_position;
                cout << "请输入元素值";
                cin >> tmp_value;
                if (ll.SetElem(tmp_position, tmp_value)) {
                    cout << "修改成功";
                    break;
                }
                cout << "修改失败";
                break;
            case 4:
                cout << "请输入元素位置";
                cin >> tmp_position;
                if (ll.GetElem(tmp_position, tmp_value)) {
                    cout << "第" << tmp_position << "位元素为:" << tmp_value;
                    break;
                }
                cout << "输入位置错误";
                break;
            case 5:
                cout << "请输入查找的元素值";
                cin >> tmp_value;
                if (ll.Locate(tmp_value) == 0) {
                    cout << "该元素不存在";
                    break;
                }
                cout << "该元素在第" << ll.Locate(tmp_value) << "位";
                break;
            case 6:
                cout << "请输入插入位置";
                cin >> tmp_position;
                cout << "请输入插入的数值";
                cin >> tmp_value;
                if (ll.Insert(tmp_position, tmp_value)) {
                    cout << "插入成功";
                    break;
                }
                cout << " 插入失败";
                break;
            case 7:
                cout << "请输入要删除元素的位置";
                cin >> tmp_position;
                if (ll.Delete(tmp_position, tmp_value)) {
                    cout << "删除" << tmp_value << "成功";
                    break;
                }
                cout << "删除失败";
                break;
            case 8:
                ll.Traverse();
                break;
            case 9:
                cout << "请输入元素值";
                cin >> tmp_value;
                if (ll.GetPrior(tmp_value, tmp_value2)) {
                    cout << tmp_value << "的前驱为" << tmp_value2;
                    break;
                }
                cout << "表中无该元素或首元素无前驱";
                break;
            case 10:
                cout << "请输入元素值";
                cin >> tmp_value;
                if (ll.GetNext(tmp_value, tmp_value2)) {
                    cout << tmp_value << "的后继为" << tmp_value2;
                    break;
                }
                cout << "表中无该元素或尾元素无后继";
                break;
            case 11:
                ll.Clear();
                cout << "清空成功";
                break;
            case 12:
                ll.DestroyList();
                cout << "销毁成功";
                break;
            case 13:
                exit(0);
        }
    }
}