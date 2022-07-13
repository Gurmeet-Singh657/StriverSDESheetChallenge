/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool Symmetric(BinaryTreeNode<int>* leftroot,BinaryTreeNode<int>* rightroot)
{
//     if(leftroot==NULL && rightroot==NULL)
//         return true;
    
//     if(leftroot==NULL || rightroot==NULL)
//         return false;
    
    if(leftroot==NULL || rightroot==NULL)
        return leftroot==rightroot;
    
    if(leftroot->data!=rightroot->data)
        return false;
    
    bool ans1=Symmetric(leftroot->left,rightroot->right);
    bool ans2=Symmetric(leftroot->right,rightroot->left);
    return ans1 && ans2;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return true;
   return Symmetric(root->left,root->right);  
}