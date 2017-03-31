//
// Created by iloft on 2017/3/5.
//
#include <iostream>
#include "sq_list.h"	// 顺序表类

using namespace std;

int main() {
    SqList<int> sl;
    SqList<string> tx;
    int c = 0;

    int num;
    int tmp_line;
    int tmp_size;
    int tmp_position;
    int tmp_value;
    while (c != 19) {
        cout << endl << "1. 输入线性表，创建顺序表";
        cout << endl << "2. 创建有序顺序表";
        cout << endl << "3. 求线性表长度";
        cout << endl << "4. 判断线性表是否为空";
        cout << endl << "5. 判断线性表是否已满";
        cout << endl << "6. 修改线性表某元素值";
        cout << endl << "7. 求线性表某位置元素值";
        cout << endl << "8. 在线性表中查找元素";
        cout << endl << "9. 在线性表中插入元素";
        cout << endl << "10. 在线性表中顺序插入元素";
        cout << endl << "11. 在线性表中删除元素";
        cout << endl << "12. 遍历线性表";
        cout << endl << "13. 清空线性表";
        cout << endl << "14. 销毁线性表";
        cout << endl << "15. 输入文本";
        cout << endl << "16. 输出文本";
        cout << endl << "17. 计算字符数";
        cout << endl << "18. 查找字符串出现次数";
        cout << endl << "19. 删除给定字符串";
        cout << endl << "20. 退出";
        cout << endl << "选择功能(1~19):";
        cin >> c;
        switch (c) {
            default:
                break;
            case 1:
                cout << "请输入最大长度:";
                cin >> tmp_size;
                sl.Setup(tmp_size);
                cout << "请输入线性表长度:";
                cin >> num;
                sl.CreateList(num);
                break;
            case 2:
                cout << "请输入最大长度:";
                cin >> tmp_size;
                sl.Setup(tmp_size);
                cout << "请输入有序线性表长度:";
                cin >> num;
                sl.CreateListOrder(num);
                break;
            case 3:
                cout << "线性表长度为:" << sl.Length();
                break;
            case 4:
                if (sl.Empty()) {
                    cout << "线性表为空";
                    break;
                }
                cout << "线性表不为空";
                break;
            case 5:
                if (sl.Full()) {
                    cout << "线性表已满";
                    break;
                }
                cout << "线性表不满";
                break;
            case 6:
                cout << "请输入元素位置:";
                cin >> tmp_position;
                cout << "请输入元素值:";
                cin >> tmp_value;
                if (sl.SetElem(tmp_position, tmp_value)) {
                    cout << "修改成功";
                    break;
                }
                cout << "修改失败";
                break;
            case 7:
                cout << "请输入元素位置:";
                cin >> tmp_position;
                if (sl.GetElem(tmp_position, tmp_value)) {
                    cout << "第" << tmp_position << "位元素为:" << tmp_value;
                    break;
                }
                cout << "输入位置错误";
                break;
            case 8:
                cout << "请输入查找的元素值";
                cin >> tmp_value;
                if (sl.Locate(tmp_value) == 0) {
                    cout << "该元素不存在";
                    break;
                }
                cout << "该元素在第" << sl.Locate(tmp_value) << "位";
                break;
            case 9:
                cout << "请输入插入位置";
                cin >> tmp_position;
                cout << "请输入插入的数值";
                cin >> tmp_value;
                if (sl.Insert(tmp_position, tmp_value)) {
                    cout << "插入成功";
                    break;
                }
                cout << " 插入失败";
                break;
            case 10:
                cout << "请输入插入的数值";
                cin >> tmp_value;
                if (sl.InsertOrder(tmp_value)) {
                    cout << "插入成功";
                    break;
                }
                cout << " 插入失败";
                break;
            case 11:
                cout << "请输入要删除元素的位置";
                cin >> tmp_position;
                if (sl.Delete(tmp_position, tmp_value)) {
                    cout << "删除" << tmp_value << "成功";
                    break;
                }
                cout << "删除失败";
                break;
            case 12:
                sl.Traverse();
                break;
            case 13:
                sl.Clear();
                cout << "清空成功";
                break;
            case 14:
                sl.~SqList();
                cout << "销毁成功";
                break;
            case 15:
                cout << "请输入行数:";
                cin >> tmp_line;
                tx.TextCreate(tmp_line);
                cout << "输入完成";
                break;
            case 16:
                tx.TextOutput();
                break;
            case 17:
                tx.TextCount();
                break;
            case 18:
                tx.TextSearch();
                break;
            case 19:
                tx.TextDelete();
                break;
            case 20:
                exit(0);
        }
    }
}
