#include <iostream>
#include "liststack.h"

template<typename T>
void ListStack<T>::push(T elem)
{
	Node<T> *node=new Node<T>(elem);
	if(Top==nullptr)
	{
		Top=node;
		Buttom=node;
		return;
	}
	Top->next=node;
	Top=Top->next;
}

template<typename T>
bool ListStack<T>::pop()
{
	if(Top==nullptr)
	{
		std::cout<<"链表为空"<<std::endl;
		return false;
	}
	Node<T> *p1=Buttom,*p2=Buttom->next;

	while(p2!=Top&&Top!=Buttom)
	{
		p1=p1->next;
		p2=p2->next;
	}
	
	Top=p1;
	delete p2;
	Top->next=nullptr;
}

template<typename T>
bool ListStack<T>::top(T &e)
{
	if(Top==nullptr)
	{
		std::cout<<"链表为空"<<std::endl;
		return false;
	}
	e=Top->data;
	return true;
}

template<typename T>
bool ListStack<T>::isEmpty()
{
	if(Top==nullptr)
		return true;
	return false;
}

template<typename T>
void ListStack<T>::printStack()
{
	Node<T> *tmp=Buttom;
	while(tmp!=Top)
	{
		std::cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	std::cout<<Top->data<<std::endl;
}
