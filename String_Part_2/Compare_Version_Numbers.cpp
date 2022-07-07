#include<bits/stdc++.h>
using namespace std;
int compareVersions(string a, string b) 
{  
    int i=0,j=0;
    while(i<a.length() || j<b.length())
    {
        long long num1=0,num2=0;
        while(i<a.length() && a[i]!='.')
        {
            num1=num1*10 + (a[i]-'0');
            i++;
        }
        while(j<b.length() && b[j]!='.')
        {
            num2=num2*10 + (b[j]-'0');
            j++;
        }
        if(num1>num2)
            return 1;
        else if(num1<num2)
            return -1;
        i++;
        j++;
    }
    return 0;     
}