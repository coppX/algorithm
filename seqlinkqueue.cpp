#include "seqlinkqueue.h"
#include <iostream>
#include <stdlib.h>

template<typename T>
T SeqLinkQueue<T>::front()
{
	if(isEmpty())
	{
		std::cout<<"The queue is empty!"<<std::endl;
		exit(1);
	}
	return head->data;
}

template<typename T>
bool SeqLinkQueue<T>::pop()
{
	if(isEmpty())
	{
		std::cout<<"The queue is empty!"<<std::endl;
		return false;
	}
	head=head->next;
	delete head->prev;
	count--;
	return true;
}

template<typename T>
T SeqLinkQueue<T>::back()
{
	if(isEmpty())
	{
		std::cout<<"The queue is empty!"<<std::endl;
		exit(1);
	}
	return rear->data;
}

template<typename T>
bool SeqLinkQueue<T>::push(T e)
{
	Node<T> *node=new Node<T>(e);//新建一个队列节点
	if(isEmpty())	//队列为空时
	{
		head=rear=node;
		count=1;
		return true;
	}
	if(isFull())	//队列满时，不能插入元素
	{
		std::cout<<"The queue is full!cannot push any element."<<std::endl;
		return false;
	}
	rear->next=node;//普通情况
	rear=rear->next;
	count++;
	return true;
}

template<typename T>
int SeqLinkQueue<T>::size()
{
	return count;
}

template<typename T>
void SeqLinkQueue<T>::print()
{
	if(isEmpty())	//队列为空
	{
		std::cout<<"The queue is empty!"<<std::endl;
		return;
	}
	Node<T> *p=head;
	if(p==rear)		//队列只有一个元素
	{
		std::cout<<p->data<<std::endl;
		return;
	}
	while(p!=rear)	//队列不止一个元素
	{
		std::cout<<p->data<<" ";
		p=p->next;
	}
	std::cout<<p->data<<std::endl;
}

template<typename T>
bool SeqLinkQueue<T>::isEmpty()
{
	return count==0?true:false;
}

template<typename T>
bool SeqLinkQueue<T>::isFull()
{
	return count==maxsize?true:false;
}
