#include "doublelist.cpp"
#include <iostream>

int main()
{
	Node<int> *node1=new Node<int>(110);
	Doublelist<int> list(node1);
	
	list.insert(110,11);
	list.insert(11,14);
	list.insert(110,13);
	list.insert(13,40);
	std::cout<<"链表里面的元素有"<<list.Size()
		<<"个,分别是:"<<std::endl;
	list.traverse();
	std::cout<<std::endl;
	std::cout<<"反向遍历,链表里元素有"<<list.Size()
		<<"个，分别是:"<<std::endl;
	list.listReverse();
	list.traverse();
	list.listReverse();

	std::cout<<std::endl;

	list.deleteKey(11);
	std::cout<<"删除一个元素11，链表的元素有"<<list.Size()
		<<"个，分别是:"<<std::endl;
	list.traverse();
	std::cout<<std::endl;
	std::cout<<"反转链表,链表里的元素有"<<list.Size()
		<<"个，分别是:"<<std::endl;
	list.listReverse();
	list.traverse();
	
	std::cout<<std::endl;
	std::cout<<"链表排序，链表元素有"<<list.Size()
		<<"个，分别是:"<<std::endl;
	list.sort();
	list.traverse();	
	
	std::cout<<std::endl;
	return 0;
}
