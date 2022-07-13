#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure.

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

// Approach 1
void Preorder(TreeNode<int>* root,TreeNode<int>* &prev)
{
    if(root==NULL)
        return;
    
    Preorder(root->right,prev);
    Preorder(root->left,prev);
    
    root->right=prev;
    root->left=NULL;
    prev=root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
   TreeNode<int>* prev=NULL;
   Preorder(root,prev);
   return root;
}

// Approach 2
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(root==NULL) return NULL;
    stack<TreeNode<int>*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode<int>* curr=st.top();
        st.pop();
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
        if(!st.empty())
        curr->right=st.top();
        curr->left=NULL;
    }
    return root;
}
// Approach 3 - Using Morris Traversal
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int>* curr=root;
    while(curr!=NULL)
    {
        if(curr->left)
        {
             TreeNode<int>* prev=curr->left;
             while(prev->right)
                 prev=prev->right;
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }       
        curr=curr->right;
    }
    return root;
}