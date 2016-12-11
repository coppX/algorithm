#include "seqarrqueue.cpp"
#include <iostream>

int main()
{
	SeqArrQueue<int> saq;
	static int x=0;
	saq.push(10);
	saq.push(20);
	saq.push(30);
	saq.push(40);
	saq.push(50);
	std::cout<<"队列中的所有元素如下:"<<std::endl;
	saq.print();

	std::cout<<"返回队头元素"<<std::endl;
	std::cout<<saq.front()<<std::endl;

	std::cout<<"此时队列的元素有"<<saq.size()<<"个元素，分别为:"<<std::endl;
	saq.print();

	x=saq.front();
	saq.pop();
	std::cout<<"队列删除队头元素"<<x<<"，此时队列的元素有"<<saq.size()<<"个元素，分别为:"<<std::endl;
	saq.print();

	std::cout<<"队列的队尾元素为"<<saq.back()<<std::endl;
	saq.push(60);
	std::cout<<"队列新入一个元素,此时的队列元素有"<<saq.size()<<"个，分别为:"<<std::endl;
	saq.print();
  
  return 0;
}
