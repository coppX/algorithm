#ifndef _LOOPARRQUEUE_H
#define _LOOPARRQUEUE_H

const int arrsize=5;

template<typename T>
class LoopArrQueue
{
	public:
		LoopArrQueue():head(nullptr),rear(nullptr),count(0){};
		~LoopArrQueue(){};
		
		T front();//返回队头元素
		bool pop();//删除队头元素
		T back();//返回队尾元素
		void push(T e);//在队尾加入元素
		int size();//队列大小
		void print();//遍历

	private:
		T arr[arrsize];
		T *head,*rear;
		int count;
};

#endif
