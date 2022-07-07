/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void InorderTraversal(TreeNode* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    InorderTraversal(root->left,ans);
    ans.push_back(root->data);
    InorderTraversal(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    InorderTraversal(root,ans);
    return ans;
}

// Iterative Inorder Traversal
#include<bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    TreeNode* node=root;
    stack<TreeNode*> st;
    while(node!=NULL || !st.empty())
    {
        while(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
        node=st.top();
        st.pop();
        ans.push_back(node->data);
        node=node->right;
     }
    return ans;
}