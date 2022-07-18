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
bool helper(TreeNode<int>* root,TreeNode<int>* leaf,stack<TreeNode<int>*>& st)
{
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==leaf->data)
        {
            st.push(root);
            return true;
        }
        else
            return false;
    }  
    st.push(root);
    if(root->left)
    {
        if(helper(root->left,leaf,st))
            return true;
    }
    if(root->right)
    {
        if(helper(root->right,leaf,st))
            return true;
    }
    st.pop();
    return false;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(root==NULL)
        return NULL;
    stack<TreeNode<int>*> st;
    helper(root,leaf,st);
    TreeNode<int>* parent=st.top();
    TreeNode<int>* newroot=parent;
    st.pop();
    while(!st.empty())
    {
        TreeNode<int>* curr=st.top();
        st.pop();
        if(curr->left==parent) 
        {
            curr->left=NULL;
            parent->left=curr;
        }
        else // curr->right==parent
        {
            curr->right=curr->left; // make curr's left as right
            curr->left=NULL; // made null so that next point it should point its parent
            parent->left=curr;
        }
        parent=curr;
    }
    return newroot;
}
