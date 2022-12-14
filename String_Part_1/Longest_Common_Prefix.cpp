#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        string curr=arr[i];
        for(int j=0;j<ans.length();j++)
        {
            if(ans[j]!=curr[j])
            {
                ans=ans.substr(0,j);
                break;
            }
        }
    }
    return ans;
}


