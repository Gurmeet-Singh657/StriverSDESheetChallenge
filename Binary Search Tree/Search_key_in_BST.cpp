/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/
// Recursive solution
// TC-> O(log2N)
// SC-> O(log2N)

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    else if(root->data>x)
        return searchInBST(root->left,x);
    return searchInBST(root->right,x);
}
// Iterative solution
// TC-> O(log2N)
// SC-> O(1)
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root!=NULL && root->data!=x)
    {
        root=(x<root->data?root->left:root->right);
    }
    return root;
}