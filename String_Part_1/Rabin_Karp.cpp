#include<bits/stdc++.h>
using namespace std;
vector<int> stringMatch(string &str, string &pat) {
    int primeno=1000000;
    vector<int> ans;
    int store=0;
    int power = 1;
        for(int i = 0;i<pat.length();i++){
            power = (power*31)%primeno;
        }
    for(int i=0;i<pat.length();i++)
    {
        store=(store*31+pat[i])%primeno;
    }
    int currans=0;
    for(int i=0;i<str.length();i++)
    {
        currans=(currans*31+str[i])%primeno;
        if(i<pat.length()-1)
            continue;
        
        if(i>=pat.length())
        {
            currans=(currans-str[i-pat.length()]*power)%primeno;
        }
        if(currans<0)
            currans=currans+primeno;
        if(currans==store)
            ans.push_back(i-pat.length()+1);
    }
    return ans;
}
