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
TreeNode<int>* BSTconvert(vector<int>& arr,int start,int end)
{
    if(start>end)
        return NULL;
    int mid=(start+end)/2;
    TreeNode<int>* node=new TreeNode<int>(arr[mid]);
    node->left=BSTconvert(arr,start,mid-1);
    node->right=BSTconvert(arr,mid+1,end);
    return node;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return BSTconvert(arr,0,n-1);
}