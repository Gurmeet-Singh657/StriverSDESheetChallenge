#include<bits/stdc++.h>
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int maxpathsum(TreeNode<int>* root,long long int &maxi)
{
    if(root==NULL)
        return 0;
    long long int leftsum=maxpathsum(root->left,maxi);
    long long int rightsum=maxpathsum(root->right,maxi);
    if(root->left!=NULL && root->right!=NULL)
    maxi=max(maxi,root->val+leftsum+rightsum);
    return root->val + max(leftsum,rightsum); 
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    long long int maxi=-1;
    maxpathsum(root,maxi);
    return maxi;
}