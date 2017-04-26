#include "node.h"
#include<iostream>
using namespace std;
template<class ElemType>
class LinkQueue 
{
private:                    //  链队列实现的数据成员:
	Node<ElemType> *front, *rear;// 队头队尾指指
    int count;             //队列长度
public:
//  抽象数据类型方法声明
bool Setup();
virtual ~LinkQueue();
void Clear(); 
bool  Empty( );
int  Length( );
bool  InQueue(ElemType  e);
bool  OutQueue(ElemType  &e);
bool GetHead(ElemType &e);
void  Traverse( );
};
template <class ElemType>
bool LinkQueue<ElemType>::Setup()
{
	rear = front = new Node<ElemType>;	
    count=0;
}
template<class ElemType>
void LinkQueue<ElemType>::Clear() 
{         Node<ElemType> *p=front->next;
while(p!=NULL)
{ front->next=p->next; 
delete p;
p=front->next;
   }
    rear=front;   count=0;
}
template<class ElemType>
 LinkQueue<ElemType>::~LinkQueue()
{ Clear();
 }
template<class ElemType>
bool LinkQueue<ElemType>::Empty() 
{
   return count==0;
}
template<class ElemType>
int LinkQueue<ElemType>::Length() 		 
{
	return count;
}
template<class ElemType>
bool LinkQueue<ElemType>::InQueue( ElemType e)
{   Node<ElemType> *tmpPtr = new  Node<ElemType>;
    if (tmpPtr == NULL)   return false;
    tmpPtr->data=e;    tmpPtr->next=NULL;
	rear->next = tmpPtr;					
	rear = tmpPtr;	
    count++;						
	return true;
} 
template<class ElemType>
bool LinkQueue<ElemType>::OutQueue(ElemType &e)
{   if (!Empty()) 
	 {	Node<ElemType> *tmpPtr = front->next;	
		e = tmpPtr->data;					
		front->next = tmpPtr->next;			
		if (rear == tmpPtr)    rear = front;
		delete tmpPtr;	count--;
		return true;   }
	else  return false;
}
template<class ElemType>
bool LinkQueue<ElemType>::GetHead (ElemType &e) 
{   if (!Empty()) 
	{	Node<ElemType> *tmpPtr = front->next;	
		e = tmpPtr->data;					
		return true;
	}
	else   return false;  
}
template <class ElemType>
void LinkQueue<ElemType>::Traverse() 
{
	for (Node<ElemType> *tmpPtr = front->next; tmpPtr != NULL;   tmpPtr = tmpPtr->next)
	{	cout<<tmpPtr->data<<'\t';
	}
}
