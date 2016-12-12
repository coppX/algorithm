#ifndef SEQLINKQUEUE_H_
#define SEQLINKQUEUE_H_

template<typename T>
struct Node{
	Node(T e):data(e),prev(nullptr),next(nullptr){}
	T data;
	Node<T> *prev;
	Node<T> *next;
};

template<typename T>
class SeqLinkQueue{
	public:
		SeqLinkQueue(int ms):
			head(nullptr),rear(nullptr),count(0),maxsize(ms)
		{}
		~SeqLinkQueue(){}
		T front();  //返回队头
		bool pop();	//删除队头
		T back();	//返回队尾
		bool push(T e);//新插入一个元素
		int size();//返回队列大小
		void print();//打印队列
		bool isEmpty();//判断队列是否为空
		bool isFull();//判断队列是否满
	private:
		Node<T> *head;//队头
		Node<T> *rear;//队尾
		int count;//队列大小
		int maxsize;//队列最大容量
};

#endif
