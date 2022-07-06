#include<bits/stdc++.h>
using namespace std;
string writeAsYouSpeak(int n) 
{
	if(n==1)
        return "1";
    string ans="1";
    for(int i=2;i<=n;i++)
    {
        int count=1;
        string temp="";
        for(int j=0;j<ans.length()-1;j++)
        {
            if(ans[j]==ans[j+1])
                count++;
            else
            {
                temp+=to_string(count)+ans[j];
                count=1;
            }
        }
        temp+=to_string(count)+ans[ans.size()-1];
        ans=temp;
    }
    return ans;
}