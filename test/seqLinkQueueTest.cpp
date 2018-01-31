#include "../seqlinkqueue.cpp"
#include <iostream>

int main()
{
	SeqLinkQueue<int> slq(5);
	int x;
	slq.push(10);
	slq.push(20);
	slq.push(30);
	slq.push(40);

	std::cout<<"此时队列中的元素有"<<slq.size()<<"个，分别为:"<<std::endl;
	slq.print();
	
	x=slq.front();
	slq.pop();
	std::cout<<"删除队头"<<x<<"此时队列中元素有"<<slq.size()
			 <<"个，分别为:"<<std::endl;
	slq.print();

	x=slq.front();
	slq.pop();
	std::cout<<"删除队头"<<x<<"此时队列中元素有"<<slq.size()
			 <<"个，分别为:"<<std::endl;
	slq.print();

	slq.push(50);
	std::cout<<"插入元素50,此时队列中有"<<slq.size()
			 <<"个，分别为:"<<std::endl;
	slq.print();
	
	slq.push(60);
	std::cout<<"插入元素60,此时队列中有"<<slq.size()
			 <<"个，分别为:"<<std::endl;
	slq.print();

	slq.push(70);
	std::cout<<"插入元素70,此时队列中有"<<slq.size()
			 <<"个，分别为:"<<std::endl;
	slq.print();


	return 0;
}
