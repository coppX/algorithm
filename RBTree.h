/*
 * 红黑树 C++
 * @author coppX
 * @data 2016/11/8
 */

#ifndef _RED_BLACK_TREE_HPP_
#define _RED_BLACK_TREE_HPP_

#include <iostream>
#include <iomanip>

using namespace std;

enum RBTColor{RED,BLACK};

template<typename T>
class RBTNode{
	public:
		RBTColor color;
		T key;
		RBTNode *left;
		RBTNode *right;
		RBTNode *parent;

		RBTNode(T value,RBTColor c,RBTNode *p,RBTNode *l,RBTNode *r):
			key(value),color(c),parent(),left(l),right(r){}
};

template<typename T>
class RBTree{
	private:
		RBTNode<T> *mRoot;
	public:
		RBTree();
		~RBTree();

		void preOrder();//前序遍历红黑树
		void inOrder(); //中序遍历红黑树
		void postOrder();//后序遍历红黑树
		RBTNode<T>* search(T key);	//(递归实现)查找红黑树中键值为key的节点
		RBTNode<T>* iterativeSearch(T key);//(非递归实现)查找红黑树中键值为key的节点
		T minimum();//查找最小节点
		T maximum();//查找最大节点
		RBTNode<T>* successor(RBTNode<T> *x);//找节点(x)的后继节点，即查找红黑树中数值大于该节点的最小节点
		RBTNode<T>* predecessor(RBTNode<T> *x);//找节点(x)的前驱节点，即查找红黑树中数值小于该节点的最大节点
		void insert(T key); //将节点key插入到红黑i树中
		void remove(T key); //删除节点key为节点键值
		void destroy();//销毁红黑树
		void print();//打印红黑树
	private:
		void preOrder(RBTNode<T>* tree) const;//前序遍历红黑树
		void inOrder(RBTNode<T>* tree) const; //中序遍历红黑树
		void postOrder(RBTNode<T>* tree) const;//后序遍历红黑树
		//(递归实现)查找红黑树x中键值为key的节点
		RBTNode<T>* search(RBTNode<T>* x,T key) const;
		//(非递归实现)查找红黑树x中键值为key的节点
		RBTNode<T>* iterativeSearch(RBTNode<T>* x,T key) const;
		RBTNode<T>* minimum(RBTNode<T>* tree);//查找红黑树tree中的最小节点
		RBTNode<T>* maximum(RBTNode<T>* tree);//查找红黑树tree中的最大节点
		void leftRotate(RBTNode<T>* &root,RBTNode<T> *x);//左旋
		void rightRotate(RBTNode<T>* &root,RBTNode<T> *y);//右旋
		void insert(RBTNode<T>* &root,RBTNode<T>* node);//插入函数
		void insertFixUp(RBTNode<T>* &root,RBTNode<T>* node);//插入修正函数
		void remove(RBTNode<T>* &root,RBTNode<T> *node);//删除函数
		void removeFixUp(RBTNode<T>* &root,RBTNode<T> *node,RBTNode<T> *parent);//删除修正函数
		void destroy(RBTNode<T>*&tree);//销毁红黑树
		void print(RBTNode<T>* tree,T key,int direction);//打印红黑树
#define rb_parent(r)	((r)->parent)
#define rb_color(r)		((r)->color)
#define rb_is_red(r)	((r)->color==RED)
#define rb_is_black(r)	((r)->color==BLACK)
#define rb_set_black(r)	do{ (r)->color=BLACK;}while(0)
#define rb_set_red(r)	do{	(r)->color=RED;}while(0)
#define rb_set_parent(r,p)	do{(r)->parent=(p);}while(0)
#define rb_set_color(r,c)	do{(r)->color=(c);}while(0)
};
