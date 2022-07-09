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
int lca(TreeNode<int>* root,int x,int y)
{
    if(root==NULL)
        return -1;
    if(root->data==x || root->data==y)
        return root->data;
    int left=lca(root->left,x,y);
    int right=lca(root->right,x,y);
    
    if(left!=-1 && right!=-1)
        return root->data;
    else if(left!=-1)
        return left;
    return right;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return lca(root,x,y);
}