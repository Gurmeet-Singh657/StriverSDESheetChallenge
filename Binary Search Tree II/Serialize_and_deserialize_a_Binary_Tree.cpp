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

string serializeTree(TreeNode<int> *root)
{
    if(root==NULL) return "";
    
    string s="";
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* curr=q.front();
        q.pop();
        if(curr==NULL) s.append("#,");
        else s.append(to_string(curr->data)+',');
        if(curr!=NULL)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.size()==0) return NULL;
    stringstream s(serialized);
    string str;
    getline(s,str,',');
    TreeNode<int>* root=new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* curr=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#")
        {
            curr->left=NULL;
        }
        else
        {
            curr->left=new TreeNode<int>(stoi(str));
            q.push(curr->left);
        }
        getline(s,str,',');
        if(str=="#")
        {
            curr->right=NULL;
        }
        else
        {
            curr->right=new TreeNode<int>(stoi(str));
            q.push(curr->right);
        }
    }
    return root;
}



