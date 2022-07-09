#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:
    
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

void addLeftBoundary(TreeNode<int>* root,vector<int>& ans)
{
    TreeNode<int>* curr=root->left;
    
    while(curr!=NULL)
    {
        if(curr->left!=NULL || curr->right!=NULL)
        ans.push_back(curr->data);
        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}
void addLeaves(TreeNode<int>* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    addLeaves(root->left,ans);
    addLeaves(root->right,ans);
}
void addRightBoundary(TreeNode<int>* root,vector<int>& ans)
{
    TreeNode<int>* curr=root->right;
    vector<int> temp;
    while(curr!=NULL)
    {
        if(curr->left!=NULL || curr->right!=NULL)
        temp.push_back(curr->data);
        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }
    reverse(temp.begin(),temp.end());
    ans.insert(ans.end(),temp.begin(),temp.end());
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL) return ans;
    if(root->left!=NULL || root->right!=NULL) // if root is not leaf
        ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}