#include <iostream>
#include "liststack.cpp"

int main()
{
	ListStack<int> ls;
	ls.push(10);
	ls.push(20);
	ls.push(30);
	ls.push(40);
	std::cout<<"链栈里的元素为:"<<std::endl;
	ls.printStack();

	std::cout<<"栈顶出栈"<<std::endl;
	ls.pop();
	ls.printStack();

	std::cout<<"栈顶出栈"<<std::endl;
	ls.pop();
	ls.printStack();

	std::cout<<"新元素入栈"<<std::endl;
	ls.push(50);
	ls.printStack();

	return 0;
}
