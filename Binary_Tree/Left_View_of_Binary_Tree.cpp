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

void LeftView(TreeNode<int>* root,vector<int>& ans,int level)
{
    if(root==NULL)
        return;
    
    if(ans.size()==level)
        ans.push_back(root->data);
    LeftView(root->left,ans,level+1);
    LeftView(root->right,ans,level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    LeftView(root,ans,0);
    return ans;
}