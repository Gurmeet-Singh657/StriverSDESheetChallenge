#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool flag=0;
    while(!q.empty())
    {
        int qsize=q.size();
        vector<int> temp;
        while(qsize>=1)
        {
            auto node=q.front();
            q.pop();
            temp.push_back(node->data);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            qsize--;
        }
        if(flag==1)
            reverse(temp.begin(),temp.end());
        ans.insert(ans.end(),temp.begin(),temp.end());
        flag=1-flag;
    }
    return ans;
}
