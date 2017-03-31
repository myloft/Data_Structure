//
// Created by iloft on 2017/3/25.
//

#ifndef MONKEY_KING_CIRCLINKLIST_H
#define MONKEY_KING_CIRCLINKLIST_H

#include <iostream>
#include "node.h"

using namespace std;

template<class ElemType>
class CircleLinkList {
private:
    Node<ElemType> *head;    // 头结点指针
    Node<ElemType> *GetElemPtr(int position);

    int length;
public:
    CircleLinkList();

    int Length();

    void CreateCircleList(int num);

    bool GetElem(int position, ElemType &e);

    bool Delete(int position, ElemType &e);
};

template<class ElemType>
Node<ElemType> *CircleLinkList<ElemType>::GetElemPtr(int position) {
    if (position == 0) {
        return head;
    }
    Node<ElemType> *tmpPtr = head->next;
    int pos = 1;
    while (tmpPtr != head && pos < position) {
        tmpPtr = tmpPtr->next;
        pos++;
    }
    if (tmpPtr != head && pos == position) {
        return tmpPtr;
    } else {
        return NULL;
    }
}

template<class ElemType>
CircleLinkList<ElemType>::CircleLinkList() {
    head = new Node<ElemType>;
}

template<class ElemType>
int CircleLinkList<ElemType>::Length() {
    int count = 0;
    for (Node<ElemType> *tmpPtr = head->next; tmpPtr != head; tmpPtr = tmpPtr->next) {
        count++;
    }
    return count;
}

template<class ElemType>
void CircleLinkList<ElemType>::CreateCircleList(int num) {
    Node<ElemType> *p = head, *q;
    for (int i = 1; i <= num; i++) {
        q = new Node<ElemType>;
        q->data = i;//生成新节点
        p->next = q;
        p = q;
    }
    q->next = head;
}

template<class ElemType>
bool CircleLinkList<ElemType>::GetElem(int position, ElemType &e)
// 将线性表的第position个位置的元素赋值为e,
{
    // position范围错
    if (position < 1 || position > Length()) {
        return false;
    } else {
        Node<ElemType> *tmpPtr;
        tmpPtr = GetElemPtr(position);
        e = tmpPtr->data;
        return true;
    }
}

template<class ElemType>
bool CircleLinkList<ElemType>::Delete(int position, ElemType &e) {
    if (position < 1 || position > Length()) {
        return false;
    } else {
        Node<ElemType> *tmpPtr;
        tmpPtr = GetElemPtr(position - 1);
        Node<ElemType> *nextPtr = tmpPtr->next;
        tmpPtr->next = nextPtr->next;
        e = nextPtr->data;
        delete nextPtr;
        return true;
    }
}


#endif //MONKEY_KING_CIRCLINKLIST_H
