#include<bits/stdc++.h>
using namespace std;
const int base=31;
const int primeno=29;
// Submission on Coding Ninjas
vector<int> stringMatch(string &str, string &pat) {
    vector<int> ans;
    int n=str.length();
    int m=pat.length();
    int hash=1;
    for(int i=0;i<m-1;i++)
    {
       hash=(hash*base)%primeno;
    }
    int checker=0;
    int curr=0;
    for(int i=0;i<m;i++)
    {
        checker=(checker*base + pat[i])%primeno;
        curr=(curr*base + str[i])%primeno;
    }
    for(int i=0;i<=n-m;i++)
       {
           if(curr==checker)
           {     
               int j=0;
               for(j=0;j<m;j++)
               {
                   if(str[i+j]!=pat[j])
                       break;
               }
               if(j==m)
                 ans.push_back(i);
           }
           
           if(i<n-m)
           {
               curr=curr-hash*str[i];
               curr=(base*curr+str[i+m])%primeno;
               if(curr<0)
                   curr=curr+primeno;
                   
           }
       }
    return ans;
}

// Actual Way of doing Rabin Karp
#include<bits/stdc++.h>
vector<int> stringMatch(string &str, string &pat) {
    int primeno=1e9+7;
    vector<int> ans;
    int store=0;
    for(int i=0;i<pat.length();i++)
    {
        int currno=(pat[i]-'A'+1)%primeno;
        store=(store*31+currno)%primeno;
    }
    int currans=0;
    for(int i=0;i<str.length();i++)
    {
        if(i>pat.length()-1)
        {
            int prevcode=((str[i-pat.length()]-'A'+1)*(int)(pow(31,pat.length()-1)))%primeno;
            currans-=prevcode;
        }
        int currno=(str[i]-'A'+1)%primeno;
        currans=(currans*31+currno)%primeno;
        if(i>=pat.length()-1)
        {
            if(currans==store)
                ans.push_back(i-pat.length()+1);
        }
    }
    return ans;
}
