template<typename T>
struct TreeNode{
    T data;
    TreeNode<T> *lchild;
    TreeNode<T> *rchild;
 };
 
 template<typename T>
 class BinaryTree{
 public:
    BinaryTree()=default;
    BinaryTree(int _count,TreeNode<T> *node)
        :count=_count,root=node
    {}
    ~Binary(){}
    bool insert(T elem);
    TreeNode<T>& insert(TreeNode<T> *node);
    bool deleteNode(T elem);
    
    void preVist(TreeNode<T> *node);
    void inVist(TreeNode<T> *node);
    void backVist(TreeNode<T> *node);
    
    bool isEmpty(TreeNode<T> *node)
    int size(TreeNode<T> *node)
 private:
    int count;
    TreeNode<T> *root;
};
