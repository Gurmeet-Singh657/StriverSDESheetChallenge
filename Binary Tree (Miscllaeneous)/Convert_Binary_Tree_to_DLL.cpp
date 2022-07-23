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
void CreateLL(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &head,BinaryTreeNode<int>*& prev)
{
    if(root==NULL)
        return;
    CreateLL(root->left,head,prev);
    if(head==NULL)
    {
        head=root;
        prev=root;
    }
    else
    {
        prev->right=root;
        root->left=prev;
        prev=prev->right;
    }
    CreateLL(root->right,head,prev);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if(root==NULL)
        return NULL;
    BinaryTreeNode<int>* head=NULL;
    BinaryTreeNode<int>* prev=NULL;
    CreateLL(root,head,prev);
    return head;
}