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
void PostorderTraversal(TreeNode* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    PostorderTraversal(root->left,ans);
    PostorderTraversal(root->right,ans);
    ans.push_back(root->data);   
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    PostorderTraversal(root,ans);
    return ans;
}

// Iterative Postorder Traversal using 2 stacks
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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    while(!st1.empty())
    {
        TreeNode* curr=st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left)
            st1.push(curr->left);
        if(curr->right)
            st1.push(curr->right);
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
   return ans;
}

// using 1 stack
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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while(curr!=NULL || !st.empty())
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;  
        }
        else
        {
            TreeNode* temp=st.top()->right;
            if(temp==NULL)
            {
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && st.top()->right==temp)
                {
                    temp=st.top();
                    ans.push_back(temp->data);
                    st.pop();
                }
            }
            else
            {
                curr=temp;
            }
        }
    }
   return ans;
}

