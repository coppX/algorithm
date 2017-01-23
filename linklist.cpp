#include <iostream>
#include "linklist.h"

template<typename T>
void Linklist<T>::insertNode(Node<T> *p,Node<T> *_node)
{
	if(head==nullptr||p==nullptr||_node==nullptr)
		return;
	Node<T> *tmp=p->next;
	p->next=_node;
	_node->next=tmp;
	size++;
}

template<typename T>
void Linklist<T>::insert(T p,T key)
{
	Node<T> *_node=new Node<T>(key);
	Node<T> *pt=search(p);
	insertNode(pt,_node);
}

template<typename T>
bool Linklist<T>::deletekey(T key)
{
	Node<T> *p=search(key);
	if(p==nullptr)
		return false;
	deleteNode(p);
}

template<typename T>
bool Linklist<T>::deleteNode(Node<T> *_node)
{
	bool sign=search(_node->data);
	if(sign==0)
		return false;
	_node->data=_node->next->data;
	_node->next=_node->next->next;
	size--;
}

template<typename T>
bool Linklist<T>::empty()
{
	return size==0?true:false;
}

template<typename T>
Node<T>* Linklist<T>::search(T key)
{
	Node<T> *p=head;
	while(p!=nullptr)
	{
		if(p->data==key)
			return p;
		p=p->next;
	}
	return nullptr;
}

template<typename T>
bool Linklist<T>::search(Node<T> *_node)
{
	Node<T> *p=head;
	while(p->next!=nullptr)
	{
		if(p->next->data==_node->data)
			return true;
		p=p->next;
	}
	return false;
}

template<typename T>
void Linklist<T>::traverse()
{
	Node<T> *tmp=head;
	while(tmp)
	{
		std::cout<<tmp->data<<"  ";
		tmp=tmp->next;
	}
}

template<typename T>
void Linklist<T>::reverseTraverse()
{
	listReverse();
	traverse();
	listReverse();
}

template<typename T>
Node<T>* Linklist<T>::listReverse()
{
	Node<T> *p1,*p2,*p3,*node=head;
	if(head==nullptr||head->next==nullptr)
		return head;
	p1=head;
	p2=head->next;
	while(p2!=nullptr)
	{
		p3=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p3;
	}
	head->next=nullptr;
	head=p1;
	return head;
}

template<typename T>
void Linklist<T>::destroy()
{
	if(head==nullptr)
		return;
	if(head)
	{
		Node<T> *tmp=head->next;
		delete(head);
		head=tmp;
	}
}

template<typename T>
int Linklist<T>::listSize()
{
	return size;
}

template<typename T>
void Linklist<T>::sort()
{
	int len=listSize();
	if(len==0||len==1)
		return;
	Node<T> *p=head;
	for(int i=1;i<len;i++)
	{
		p=head;
		for(int j=0;j<len-i;j++)
		{
			if(p->data>p->next->data)
			{
				int tmp=p->data;
				p->data=p->next->data;
				p->next->data=tmp;
			}
			p=p->next;
		}
	}
}
