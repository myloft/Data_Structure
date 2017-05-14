#include <iostream>
#include <cstdlib>
#include "node.h"
using namespace std;

template<class ElemType>
class LkQueue{
	protected:
		Node<ElemType> *front,*rear;
		int count;
	public:
		LkQueue();
		virtual ~LkQueue();
		bool Empty();
		bool OutQueue(ElemType & e);
		bool GetHead(ElemType &e);
		bool InQueue(ElemType e);
		void Traverse();
};

template<class ElemType>
LkQueue<ElemType>::LkQueue(){
	rear=front=new Node<ElemType>;
	count=0;
}

template<class ElemType>
LkQueue<ElemType>::~LkQueue(){
	ElemType tempElem;
	while(!Empty()){
		OutQueue(tempElem);
	}
}

template<class ElemType>
bool LkQueue<ElemType>::Empty(){
	return count==0;
}

template<class ElemType>
bool LkQueue<ElemType>::OutQueue(ElemType &e){
	if(!Empty()){
		Node<ElemType> *tempPtr=front->next;
		e=tempPtr->data;
		front->next=tempPtr->next;
		if(rear==tempPtr){
			rear=front;
		}
		delete tempPtr;
		count--;
		return true;
	}
	else{
		return false;
	}
}

template<class ElemType>
bool LkQueue<ElemType>::GetHead(ElemType &e){
	if(!Empty()){
		Node<ElemType> *tempPtr;
		tempPtr=front->next;
		e=tempPtr->data;
		return true;
	}
	else{
		return false;
	}
}

template<class ElemType>
bool LkQueue<ElemType>::InQueue(ElemType e){
	Node<ElemType> *tempPtr;
	tempPtr=new Node<ElemType>;
	tempPtr->data=e;
	rear->next=tempPtr;
	rear=tempPtr;
	count++;
	return true;
}

template<class ElemType>
void LkQueue<ElemType>::Traverse(){
	Node<ElemType> *tempPtr;
	tempPtr=front->next;
	while(tempPtr!=NULL){
		cout<<tempPtr->data<<endl;
		tempPtr=tempPtr->next;
	}
}
