#include "looparrqueue.cpp"
#include <iostream>

int main()
{
	LoopArrQueue<int> laq;
	int x;
	laq.push(10);
	laq.push(20);
	laq.push(30);
	laq.push(40);

	std::cout<<"此时队列中的元素有"<<laq.size()<<"个，分别为:"<<std::endl;
	laq.print();
	
	x=laq.front();
	laq.pop();
	std::cout<<"删除队头"<<x<<"此时队列中元素有"<<laq.size()
			 <<"个，分别为:"<<std::endl;
	laq.print();

	x=laq.front();
	laq.pop();
	std::cout<<"删除队头"<<x<<"此时队列中元素有"<<laq.size()
			 <<"个，分别为:"<<std::endl;
	laq.print();

	laq.push(50);
	std::cout<<"插入元素50,此时队列中有"<<laq.size()
			 <<"个，分别为:"<<std::endl;
	laq.print();
	
	laq.push(60);
	std::cout<<"插入元素60,此时队列中有"<<laq.size()
			 <<"个，分别为:"<<std::endl;
	laq.print();

	laq.push(70);
	std::cout<<"插入元素70,此时队列中有"<<laq.size()
			 <<"个，分别为:"<<std::endl;
	laq.print();


	return 0;
}
