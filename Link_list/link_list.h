//
// Created by iloft on 2017/3/17.
//

#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
#include "node.h"

using namespace std;

template<class ElemType>
class LinkList {
private:
    //  链表实现的数据成员:
    int length = 0;
    Node<ElemType> *head;    // 头结点指针
    Node<ElemType> *GetElemPtr(int position);

public:
    //线性链表方法声明:
    void Init();

    void CreateList(int num);

    void Clear();    // 将线性表清空
    void DestroyList();

    int Length();        // 求线性表长度
    bool Empty();    // 判断线性表是否为空
    bool SetElem(int position, ElemType e);

    bool GetElem(int position, ElemType &e);

    int Locate(ElemType e);

    bool Insert(int position, ElemType e);// 插入元素
    bool Delete(int position, ElemType &e);

    void Traverse();

    bool GetPrior(ElemType e, ElemType &x);

    bool GetNext(ElemType e, ElemType &x);
};

template<class ElemType>

void LinkList<ElemType>::Init() {
    head = new Node<ElemType>;   // 构造头指针
}

template<class ElemType>
void LinkList<ElemType>::CreateList(int num) {
    Node<ElemType> *p = head, *q;
    if (length > 0) Clear();    //清空现有元素
    cout << "请依次输入" << num << "个元素值：" << endl;
    for (int i = 1; i <= num; i++) {
        q = new Node<ElemType>;
        cin >> q->data;//生成新节点
        p->next = q;
        p = q;
    }
    q->next = NULL;
    length = num;
}

template<class ElemType>
int LinkList<ElemType>::Length() {
    int count = 0;        // 计数器
    for (Node<ElemType> *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
        // 用tmpPtr依次指向每个元素
    { count++; }
    return count;
}

template<class ElemType>
bool LinkList<ElemType>::Empty()
// 如线性表为空，则返回true，否则返回false
{
    return head->next == NULL;
}

template<class ElemType>
bool LinkList<ElemType>::GetElem(int position, ElemType &e)
// 将线性表的第position个位置的元素赋值为e,
{
    // position范围错
    if (position < 1 || position > length) {
        return false;
    } else      // position合法
    {
        Node<ElemType> *tmpPtr = head->next;
        int j = 1;
        while (j < position) {
            tmpPtr = tmpPtr->next;
            j++;
        }
        e = tmpPtr->data;
        return true;
    }
}

template<class ElemType>
bool LinkList<ElemType>::SetElem(int position, ElemType e)
// 将线性表的第position个位置的元素赋值为e
{
    if (position < 1 || position > length)
        // position范围错
    {
        return false;
    } else       // position合法
    {
        Node<ElemType> *tmpPtr = head->next;
        int j = 1;
        while (j < position) {
            tmpPtr = tmpPtr->next;
            j++;
        }
        tmpPtr->data = e;
        return true;
    }
}

template<class ElemType>
int LinkList<ElemType>::Locate(ElemType e) {
    int position = 1;
    Node<ElemType> *p = head->next;  //p指向首元素
    while (p != NULL && p->data != e) {
        p = p->next;
        position++;
    }
    if (p == NULL) return false;
    else return position;
}

template<class ElemType>
bool LinkList<ElemType>::Insert(int position, ElemType e) {
    if (position < 1 || position > length + 1) {    // position范围错
        return false;    // 位置不合法
    }
    Node<ElemType> *newp, *pp;
    pp = head->next;          //前驱指针
    for (int j = 1; j < position - 1; j++) { pp = pp->next; }
    newp = new Node<ElemType>; //分配新节点
    newp->data = e;//新元素赋值
    newp->next = pp->next;
    pp->next = newp;
    length++;
    return true;
}

template<class ElemType>
bool LinkList<ElemType>::Delete(int position, ElemType &e) {
    if (position < 1 || position > length) return false;
    Node<ElemType> *pp, *cp;
    pp = head; //pp指向头节点
    cp = pp->next; //cp指向首元素
    for (int j = 1; j < position; j++) {
        pp = cp;
        cp = cp->next;
    }
    pp->next = cp->next;//cp指向pos元素，pp指向其前驱
    delete cp;//删除pos元素
    length--;
    return true;
}

template<class ElemType>
void LinkList<ElemType>::Traverse() {
    for (Node<ElemType> *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next) {    // 用tmpPtr依次指向每个元素
        cout << tmpPtr->data << '\t';
    }
    cout << endl;
}

template<class ElemType>
bool LinkList<ElemType>::GetPrior(ElemType e, ElemType &x) {
    Node<ElemType> *pp, *cp;
    pp = head;
    cp = pp->next;
    while (cp != NULL && cp->data != e) {
        pp = cp;
        cp = cp->next;
    }
    if (cp == NULL)
        return false;//表中无元素e
    if (pp == head)
        return false; //首元素无前驱
    x = pp->data;  //返回前驱
    return true;
}

template<class ElemType>
bool LinkList<ElemType>::GetNext(ElemType e, ElemType &x) {
    Node<ElemType> *p;
    p = head->next;
    while (p != NULL && p->data != e)
        p = p->next;
    if (p == NULL) return false;
    if (p->next == NULL) return false; //尾元素无后继
    x = p->next->data; //返回后继
    return true;
}

template<class ElemType>
Node<ElemType> *LinkList<ElemType>::GetElemPtr(int position)
//返回指向第position个结点的指针
{
    Node<ElemType> *tmpPtr = head;
    int curPosition = 0;
    while (tmpPtr != NULL && curPosition < position) {
        tmpPtr = tmpPtr->next;
        curPosition++;
    }
    if (tmpPtr != NULL && curPosition == position) {
        return tmpPtr;
    } else {
        return NULL;
    }
}

template<class ElemType>
void LinkList<ElemType>::Clear() {
    Node<ElemType> *p = head->next;
    while (p != NULL) {
        head->next = p->next;
        delete p;//删除节点
        p = head->next;
    }
}

template<class ElemType>
void LinkList<ElemType>::DestroyList() {
    Clear();
    delete head;//删除头结点
}

#endif //LINK_LIST_LINK_LIST_H
