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
int findinorder(vector<int>& inorder,int val,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==val)
            return i;
    }
    return -1;
}
TreeNode<int>* BinaryTree(vector<int>& inorder,vector<int>& preorder,int start,int end,int& index)
{
    if(start>end)
        return NULL;
    
    int val=preorder[index];
    index++;
    int pos=findinorder(inorder,val,start,end);
    TreeNode<int>* root=new TreeNode<int>(val);
    root->left=BinaryTree(inorder,preorder,start,pos-1,index);
    root->right=BinaryTree(inorder,preorder,pos+1,end,index);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int index=0;
    return BinaryTree(inorder,preorder,0,inorder.size()-1,index);
}