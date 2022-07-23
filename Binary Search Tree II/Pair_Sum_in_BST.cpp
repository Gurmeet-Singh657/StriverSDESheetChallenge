#include<bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTiterator
{
    stack<BinaryTreeNode<int>*> st;
    bool reverse;
    void push(BinaryTreeNode<int>* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            if(reverse==true)
                root=root->right;
            else
                root=root->left;
        }
    }
    public:
    BSTiterator(BinaryTreeNode<int>* root,bool isreverse)
    {
        reverse=isreverse;
        push(root);
    }
    bool hasnext()
    {
        return !st.empty();
    }
    int next()
    {
        BinaryTreeNode<int>* node=st.top();
        st.pop();
        if(reverse)
            push(node->left);
        else
            push(node->right);
        return node->data;
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(root==NULL) return false;
    BSTiterator l(root,false);
    BSTiterator r(root,true);
    int i=l.next();
    int j=r.next();
    while(i<j)
    {
        if(i+j==k)
            return true;
        else if(i+j<k)
            i=l.next();
        else
            j=r.next();
    }
    return false;
}