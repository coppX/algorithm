#include "seqstack.cpp"
#include <iostream>

int main()
{
	Seqstack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	std::cout<<"此时栈内元素:"<<'\n';
	st.printStack();

	std::cout<<"栈顶"<<st.top()<<"出栈"<<'\n';
	st.pop();
	st.printStack();

	std::cout<<"栈顶"<<st.top()<<"出栈"<<'\n';
	st.pop();
	st.printStack();

	std::cout<<"新元素入栈"<<'\n';
	st.push(50);
	st.printStack();

	return 0;
}
	
	
