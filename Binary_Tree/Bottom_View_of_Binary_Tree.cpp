/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    map<int,int> mp;
    while(!q.empty())
    {
          auto curr=q.front();
          q.pop();
          BinaryTreeNode<int>* node=curr.first;
          int line=curr.second;
          mp[line]=node->data;
          if(node->left)
          {
              q.push({node->left,line-1});
          }
          if(curr.first->right)
          {
              q.push({node->right,line+1});
          } 
    }
    
    for(auto it:mp)
        ans.push_back(it.second);
    return ans;
}
