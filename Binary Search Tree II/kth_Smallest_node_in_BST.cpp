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

int kthSmallest(TreeNode<int> *curr, int k)
{
    vector<int> ans;
    TreeNode<int>* root=curr;
    while(root!=NULL)
    {
       if(root->left) // if left subtree exists
       {
           TreeNode<int>* temp=root->left;
           while(temp->right && temp->right!=root)
           {
               temp=temp->right;
           }
           if(temp->right==root)
           {
               ans.push_back(root->data);
               temp->right=NULL;
               root=root->right;
           }
           else
           {
               temp->right=root;
               root=root->left;
           }
       }
        else
        {
            ans.push_back(root->data);
            root=root->right;
        }
    }
    return ans[k-1];
}