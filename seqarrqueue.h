#ifndef SEQARRQUEUE_H_
#define SEQARRQUEUE_H_

const int arrsize=100;
template<typename T>
class SeqArrQueue
{
	public:
		SeqArrQueue():head(nullptr),rear(nullptr),count(0){};
		~SeqArrQueue(){};
		//bool empty();//判断是否为空
		T front();	//返回队头元素
		bool pop();//删除队头元素
		T back();//返回队尾元素
		bool push(T e);//在队尾加入元素
		int size();//队列大小
		void print();//遍历
	private:
		T arr[arrsize];
		T* head,*rear;
		int count;
};

#endif
