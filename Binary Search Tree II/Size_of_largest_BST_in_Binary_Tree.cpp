/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class Nodepar
{
    public:
    int maxNode,minNode,maxsize;
    Nodepar(int maxi,int mini,int size)
    {
        maxNode=maxi;
        minNode=mini;
        maxsize=size;
    }
};
Nodepar bstsize(TreeNode<int>* root)
{
    if(root==NULL)
        return Nodepar(INT_MIN,INT_MAX,0);
    Nodepar left=bstsize(root->left);
    Nodepar right=bstsize(root->right);
    if(left.maxNode<root->data && root->data<right.minNode)
    {
        return Nodepar(max(root->data,right.maxNode),min(left.minNode,root->data),left.maxsize+right.maxsize+1);
    }
    return Nodepar(INT_MAX,INT_MIN,max(left.maxsize,right.maxsize));
}
int largestBST(TreeNode<int>* root) 
{
    return bstsize(root).maxsize;
}
