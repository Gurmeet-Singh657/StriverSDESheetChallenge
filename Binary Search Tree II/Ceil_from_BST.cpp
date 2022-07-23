/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
// TC-> O(log2n)
// SC-> O(1)
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans=-1;
    while(node!=NULL)
    {
        if(node->data==x)
            return node->data;
        else if(node->data>x)
        {
            ans=node->data;
            node=node->left;
        }
        else
            node=node->right;
    }
    return ans;
}