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
// TC-> O(N)
// SC-> O(1)
bool BST(BinaryTreeNode<int>* root,int lb,int ub)
{
    if(root==NULL)
        return true;
    if(root->data>ub || root->data<lb)
        return false;
    bool findleft=BST(root->left,lb,root->data);
    bool findright=BST(root->right,root->data,ub);
    return findleft & findright;  
}
bool validateBST(BinaryTreeNode<int> *root) {
      return BST(root,INT_MIN,INT_MAX);
}