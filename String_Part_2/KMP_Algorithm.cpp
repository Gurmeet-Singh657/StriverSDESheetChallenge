#include<bits/stdc++.h>
using namespace std;
bool checkpattern(string p,string s,int temp[])
{
    int j=0;
    int i=0;
    while(i<s.length())
    {
        if(s[i]==p[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j=temp[j-1];
            else
                i=i+1;
        }
        if(j==p.length()) return true;
    }
    return false;
}
bool findPattern(string p, string s)
{
    int n=p.length();
    int m=s.length();
    int temp[m];
    int j=0;
    temp[0]=0;
    int i=1;
    while(i<p.length())
    {
        if(p[i]==p[j])
        {
            temp[i]=j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
                j=temp[j-1];
            else
            {
                temp[i]=0;
                i++;
            }
        }
    }
    return checkpattern(p,s,temp);
}