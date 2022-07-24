struct Node
{
    Node* links[26];
    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void set(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
};
class Trie
{
    public:
    Node* root;
    int count=0;
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
            {
                node->set(word[i],new Node());
                count++;
            }
            node=node->get(word[i]);
        }
    }
};
int distinctSubstring(string &word) {
    Trie trie;
    for(int i=0;i<word.length();i++)
    {
        string ans="";
        for(int j=i;j<word.length();j++)
        {
            ans+=word[j];
            trie.Insert(ans);
        }
    }
    return trie.count;
}
