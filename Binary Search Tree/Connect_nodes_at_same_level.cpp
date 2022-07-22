#include<bits/stdc++.h>
using namespace std;
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        int qsize=q.size();
        while(qsize>1)
        {
            auto node=q.front();
            q.pop();
            node->next=q.front();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            qsize--;
        }
        q.pop();
        q.push(NULL);
    }
}