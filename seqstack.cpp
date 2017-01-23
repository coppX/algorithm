#include <iostream>
#include "seqstack.h"

template<typename T>
bool Seqstack<T>::push(T e)
{
	if(Top==size-1)
		return false;
	elem[++Top]=e;
	return true;
}

template<typename T>
bool Seqstack<T>::pop()
{
	if(Top==-1)
		return false;
	Top--;
	return true;
}

template<typename T>
T Seqstack<T>::top()
{
	if(Top==-1)
		std::cout<<"栈为空"<<std::endl;
	return elem[Top];
}

template<typename T>
bool Seqstack<T>::isEmpty()
{
	if(Top==-1)
		return true;
	return false;
}

template<typename T>
bool Seqstack<T>::isFull()
{
	if(Top==size-1)
		return true;
	return false;
}

template<typename T>
void Seqstack<T>::printStack()
{
	if(Top>=0)
	{
		for(int i=0;i<=Top;i++)
			std::cout<<elem[i]<<" ";
		std::cout<<std::endl;
		return;
	}
	std::cout<<"栈为空"<<std::endl;
}


	
