#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        string curr=arr[i];
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]!=curr[i])
            {
                ans=ans.substr(0,i);
                break;
            }
        }
    }
    return ans;
}


