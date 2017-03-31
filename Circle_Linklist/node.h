//
// Created by iloft on 2017/3/25.
//

#ifndef MONKEY_KING_NODE_H
#define MONKEY_KING_NODE_H
template <class ElemType>
struct Node {
// 数据成员:
    ElemType data;                // 数据域
    Node<ElemType> *next;        // 指针域
    //构造函数模板
    Node();

    Node(ElemType item, Node<ElemType> *link = NULL);
};

template <class ElemType>
Node<ElemType>::Node()
{
    next=NULL;
}

template <class ElemType>
Node<ElemType>::Node(ElemType item,Node<ElemType> *link)
{
    data=item;
    next=link;
}
#endif //MONKEY_KING_NODE_H
