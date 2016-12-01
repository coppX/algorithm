#ifndef LINKLIST_H
#define LINKLIST_H

template<typename T>
struct Node
{
		Node(T _data,Node<T> *n=nullptr):data(_data),next(n){};
		T data;
		Node<T> *next;
};

template<typename T>
class Linklist
{
	public:
		Linklist(Node<T> *_node):head(_node),size(1){};
		~Linklist()
		{
			destroy();
		}

		void insertNode(Node<T> *p,Node<T> *_node);//p节点后插入节点_node
		void insert(T p,T key);//键值p后面插入数值key

		bool deletekey(T key);//删除数值
		bool deleteNode(Node<T> *_node);//删除节点

		void destroy();//销毁
		
		Node<T>* search(T key);//查找key
		bool search(Node<T> *_node);//查找节点

		bool empty();//判断链表是否为空

		void traverse();//遍历
		void reverseTraverse();//反向遍历	
		Node<T>* listReverse();//链表反转
		int listSize();		//链表大小
		
		void sort();		//排序
	private:
		Node<T> *head;
		int size;
};

#endif
