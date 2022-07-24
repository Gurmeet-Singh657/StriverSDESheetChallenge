struct Node
{
    Node* links[2];
    bool containskey(int val)
    {
        return links[val]!=NULL;
    }
    Node* get(int val)
    {
        return links[val];
    }
    void put(int val,Node* node)
    {
        links[val]=node;
    }
};
class Trie
{
    public:
    Node* root;
    Trie()
    {
        root=new Node();
    }
    void Insert(int ele)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int currbit=(ele>>i) & 1;
            if(!node->containskey(currbit))
            {
                node->put(currbit,new Node());
            }
            node=node->get(currbit);
        }
    }
    int search(int ele)
    {
        Node* node=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int currbit=(ele>>i) & 1;
            if(!node->containskey(1-currbit))
            {
                node=node->get(currbit);
            }
            else
            {
                node=node->get(1-currbit);
                ans=ans | (1<<i);
            }
        }
        return ans;
    }
};
int maximumXor(vector<int> A)
{
    Trie trie;
    int maxi=0;
      for(int i=0;i<A.size();i++)
      {
          trie.Insert(A[i]);
          maxi=max(maxi,trie.search(A[i]));
      }
    return maxi;
}