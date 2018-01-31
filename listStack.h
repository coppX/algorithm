#ifndef _LISTSTACK_H
#define _LISTSTACK_H

template<typename T>
struct Node
{
	Node(T _data,Node<T> *n=nullptr)
		:data(_data),next(n){};
	T data;
	Node<T> *next;
};

template<typename T>
class ListStack
{
public:
	ListStack():Top(nullptr),Buttom(nullptr){};
	~ListStack(){};
	void push(T elem);
	bool pop();
	bool top(T &e);
	bool isEmpty();
	void printStack();
	
private:
	Node<T> *Top;
	Node<T> *Buttom;
};

#endif
