#ifndef _SEQSTACK_H
#define _SEQSTACK_H
const int size=100;

template<typename T>
class Seqstack
{
public:
	Seqstack():Top(-1){};
	~Seqstack(){};
	bool push(T e);
	bool pop();
	T top();
	bool isEmpty();
	bool isFull();
	void printStack();

private:
	T elem[size];
	int Top;
};

#endif
