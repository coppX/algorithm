#ifndef _DOUBLELIST_H
#define _DOUBLELIST_H

template<typename T>
struct Node{
	Node(T _data)
		:data(_data),prev(nullptr),next(nullptr){};	
	T data;
	Node<T> *prev;
	Node<T> *next;
};

template<typename T>
class Doublelist{
	public:
		Doublelist(Node<T> *_head):head(_head),size(1){};
		~Doublelist()
		{
			destroy();
		}
		//增
		void insert(T p,T key);
		void insertNode(Node<T> *p,Node<T> *_node);

		//删
		bool deleteKey(T key);
		bool deleteNode(Node<T> *_node);
	
		//改
		bool changeKey(T p,T key);

		//查
		Node<T>* search(T key);

		//大小/链表是否为空
		int Size();
		bool empty();
		//排序
		void sort();

		//销毁
		void destroy();
		
		//遍历
		void traverse();
		
		//链表反转
	   	Node<T>* listReverse();
		
				

	private:
		Node<T> *head;
		int size;
};

#endif
