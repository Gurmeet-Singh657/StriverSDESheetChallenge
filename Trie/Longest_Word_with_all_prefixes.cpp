struct Node
{
    Node* links[26];
    bool flag=false;
    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    void setEnd()
    {
        flag=true;
    }
    bool getEnd()
    {
        return flag;
    }
};
class Trie
{
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    void Insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containskey(word[i]))
                node->put(word[i],new Node());
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkprefix(string word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            node=node->get(word[i]);
            if(!node->getEnd())
                return false;
        }
        return true;
    }
    
};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(int i=0;i<n;i++)
    {
        trie.Insert(a[i]);
    }
    string longest="";
    for(int i=0;i<n;i++)
    {
        string curr=a[i];
        if(trie.checkprefix(curr))
        {
            if(longest.length()<curr.length())
                longest=curr;
            else if(longest.length()==curr.length())
            {
                if(longest>curr)
                    longest=curr;
            }
        }
    }
    return longest==""?"None":longest;
    
}