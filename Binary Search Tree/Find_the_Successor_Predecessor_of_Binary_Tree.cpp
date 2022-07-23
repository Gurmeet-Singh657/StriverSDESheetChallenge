/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

int getpre(BinaryTreeNode<int>* root,int key)
{
    BinaryTreeNode<int>* pre=NULL;
    while(root!=NULL)
    {
        if(key==root->data)
            root=root->left;
        else if(root->data<key)
        {
            pre=root;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return pre==NULL?-1:pre->data;
}
int getsucc(BinaryTreeNode<int>* root,int key)
{
    BinaryTreeNode<int>* succ=NULL;
    while(root!=NULL)
    {
        if(key>=root->data)
        {
            root=root->right;
        }
        else
        {
            succ=root;
            root=root->left;
        }
    }
    return succ==NULL?-1:succ->data;
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int predecessor=getpre(root,key);
    int successor=getsucc(root,key);
    
    return {predecessor,successor};
}
