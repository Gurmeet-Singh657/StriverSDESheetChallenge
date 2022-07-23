/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int KthLargestNumber(TreeNode<int>* curr, int k) 
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
    if(ans.size()<k)
        return -1;
    return ans[ans.size()-k];
}
