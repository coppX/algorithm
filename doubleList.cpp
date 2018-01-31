#include "doublelist.h"
#include <iostream>
//#define NDEBUG
#include <cassert>

template<typename T>
void Doublelist<T>::insert(T p,T key)
{
	Node<T> *pt=search(p);	//查找键值p在链表中的位置
	assert(pt!=nullptr);
	Node<T> *node=new Node<T>(key);	//生成一个节点，其键值为key
	assert(node!=nullptr);
	insertNode(pt,node);	
}

template<typename T>
void Doublelist<T>::insertNode(Node<T> *p,Node<T> *_node)
{
	if(head==nullptr&&p==nullptr)
		head=_node;
	if(p==nullptr||_node==nullptr)
		return;
	if(p->next!=nullptr)	//在节点p后面插入
	{
		_node->prev=p->next->prev;
		_node->next=p->next;
		_node->next->prev=_node;
		p->next=_node;
		size++;
		return;
	}
	else if(p->next==nullptr)	//尾插
	{
		p->next=_node;
		_node->prev=p;
		_node->next=nullptr;
		size++;
		return;
	}
}

template<typename T>
bool Doublelist<T>::deleteKey(T key)
{
	Node<T>* p=search(key);
//	assert(p!=nullptr);
	if(p==nullptr)	
		return false;
	deleteNode(p);
}

template<typename T>
bool Doublelist<T>::deleteNode(Node<T> *_node)
{
	if(_node!=nullptr)	
	{	
		_node->prev->next=_node->next;
		_node->next->prev=_node->prev;
		delete _node;
		size--;
		return true;
	}
	else return false;
}

template<typename T>
bool changeKey(T p,T key)
{
	Node<T> *node=search(p);
	if(node!=nullptr)
	{
		node->data=key;
		return true;
	}
	else return false;
}

template<typename T>
Node<T>* Doublelist<T>::search(T key)
{
	Node<T> *tmp=head;
	while(tmp!=nullptr)
	{
		if(tmp->data==key)
			return tmp;
		tmp=tmp->next;
	}
	return nullptr;
}

template<typename T>
int Doublelist<T>::Size()
{
	return size;
}

template<typename T>
bool Doublelist<T>::empty()
{
	return size==0?true:false;
}

template<typename T>
void Doublelist<T>::sort()
{
	Node<T> *p=head;//冒泡排序
	int len=Size();
	if(len==0||len==1)
		return;
	for(int i=1;i<len;i++)
	{
		p=head;
		for(int j=0;j<len-i;j++)
		{
			if(p->data>p->next->data)
			{
				T tmp=p->data;
				p->data=p->next->data;
				p->next->data=tmp;
			}
			p=p->next;
		}
	}
}

template<typename T>
void Doublelist<T>::destroy()
{
	while(head)
	{
		Node<T> *tmp=head->next;
		delete(head);
		head=tmp;
	}
}

template<typename T>
void Doublelist<T>::traverse()
{
	Node<T> *tmp=head;
	while(tmp!=nullptr)
	{
		std::cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	std::cout<<std::endl;
}

template<typename T>
Node<T>* Doublelist<T>::listReverse()//链表反转
{
	Node<T> *pnode=head,*pre=nullptr;
	while(pnode)
	{
		Node<T> *pnext=pnode->next;//保存pnode的后继
		pnode->next=pre;		   //将pnode的前驱变为pnode的后继
		pnode->prev=pnext;			
		pre=pnode;				   //pre向后移
		pnode=pnext;			   //pnode向后移
	}
	head=pre;					   //pnode为空时，将链表头设为pre
	return head;
}
