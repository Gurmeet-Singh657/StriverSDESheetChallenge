struct Node
{
    Node* links[26];
    int ew=0;
    int cp=0;
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void set(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void setEnd()
    {
        ew++;
    }
    int getEnd()
    {
       return ew; 
    }
    void eraseEnd()
    {
        ew--;
    }
    void setprefix()
    {
        cp++;
    }
    int getprefix()
    {
        return cp;
    }
    void eraseprefix()
    {
        cp--;
    }
};
class Trie{

    public:
    Node* root;
    Trie(){
       root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containskey(word[i]))
            {
                node->set(word[i],new Node());
            }
            node=node->get(word[i]);
            node->setprefix();
        }
        node->setEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containskey(word[i]))
                return 0;
            node=node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containskey(word[i]))
                return 0;
            node=node->get(word[i]);
        }
        return node->getprefix();
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            node=node->get(word[i]);
            node->eraseprefix();
        }
        node->eraseEnd();
    }
};
