#include "looparrqueue.h"
#include <iostream>

template<typename T>
T LoopArrQueue<T>::front()
{
	if(head!=nullptr||rear!=nullptr)
		return *head;
	else std::cout<<"The queue is empty!"<<std::endl;
}

template<typename T>
bool LoopArrQueue<T>::pop()
{
	if(head==nullptr||rear==nullptr)
	{
		std::cout<<"The queue is empty!"<<std::endl;
		return false;
	}
	if(head==&arr[arrsize-1])//队头为数组最后一个位置时，
							  //删除队头后，新队头为数组开始
	{
		head=&arr[0];
		count--;
		return true;
	}
	head++;
	count--;
	return true;
}

template<typename T>
T LoopArrQueue<T>::back()
{
	if(head==nullptr||rear==nullptr)
	{
		std::cout<<"The queue is empty!"<<std::endl;
		return (T)nullptr;
	}
	return *rear;
}

template<typename T>
void LoopArrQueue<T>::push(T e)
{
	if(count==arrsize)
	{
		std::cout<<"The queue is full!cannot push any element."<<std::endl;
		return;
	}
	if(head==nullptr||rear==nullptr)//当队列为空时
	{
		arr[0]=e;
		head=rear=&arr[0];
		count=1;
		return;
	}
	if(rear==&arr[arrsize-1])//如果队尾是数组最后一个位置，
							 //	新插入的元素就该位于数组开始
	{
		arr[0]=e;
		rear=&arr[0];
		count++;
		return;
	}
	//一般情况
	rear++;
	*rear=e;
	count++;
}

template<typename T>
int LoopArrQueue<T>::size()
{
	return count;
}

template<typename T>
void LoopArrQueue<T>::print()
{
	if(head==nullptr||rear==nullptr)
	{
		std::cout<<"The queue is empty!"<<std::endl;
		return;
	}
	T *p=head;
	if(p==rear)//队列只有一个元素
	{
		std::cout<<*p<<std::endl;
		return;
	}
	//从front开始遍历，在遇到arr[arrsize-1]和rear之前输出元素
	while(p!=&arr[arrsize-1]&&p!=rear)
	{
		std::cout<<*p<<" ";
		p++;
	}
	//如果p不等于rear，此时p必等于arr[arrsize-1]
	if(p!=rear)
	{
		std::cout<<*p<<" ";
		p=&arr[0];//将p置于数组开始，然后遍历到rear
	}
	while(p!=rear)
	{
		std::cout<<*p<<" ";
		p++;
	}
	std::cout<<*rear<<std::endl;
}
