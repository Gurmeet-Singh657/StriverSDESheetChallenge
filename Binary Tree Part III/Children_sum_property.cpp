/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL || (!root->left && !root->right))
        return;
    int check=0;
    if(root->left)
        check+=root->left->data;
    if(root->right)
        check+=root->right->data;
    if(check>=root->data)
        root->data=check;
    else 
    {
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int total=0;
    if(root->left)
        total+=root->left->data;
    if(root->right)
        total+=root->right->data;
    if(total!=0)
        root->data=total;
}  

// Need is only if check is coming smaller than the given node
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL || (!root->left && !root->right))
        return;
    int check=0;
    if(root->left)
        check+=root->left->data;
    if(root->right)
        check+=root->right->data;
    if(check<root->data)
    {
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int total=0;
    if(root->left)
        total+=root->left->data;
    if(root->right)
        total+=root->right->data;
    if(total!=0)
        root->data=total;
}  