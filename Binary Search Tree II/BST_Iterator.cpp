#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
    public:
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        push(root);
    }

    int next()
    {
        TreeNode<int>* mynext=st.top();
        st.pop();
        push(mynext->right);
        return mynext->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
    void push(TreeNode<int>* curr)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/