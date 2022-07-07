// Leetcode Submission

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int>>> mp;
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        TreeNode* node=it.first;
        int line=it.second.first;
        int level=it.second.second;
        mp[line][level].insert(node->val);
        if(node->left)
            q.push({node->left,{line-1,level+1}});
        if(node->right)
            q.push({node->right,{line+1,level+1}});
    }
    vector<vector<int>> ans;
    for(auto it:mp)
    {
        vector<int> col;
        for(auto it1:it.second)
        {
            col.insert(col.end(),it1.second.begin(),it1.second.end());
        }
        ans.push_back(col);
    }
    return ans;
    }
};

// Coding Ninjas Submission
#include<bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if(root==NULL)
        return {};
    vector<int> ans;
    queue<pair<TreeNode<int>*,int>> q;
    map<int,vector<int>> mp;
    
    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        mp[it.second].push_back(it.first->data);
        if(it.first->left)
            q.push({it.first->left,it.second-1});
        if(it.first->right)
            q.push({it.first->right,it.second+1});
    }
    for(auto it:mp)
    {
        for(int i=0;i<it.second.size();i++)
            ans.push_back(it.second[i]);
    }
    return ans;
}