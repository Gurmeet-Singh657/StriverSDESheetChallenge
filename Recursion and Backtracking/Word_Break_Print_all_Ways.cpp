#include<bits/stdc++.h>
using namespace std;
void BreakWord(string s,vector<string>& finalans,set<string> st,string ans,int maxsize)
{
    if(s.length()==0)
    {
        finalans.push_back(ans);
        return;
    }
    for(int i=0;i<s.length();i++)
    {
        if(i+1<=maxsize && st.find(s.substr(0,i+1))!=st.end())
        {
            BreakWord(s.substr(i+1),finalans,st,ans+s.substr(0,i+1)+" ",maxsize);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    set<string> st;
    int maxsize=0;
    for(int i=0;i<dictionary.size();i++)
    {
        st.insert(dictionary[i]);
        int len=dictionary[i].length();
        maxsize=max(maxsize,len);
    }
    vector<string> ans;
    BreakWord(s,ans,st,"",maxsize);
    return ans;
}