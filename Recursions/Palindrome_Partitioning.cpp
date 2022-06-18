#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string str,int start,int end)
{
    while(start<=end)
    {
        if(str[start]!=str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
void f(string s,vector<string>& currans,vector<vector<string>>& ans)
{
    if(s.length()==0)
    {
        ans.push_back(currans);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        if(ispalindrome(s,0,i))
        {
            currans.push_back(s.substr(0,i+1));
            f(s.substr(i+1),currans,ans);
            currans.pop_back();
            
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> currans;
    f(s,currans,ans);
    return ans;
}