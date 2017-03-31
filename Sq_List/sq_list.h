//
// Created by iloft on 2017/3/5.
//
#include <algorithm>
#include <string>
#include <iostream>

using std::string;

#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

// 顺序表类模板
template<class ElemType>
class SqList {
protected:
// 顺序表实现的数据成员:
    int line;
    int count;            // 元素个数
    int maxSize;        // 顺序表最大元素个数
    ElemType *elems;    // 元素存储空间
public:
// 顺序表的方法声明：
    bool Setup(int size);    // 初始化线性表
    virtual ~SqList();    // 销毁线性表
    bool CreateList(int num); //构建顺序表
    bool CreateListOrder(int num); //构建有序顺序表
    void Clear();        // 将线性表清空
    int Length();    // 求线性表长度
    bool Empty();    // 判断线性表是否为空
    bool Full();    // 判断线性表是否已满
    bool SetElem(int position, ElemType e);// 设置指定位置的元素值
    bool GetElem(int position, ElemType &e);    // 求指定位置的元素
    int Locate(ElemType e); //元素定位
    bool Insert(int position, ElemType e);// 插入元素
    bool InsertOrder(ElemType e);//顺序插入元素
    bool Delete(int position, ElemType &e);// 删除元素
    void Traverse();            // 遍历线性表
    bool TextCreate(int line);  //文本输入
    bool TextOutput(); //文本输出
    bool TextCount(); //计算字符数
    bool TextSearch(); //查找字符串
    bool TextDelete(); //删除字符串
};

template<class ElemType>
bool SqList<ElemType>::Setup(int size) {
// 操作结果：初始化线性表为最大元素个数为size的空线性表
    elems = new ElemType[size];// 分配存储空间
    if (elems == NULL)
        exit(1); //无空间可分配，“溢出”退出
    maxSize = size;     // 最大元素个数
    count = 0;    // 空线性表元素个数为0
    return true;
}

template<class ElemType>
SqList<ElemType>::~SqList()
//销毁顺序表
{
    delete[] elems;
    maxSize = count = 0;
}

template<class ElemType>
bool SqList<ElemType>::CreateList(int num)
//创建长度为num的顺序表
{
    if (num > maxSize) return false; //参数非法
    std::cout << "建立长度为" << num << "的顺序表\n";
    std::cout << "请依次输入" << num << "个元素值：\n";
    for (int i = 0; i < num; i++)
        std::cin >> elems[i];
    count = num;
    return true;
}

template<class ElemType>
bool SqList<ElemType>::CreateListOrder(int num)
//创建长度为num的有序顺序表
{
    if (num > maxSize) return false; //参数非法
    std::cout << "建立长度为" << num << "的顺序表\n";
    std::cout << "请依次输入" << num << "个元素值：\n";
    for (int i = 0; i < num; i++)
        std::cin >> elems[i];
    count = num;
    std::sort(elems, elems + num);
    return true;
}

template<class ElemType>
void SqList<ElemType>::Clear()
//线性表清零
{
    count = 0;
}

template<class ElemType>
int SqList<ElemType>::Length()
// 求线性表长度
{
    return count;
}

template<class ElemType>
bool SqList<ElemType>::Empty()
// 判断线性表是否为空,如线性表为空，则返回true，否则返回false
{
    return count == 0;
}

template<class ElemType>
bool SqList<ElemType>::Full()
//判断线性表是否已满,如线性表已满，则返回true，否则返回false
{
    return count == maxSize;
}

template<class ElemType>
bool SqList<ElemType>::SetElem(int position, ElemType e)
// 将线性表的第position个位置的元素赋值为e
{   // 位置错
    if (position < 1 || position > count) { return false; }
    else {
        elems[position - 1] = e;
        return true;        // 成功
    }
}

template<class ElemType>
bool SqList<ElemType>::GetElem(int position, ElemType &e)
//当线性表存在第position个元素时，用e返回其值
{
    if (position < 1 || position > Length()) { return false; }    // position范围错元素不存在
    else                                   // position合法
    {
        e = elems[position - 1];
        return true;                     // 元素存在
    }
}

template<class ElemType>
int SqList<ElemType>::Locate(ElemType e)
//从顺序表中查找具有给定值e的第一个元素，并返回该元素的逻辑位序，若找不到返回0。
{
    int i;
    for (i = 0; i < count; i++)
        if (elems[i] == e) break;
    return i < count ? i + 1 : 0;
}

template<class ElemType>
bool SqList<ElemType>::Insert(int position, ElemType e)
// 在线性表的第position个位置前插入元素e。
{
    // 线性表已满
    if (Full()) { return false; }
        // position范围错
    else if (position < 1 || position > count + 1) { return false; }
    else {    // 插入位置之后的元素右移
        for (int curPosition = count - 1;
             curPosition >= position - 1; curPosition--) { elems[curPosition + 1] = elems[curPosition]; }
        elems[position - 1] = e;       //将e赋值到position位置处
        count++;               // 插入后元素个数将自增1
        return true;             // 插入成功
    }
}

template<class ElemType>
bool SqList<ElemType>::InsertOrder(ElemType e)
// 在顺序线性表中插入元素e。
{
    if (Full()) { return false; }
        // position范围错
    else {
        elems[count] = e;
        std::sort(elems, elems + count + 1);
        count++;
        return true;
    }
}

template<class ElemType>
bool SqList<ElemType>::Delete(int position, ElemType &e)
// 删除线性表的第position个位置的元素, 并用e返回其值
{        // position范围错
    if (position < 1 || position > count) { return false; }
    else {       // 用e返回被删除元素的值
        e = elems[position - 1];
        // 被删除元素之后的元素依次左移
        for (int curPosition = position;
             curPosition < count; curPosition++) { elems[curPosition - 1] = elems[curPosition]; }
        count--;      // 删除后元素个数将自减1
        return true;
    }
}

template<class ElemType>
void SqList<ElemType>::Traverse()
// 依次输出线性表的每个元素
{
    for (int curPosition = 0; curPosition <= count - 1;
         curPosition++) {
        std::cout << elems[curPosition] << '\t';
    }
    std::cout << std::endl;
}

template<class ElemType>
bool SqList<ElemType>::TextCreate(int tmp_line) {
    line = tmp_line;
    elems = new ElemType[line - 1];
    std::cout << "请输入文字" << std::endl;
    std::cin.ignore();
    for (int i = 0; i < line; i++) {
        std::getline(std::cin, elems[i]);
        if (elems[i].length() > 80) {
            std::cout << "单行输入不得超过80个字符";
            exit(0);
        }
    }
    return true;
}

template<class ElemType>
bool SqList<ElemType>::TextOutput() {
    for (int i = 0; i < line; i++) {
        std::cout << elems[i] << std::endl;
    }
    return true;
}

template<class ElemType>
bool SqList<ElemType>::TextCount() {
    int length = 0;
    int C_letter = 0;
    int L_letter = 0;
    int space = 0;
    int number = 0;
    for (int i = 0; i < line; i++) {
        length = elems[i].length() + length;
        for (int j = 0; j < elems[i].length(); j++) {
            if (elems[i][j] >= 'A' && elems[i][j] <= 'Z') {
                C_letter++;
            } else if (elems[i][j] >= 'a' && elems[i][j] <= 'z') {
                L_letter++;
            } else if (elems[i][j] == ' ') {
                space++;
            } else if (elems[i][j] >= '0' && elems[i][j] <= '9') {
                number++;
            }
        }
    }
    std::cout << "字母数量:" << C_letter + L_letter << std::endl;
    std::cout << "数字数量:" << number << std::endl;
    std::cout << "空格数量:" << space << std::endl;
    std::cout << "文章总字数:" << length << std::endl;
    return true;
}

template<class ElemType>
bool SqList<ElemType>::TextSearch() {
    string search;
    std::cout << "请输入搜索的字符串:";
    std::cin.ignore();
    std::getline(std::cin, search);
    int sum = 0;
    for (int i = 0; i < line; i++) {
        size_t nPos = elems[i].find(search, 0); // fist occurrence
        while (nPos != string::npos) {
            sum++;
            nPos = elems[i].find(search, nPos + 1);
        }
    }
    std::cout << search << "出现了:" << sum << "次";
    return true;
}

template<class ElemType>
bool SqList<ElemType>::TextDelete() {
    string string_delete;
    std::cout << "请输入删除的字符串:";
    std::cin.ignore();
    std::getline(std::cin, string_delete);
    for (int j = 0; j < line; j++) {
        for (int i = 0; i < string_delete.length(); ++i) {
            elems[j].erase(std::remove(elems[j].begin(), elems[j].end(), string_delete[i]), elems[j].end());
        }
        std::cout << elems[j] << std::endl;
    }
    return true;
}

#endif
