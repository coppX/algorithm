
/*
 * 红黑树 C++
 * 
 * @author	coppX
 * @date	2016/11/08
*/
#include <iostream>
#include "../RBTree.cpp"

using namespace std;

int main()
{
	int a[]={10,40,30,60,90,70,20,50,80};
	int check_insert=0;
	int check_remove=0;
	int i;
	int ilen=(sizeof(a))/(sizeof(a[0]));
	RBTree<int>* tree=new RBTree<int>();
	cout<<"==原始数据:";
	for(i=0;i<ilen;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(i=0;i<ilen;i++)
	{
		tree->insert(a[i]);
		if(check_insert)
		{
			cout<<"==添加节点:"<<a[i]<<endl;
			cout<<"==树的详细信息:"<<endl;
			tree->print();
			cout<<endl;
		}
	}
	cout<<"==前序遍历:";
	tree->preOrder();

	cout<<"\n==中序遍历:";
	tree->inOrder();

	cout<<"\n==后序遍历:";
	tree->postOrder();
	cout<<endl;

	cout<<"==最小值:"<<tree->minimum()<<endl;
	cout<<"==最大值:"<<tree->maximum()<<endl;
	cout<<"==树的详细信息:"<<endl;
	tree->print();

	//设置check_remove=1,测试删除函数
	if(check_remove)
	{
		for(i=0;i<ilen;i++)
		{
			tree->remove(a[i]);
			cout<<"==删除节点:"<<a[i]<<endl;
			cout<<"==树的详细信息:"<<endl;
			tree->print();
			cout<<endl;
		}
	}
	//销毁红黑树
	tree->destroy();
	return 0;
}
