#include<bits/stdc++.h>
using namespace std;
int atoi(string str) {
   int ans=0;
    int i=0;
    bool minus=false;
    if(str[i]=='-')
    {
        minus=true;
        i++;
    }
    while(i<str.length())
    {
        int digit=str[i]-'0';
        if(digit>=0 && digit<=9)
            ans=ans*10 + digit;
        i++;
    }
    if(minus==true)
        ans=-1*ans;
    return ans;
}