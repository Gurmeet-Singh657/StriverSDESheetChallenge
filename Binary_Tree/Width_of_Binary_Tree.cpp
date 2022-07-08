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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int qsize=q.size();
            int first,last;
            int min=q.front().second;
            for(int i=0;i<qsize;i++)
            {
                auto it=q.front();
                q.pop();
                if(i==0)
                    first=it.second;
                if(i==qsize-1)
                    last=it.second;
                it.second-=min; // to consider all elements as staring from 0
                if(it.first->left)
                    q.push({it.first->left,(long long)2*it.second+1});
                if(it.first->right)
                    q.push({it.first->right,(long long)2*it.second+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};

// Coding Ninjas Submission
#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return 0;
    queue<TreeNode<int>*> q;
    int maxwidth=-1;
    q.push(root);
    while(!q.empty())
    {
        int qsize=q.size();
        maxwidth=max(maxwidth,qsize);
        while(qsize>0)
        {
            TreeNode<int>* node=q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            qsize--;
        }
    }
    return maxwidth;
}