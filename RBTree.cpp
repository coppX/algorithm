/*
 * 红黑树 C++
 * @author Neko_Toi
 * @data 2016/11/8
 */

#include <iostream>
#include <iomanip>
#include "RBTree.h"

//构造函数
template<typename T>
RBTree<T>::RBTree():mRoot(nullptr)
{
}

//析构函数
template<typename T>
RBTree<T>::~RBTree()
{
	destroy();
}

//(递归实现)前序遍历红黑树
template<typename T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
	if(tree!=nullptr)
	{
		cout<<tree->key<<" ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template<typename T>
void RBTree<T>::preOrder()
{
	preOrder(mRoot);
}

//(递归实现)中序遍历红黑树
template<typename T>
void RBTree<T>::inOrder(RBTNode<T> *tree) const
{
	if(tree!=nullptr)
	{
		inOrder(tree->left);
		cout<<tree->key<<" ";
		inOrder(tree->right);
	}
}

template<typename T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}

//(递归实现)后序遍历红黑树
template<typename T>
void RBTree<T>::postOrder(RBTNode<T> *tree) const
{
	if(tree!=nullptr)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout<<tree->key<<" ";
	}
}

template<typename T>
void RBTree<T>::postOrder() 
{
	postOrder(mRoot);
}

//(递归实现)查找红黑树x中键值为key的节点
template<typename T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x,T key) const
{
	if(x==nullptr||x->key==key)
		return x;
	if(key<x->key)
		return search(x->left,key);
	else
		return search(x->right,key);
}

template<typename T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot,key);
}

//(非递归实现)查找红黑树x中键值为key的节点
template<typename T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T> *x,T key) const
{
	while((x!=nullptr)&&(x->key!=key))
	{
		if(key<x->key)
			x=x->left;
		else
			x=x->right;
	}
	return x;
}

template<typename T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot,key);
}

//查找最小节点，返回tree为根节点的红黑树的最小节点
template<typename T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T> *tree)
{
	if(tree==nullptr)
		return tree;
	while(tree->left!=nullptr)
		tree=tree->left;
	return tree;
}

template<typename T>
T RBTree<T>::minimum()
{
	RBTNode<T> *p=minimum(mRoot);
	if(p!=nullptr)
		return p->key;
	return (T)NULL;
}

//查找最大节点，返回tree为根节点的红黑树的最大节点
template<typename T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T> *tree)
{
	if(tree==nullptr)
		return nullptr;
	while(tree->right!=nullptr)
		tree=tree->right;
	return tree;
}

template<typename T>
T RBTree<T>::maximum()
{
	RBTNode<T> *p=maximum(mRoot);
	if(p!=nullptr)
		return p->key;
	return (T)NULL;
}

//查找x的后继节点，即查找红黑树中数值大于该节点的最小节点
template<typename T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x)
{
	if(x->right!=nullptr)//如果x存在右孩子，该值为右孩子中最小的那个
		return minimum(x->right);
	//如果x没有右孩子，x有两种可能:
	//x是一个左孩子，x的后继为它的父节点
	//x是一个右孩子，则查找x的最低父节点，并且该父节点要具有左孩子
	//这个最低父节点就是x的后继
	//    p        p
	//  /         / \
	// z         z   \
	//  \             \
	//   \             \
	//    x             x
	//   /              /
	RBTNode<T> *y=x->parent;
	while((y!=nullptr)&&(x==y->right))
	{
		x=y;
		y=y->parent;
	}
	return y;
}

//查找节点x的前驱节点。即查找红黑树中小于该节点的最大节点
template<typename T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T> *x)
{
	if(x->left!=nullptr)//如果该节点存在左孩子，则前驱为该节点的左孩子中最大值
		return maximum(x->left);
	//如果x没有左孩子，有两种情况:
	//x是一个右孩子，其前驱为其父节点
	//x是一个左孩子，则查找其最低父节点，该父节点要具有右孩子
	//这个最低父节点为该节点的前驱
	//     p
	//      \
	//       z
	//      /
	//     /
	//    x
	//     \
	//
	RBTNode<T> *y=x->parent;
	while((y!=nullptr)&&(x==y->left))
	{
		x=y;
		y=y->parent;
	}
	return y;
}

/*对红黑树的节点x进行左旋转
         px						px
		 /					    /
		x    --(左旋)-->	   	   y	
	   / \                    / \
	  lx  y                  x  ry
	     / \                / \
		ly  ry             lx  ly
*/
template<typename T>
void RBTree<T>::leftRotate(RBTNode<T>* &root,RBTNode<T>* x)
{
	//设置x的右孩子为y
	RBTNode<T>* y=x->right;
	//将y的左孩子设为x的右孩子
	//如果y的左孩子非空，将x设为y的左孩子的父亲
	x->right=y->left;
	if(y->left!=nullptr)
		y->left->parent=x;
	//将x的父亲设为y的父亲
	y->parent=x->parent;
	if(x->parent==nullptr)
	{
		root=y;//如果x的父节点为空，将y设置为根节点
	}
	else
	{
		if(x->parent->left==x)
			x->parent->left=y;
	   	//如果x是它父节点的左孩子，则将y设为x父节点的左孩子
		else
			x->parent->right=y;
	}
	//将x设为y的左孩子
	y->left=x;
	//将x的父节点设为y
	x->parent=y;
}

/*
 * 对红黑树的节点y进行右旋
 *               py                         py
 *               /                          /
 *              y		--(右旋)-->        x
 *             / \                        / \
 *            x   ry                     lx  y
 *           / \                            / \
 *          lx  rx                         rx  ry
 * */
template<typename T>
void RBTree<T>::rightRotate(RBTNode<T> *&root,RBTNode<T> *y)
{
	//设置x是当前节点的左孩子
	RBTNode<T> *x=y->left;
	//将x的右孩子设置为y的左孩子，
	//如果x的右孩子不为空的话，将y设置为x的右孩子的父亲
	y->left=x->right;
	if(x->right!=nullptr)
		x->right->parent=y;
	//将y的父亲设置为x的父亲
	x->parent=y->parent;
	if(y->parent==nullptr)
	{
		root=x; //如果y的父亲为空，则设置x为根节点
	}
	else
	{
		if(y=y->parent->right)
			y->parent->right=x;
		//如果y是它父节点的右孩子，将x设置为y的父节点的右孩子
		else 
			y->parent->left=x;
		//如果y是它父节点的左孩子，将x设置为y的父节点的左孩子
	}
	//将y设置为x的右孩子
	x->right=y;
	//将y的父节点设置为x
	y->parent=x;
}

/*
 * 红黑树插入修正函数
 *
 * 在向红黑树中插入节点之后(失去平衡)，在调用该函数;
 * 目的是将它重新塑造成一棵红黑树
 *
 * 参数说明:
 * root 红黑树的根
 * node插入的节点  //对应算法导论中的z
 * */

template<typename T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root,RBTNode<T>* node)
{
	RBTNode<T> *parent,*gparent;
	//若父节点存在，并且父节点是红色的
	while((parent=rb_parent(node))&&rb_is_red(parent))
	{
		gparent=rb_parent(parent);
		//若父节点是祖父节点的左孩子
		if(parent==gparent->left)
		{
			//case1 条件:叔叔节点是红色
			{
				RBTNode<T> *uncle=gparent->right;
				if(uncle&&rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node=gparent;
					continue;
				}
			}
			//case2 条件:叔叔节点是黑色的，而且当前节点是右孩子
			if(parent->right==node)
			{
				RBTNode<T> *tmp;
				leftRotate(root,parent);
				tmp=parent;
				parent=node;
				node=tmp;
			}
			rb_set_black(parent);
			rb_set_red(gparent);
			rightRotate(root,gparent);
		}
		else //若z的父节点是z的祖父节点的右孩子
		{
			//case1 条件:叔叔节点是红色的
			{
				RBTNode<T> *uncle=gparent->left;
				if(uncle&&rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node=gparent;
					continue;
				}
			}
			//case2 条件:叔叔节点是黑色，且当前节点是左孩子
			if(parent->left==node)
			{
				RBTNode<T> *tmp;
				rightRotate(root,parent);
				tmp=parent;
				parent=node;
				node=tmp;
			}
			//case3 条件:叔叔节点是黑色，且当前节点是右孩子
			rb_set_black(parent);
			rb_set_red(gparent);
			leftRotate(root,gparent);
		}
	}
	rb_set_black(root);//将根节点设为黑色
}

/*
 *将节点插入到红黑树中
 * 参数说明:
 *		root红黑树的根节点
 *		node插入的节点  //对应算法导论中的node
 * */
template<typename T>
void RBTree<T>::insert(RBTNode<T>* &root,RBTNode<T>* node)
{
	RBTNode<T> *y=nullptr;
	RBTNode<T> *x=root;
	//1.将红黑树当作一棵二叉查找树，将节点添加到二叉查找树中
	while(x!=nullptr)
	{
		y=x;
		if(node->key<x->key)
			x=x->left;
		else
			x=x->right;
	}
	node->parent=y;
	if(y!=nullptr)
	{
		if(node->key<y->key)
			y->left=node;
		else
			y->right=node;
	}
	else
		root=node;
	//2.设置节点的颜色为红色
	node->color=RED;
	//3.将它重新修正为一棵二叉查找树
	insertFixUp(root,node);
}

/*
 * 将节点(key为节点键值)插入到红黑树中
 *
 * 参数说明:
 *		tree红黑树的根节点
 *		key 插入节点的键值
 */

template<typename T>
void RBTree<T>::insert(T key)
{
	RBTNode<T> *z=nullptr;
	//如果新建节点失败，则返回
	if((z=new RBTNode<T>(key,BLACK,nullptr,nullptr,nullptr))==nullptr)
		return;
	insert(mRoot,z);
}

/*红黑树删除修正函数
 *
 * 在从红黑树中删除插入节点之后(红黑树失去平衡)，在调用该函数
 * 目的是将它重新塑造成一棵红黑树
 *
 * 参数说明:
 *	root红黑树的根
 *	node待修正的节点
 */

template<typename T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root,RBTNode<T> *node,RBTNode<T> *parent)
{
	RBTNode<T> *other;
	while((!node||rb_is_black(node))&&node!=root)
	{
		if(parent->left==node)
		{
			other=parent->right;
			if(rb_is_red(other))
			{
				//case1:x的兄弟w是红色的
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root,parent);
				other=parent->right;
			}
			if((!other->left||rb_is_black(other->left))&&
			   (!other->right||rb_is_black(other->right)))
			{
				//case2:x的兄弟w是黑色的，且w的两个孩子也是黑色的
				rb_set_red(other);
				node=parent;
				parent=rb_parent(node);
			}
			else
			{
				if(!other->right||rb_is_black(other->right))
				{
					//case3:x的兄弟w是黑色，并且w的左孩子是红色，右孩子为黑色。
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root,other);
					other=parent->right;
				}
				//case4:x的兄弟w是黑色的，并且w的右孩子是红色的，左孩子为任意颜色
				rb_set_color(other,rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->right);
				leftRotate(root,parent);
				node=root;
				break;
			}
		}
		else
		{
			other=parent->left;
			if(rb_is_red(other))
			{
				//case1:x的兄弟w是红色的
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root,parent);
				other=parent->left;
			}
			if((!other->left||rb_is_black(other->left))&&
			   (!other->right||rb_is_black(other->right)))
			{
				//case 2:x的兄弟w是黑色，且w的两个孩子也都是黑色的
				rb_set_red(other);
				node=parent;
				parent=rb_parent(node);
			}
			else
			{
				if(!other->left||rb_is_black(other->left))
				{
					//case3:x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root,other);
					other=parent->left;
				}
				//case4:x的兄弟w是黑色的，并且w的右孩子是红色的，左孩子为任意色
				rb_set_color(other,rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->left);
				rightRotate(root,parent);
				node=root;
				break;
			}
		}
	}
	if(node)
		rb_set_black(node);
}


/*
 *
 * 删除节点(node)，并返回被删除的节点
 *
 * 参数说明:
 *		root红黑树的根节点
 *		node删除的节点
 */

template<typename T>
void RBTree<T>::remove(RBTNode<T>* &root,RBTNode<T> *node)
{
	RBTNode<T> *child,*parent;
	RBTColor color;

	//被删除节点的左右孩子都不为空的情况
	if((node->left!=nullptr)&&(node->right!=nullptr))
	{
		//被删节点的后继节点。(称为取代节点)
		//用它来取代"被删节点"的位置，然后再将被删节点去掉
		RBTNode<T> *replace=node;
		//获取后继节点
		replace=replace->right;
		while(replace->left!=nullptr)
			replace=replace->left;
		//node节点不是根节点(只有根节点不存在父节点)
		if(rb_parent(node))
		{
			if(rb_parent(node)->left==node)
				rb_parent(node)->left=replace;
			else
				rb_parent(node)->right=replace;
		}
		else
			//node节点是根节点，更新根节点
			root=replace;
		//child是取代节点的右孩子，也是需要调整的节点
		//取代节点肯定不存在左孩子！因为它只有一个后继节点
		child=replace->right;
		parent=rb_parent(replace);
		color=rb_color(replace);
		//被删除节点是它的后继节点的父节点
		if(parent==node)
		{
			parent=replace;
		}
		else
		{
			//child不为空
			if(child)
				rb_set_parent(child,parent);
			parent->left=child;
			replace->right=node->right;
			rb_set_parent(node->right,replace);
		}
		replace->parent=node->parent;
		replace->color=node->color;
		replace->left=node->left;
		node->left->parent=replace;
		if(color==BLACK)
			removeFixUp(root,child,parent);
		delete node;
		return;
	}
	if(node->left!=nullptr)
		child=node->left;
	else
		child=node->right;
	parent-node->right;
	color=node->color;
	if(child)
		child->parent=parent;
	//node节点不是根节点
	if(parent)
	{
		if(parent->left==node)
			parent->left=child;
		else
			parent->right=child;
	}
	else
		root=child;
	if(color==BLACK)
		removeFixUp(root,child,parent);
	delete node;
}

/*
 * 删除红黑树中键值为key的节点
 *
 * 参数说明:
 *		tree红黑树的根节点
 * */

template<typename T>
void RBTree<T>::remove(T key)
{
	RBTNode<T> *node;
	//查找key对应的节点(node)，找到的话就删除该节点
	if((node=search(mRoot,key))!=nullptr)
		remove(mRoot,node);
}

/*
 * 销毁红黑树
 */

template<typename T>
void RBTree<T>::destroy(RBTNode<T>* &tree)
{
	if(tree==nullptr)
		return;
	if(tree->left!=nullptr)
		return destroy(tree->left);
	if(tree->right!=nullptr)
		return destroy(tree->right);
	delete tree;
	tree=nullptr;
}

template<typename T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

/*打印二叉查找树
 *
 * key		--节点的键值
 * direction--0,表示该节点是根节点
 *			  -1,表示该节点是它的父节点的左孩子
 *			  1表示该节点是它的父节点的右孩子
 */

template<typename T>
void RBTree<T>::print(RBTNode<T>* tree,T key,int direction)
{
	if(tree!=nullptr)
	{
		if(direction==0)		//tree是根节点
			cout<<setw(2)<<tree->key<<"(B) is root"<<endl;
		else
			cout<<setw(2)<<tree->key<<(rb_is_red(tree)?"(R)":"(B)")<<setw(2)<<key<<"'s"
				<<setw(12)<<(direction==1?"right child":"left child")<<endl;
		print(tree->left,tree->key,-1);
		print(tree->right,tree->key,1);
	}
}

template<typename T>
void RBTree<T>::print()
{
	if(mRoot!=nullptr)
		print(mRoot,mRoot->key,0);
}
#endif
