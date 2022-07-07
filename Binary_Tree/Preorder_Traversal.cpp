/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void PreorderTraversal(TreeNode* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    ans.push_back(root->data);
    PreorderTraversal(root->left,ans);  
    PreorderTraversal(root->right,ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    PreorderTraversal(root,ans);
    return ans;
}

// Iterative Preorder Traversal
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while(curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            ans.push_back(curr->data);
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        curr=curr->right;
    }
    return ans;
}


// Striver soln
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* curr=st.top();
        ans.push_back(curr->data);
        st.pop();
        if(curr->right!=NULL)
        {
            st.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            st.push(curr->left);
        }
    }
    return ans;
}
