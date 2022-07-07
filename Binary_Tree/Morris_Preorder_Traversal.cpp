/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left) // if left subtree exists
            {
                TreeNode* temp=curr->left;
                while(temp->right!=NULL && temp->right!=curr)
                {
                    temp=temp->right;
                }
                if(temp->right==curr) // means already threaded -> remove thread and go to right
                {
                    temp->right=NULL;
                    curr=curr->right;
                }
                else // thread it , print it and go to left
                {
                    ans.push_back(curr->val);
                    temp->right=curr;
                    curr=curr->left;
                } 
            }
            else // if left subtree does not exists
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
    }
};