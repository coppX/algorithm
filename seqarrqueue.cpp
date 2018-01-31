#include "seqarrqueue.h"
#include <iostream>

/*template<typename T>
bool SeqArrQueue<T>::empty()
{
	return count==0?1:0;
}*/

template<typename T>
T SeqArrQueue<T>::front()
{
	while(head)
		return *head;
	std::cout<<"The queue is empty"<<std::endl;
}

template<typename T>
bool SeqArrQueue<T>::pop()
{
	while(head)
	{
		head++;
		count--;
		return true;
	}
	std::cout<<"The queue is empty"<<std::endl;
	return false;
}

template<typename T>
T SeqArrQueue<T>::back()
{
	while(rear)
		return *rear;
	std::cout<<"The queue is empty"<<std::endl;
}

template<typename T>
bool SeqArrQueue<T>::push(T e)
{
	while(head==nullptr||rear==nullptr)
	{
		arr[0]=e;
		head=rear=&arr[0];
		count=1;
		return true;
	}
	rear++;
	*rear=e;
	count++;
	return true;
}

template<typename T>
int SeqArrQueue<T>::size()
{
	return count;
}

template<typename T>
void SeqArrQueue<T>::print()
{
	while(head==nullptr||rear==nullptr)
	{
		std::cout<<"The queue is empty!"<<std::endl;
		return;
	}
	if(head==rear)
		std::cout<<*head<<std::endl;
	T *p=head;
	while(p!=rear)
	{
		std::cout<<*p<<" ";
		p++;
	}
	std::cout<<*p;
	std::cout<<std::endl;
}

