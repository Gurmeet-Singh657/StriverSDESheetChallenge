// Naive solution
// Just insert elements one by one 
// TC-> O(n*n)
// SC-> O(1)

// Optimised solution -1
// sort the preorder elements
// since inorder is sorted in bst
// similar to BT , use inorder and preorder
// TC-> O(nlogn)+O(n)
// SC-> O(n)

#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
int findele(vector<int>& arr,int start,int end,int ele)
{
    for(int i=start;i<=end;i++)
    {
        if(arr[i]==ele)
            return i;
    }
    return -1;
}
TreeNode<int>* traversal(vector<int>& preOrder,vector<int>& Inorder,int start,int end,int& ind)
{
    if(start>end)
        return NULL;
    TreeNode<int>* node=new TreeNode<int>(preOrder[ind]);
    int mid=findele(Inorder,start,end,preOrder[ind]);
    ind++;
    node->left=traversal(preOrder,Inorder,start,mid-1,ind);
    node->right=traversal(preOrder,Inorder,mid+1,end,ind);
    return node;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    vector<int> Inorder=preOrder;
    sort(Inorder.begin(),Inorder.end());
    int ind=0;
    return traversal(preOrder,Inorder,0,preOrder.size()-1,ind);
}

// Optimised approach -2
// TC-> O(3N) = O(N)
// since node going coming back and then going and then coming back
// SC-> O(1)
// using upperbound
#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* traversal(vector<int>& preOrder,int &i,int upperbound)
{
    if(i==preOrder.size() || preOrder[i]>upperbound)
        return NULL;
    TreeNode<int>* root=new TreeNode<int>(preOrder[i]);
    i++;
    root->left=traversal(preOrder,i,root->data);
    root->right=traversal(preOrder,i,upperbound);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int ind=0;
    return traversal(preOrder,ind,INT_MAX);
}
