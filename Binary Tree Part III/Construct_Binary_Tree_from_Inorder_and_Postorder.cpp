/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
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
TreeNode<int>* BinaryTree(vector<int>& inorder,vector<int>& postorder,int start,int end,int& index)
{
    if(start>end)
        return NULL;
    
    int val=postorder[index];
    index--;
    int pos=findinorder(inorder,val,start,end);
    TreeNode<int>* root=new TreeNode<int>(val);
    root->right=BinaryTree(inorder,postorder,pos+1,end,index);
    root->left=BinaryTree(inorder,postorder,start,pos-1,index);
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	int index=postorder.size()-1;
    return BinaryTree(inorder,postorder,0,inorder.size()-1,index);
}
