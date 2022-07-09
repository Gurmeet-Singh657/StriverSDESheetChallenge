/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int heightfinder(BinaryTreeNode<int>* root)
{
    if(root==NULL) return 0;
    int lh=heightfinder(root->left);
    int rh=heightfinder(root->right);
    if(lh==-1 || rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    bool ans=heightfinder(root)==-1?false:true;
    return ans;
}