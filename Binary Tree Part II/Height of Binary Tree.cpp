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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
    }
};

// Coding Ninjas Submission
// TLE Code
#include<bits/stdc++.h>
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        data=d;
        left=right=NULL;
    }
};
Node* constructTree(vector<int>& inorder,unordered_map<int,int> mp,int start,int end)
{
    if(start>end)
        return NULL;
    
    int minindex=start;
    for(int i=start;i<=end;i++)
    {
        if(mp[inorder[i]]<mp[inorder[minindex]])
            minindex=i;
    }
    Node* node=new Node(inorder[minindex]);
    node->left=constructTree(inorder,mp,start,minindex-1);
    node->right=constructTree(inorder,mp,minindex+1,end);
    return node;
}
int heightofBinaryTree(Node* root)
{
    if(root==NULL) return -1;
    int lh=heightofBinaryTree(root->left);
    int rh=heightofBinaryTree(root->right);
    return max(lh,rh)+1;
}
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    unordered_map<int,int> mp;
    for(int i=0;i<levelOrder.size();i++)
    {
        mp[levelOrder[i]]=i;
    }
    Node* root=constructTree(inorder,mp,0,N-1);
    return heightofBinaryTree(root);
}

// Successful Submission
#include<bits/stdc++.h>
int heightOfTheTree(vector<int>& inorder, vector<int>& levelorder, int N){
    if(N==1)
        return 0;
	unordered_map<int,int> mp;
    // Let us store the inorder indices of array
    for(int i=0;i<inorder.size();i++)
    {
        mp[inorder[i]]=i;
    }
    // using queue -> for storing inorder ranges like level order traversal 
    // so that given level order array lies everytime we traverse b/w given inorder range
    
    
     queue<vector<int>> q;
     if(mp[levelorder[0]]==N-1) // means for root element only left subtree exists
        q.push({0,N-2,1});
    else if(mp[levelorder[0]]==0) // means for root element only right subtree exists
        q.push({1,N-1,1});
    else // when both right and left exist
    {
        q.push({0,mp[levelorder[0]]-1,1});
        q.push({mp[levelorder[0]]+1,N-1,1});
    }
    
    int k=1;
    int maxans=0;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int currele=levelorder[k];
        maxans=max(maxans,it[2]);
        if(it[0]==it[1]) // means it is leaf node
            maxans=max(maxans,it[2]+1);
        else if(mp[currele]==it[1]) //no right subtree
            q.push({it[0],it[1]-1,it[2]+1});
        else if(mp[currele]==it[0]) // no left subtree
            q.push({it[0]+1,it[1],it[2]+1});
        else // both exist
        {
            q.push({it[0],mp[currele]-1,it[2]+1});
            q.push({mp[currele]+1,it[1],it[2]+1});
        }   
        k++;
    }
      return maxans-1;
}