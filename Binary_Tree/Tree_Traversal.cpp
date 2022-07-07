#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans(3);
    if(root==NULL)
        return ans;
    stack<pair<BinaryTreeNode<int>*,int>> st;
    st.push({root,1});
    while(!st.empty())
    {
        if(st.top().second==1)
        {
            ans[1].push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left)
                st.push({st.top().first->left,1});
        }
        else if(st.top().second==2)
        {
            ans[0].push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->right)
                st.push({st.top().first->right,1});
        }
        else
        {
            ans[2].push_back(st.top().first->data);
            st.pop();
        }
    }
    return ans;
}