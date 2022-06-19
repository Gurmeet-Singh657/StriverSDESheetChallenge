// Naive solution
#include<bits/stdc++.h>
using namespace std;
void Permutations(string s,vector<string>& ans,map<int,bool> &mp,string curr)
{
    if(curr.size()==s.size())
    {
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<s.length();i++)
    {
        if(mp[s[i]-'0']==false)
        {
            mp[s[i]-'0']=true;
            Permutations(s,ans,mp,curr+to_string(s[i]-'0'));
            mp[s[i]-'0']=false;
        }
    }
}
vector<string> permute(string s)
{
    vector<string> ans;
    map<int,bool> mp;
    Permutations(s,ans,mp,"");
    return ans;
}
// Optimised Approach
void Permutations(string& s,int ind,vector<string>& ans)
{
    if(ind==s.length()-1)
    {
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<s.length();i++)
    {
        swap(s[i],s[ind]);
        Permutations(s,ind+1,ans);
        swap(s[i],s[ind]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    Permutations(s,0,ans);
    return ans;
}