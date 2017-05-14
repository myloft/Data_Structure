#ifndef LINKLIST_NODE_H
#define LINKLIST_NODE_H

template <class ElemType>
struct Node {
    ElemType data;
    Node<ElemType> *next;

    Node();
    Node(ElemType item, Node<ElemType> *link);
};

template <class ElemType>
Node<ElemType>::Node() {
    next = NULL;
}

template <class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link) {
    data = item;
    next = link;
}


#endif
