#include<bits/stdc++.h>
using namespace std;
// My solution - but not optimised
int findsingles(char ch)
{
    if(ch=='I')
        return 1;
    else if(ch=='V')
        return 5;
    else if(ch=='X')
        return 10;
    else if(ch=='L')
        return 50;
    else if(ch=='C')
        return 100;
    else if(ch=='D')
        return 500;
    else if(ch=='M')
        return 1000;
}
int romanToInt(string str) {
    int i=0;
    int ans=0;
    while(i<str.length())
    {
        if(str.length()-i>=2)
        {
            string temp=str.substr(i,2);
            if(temp=="IV")
                ans+=4;
            else if(temp=="IX")
                ans+=9;
            else if(temp=="XL")
                ans+=40;
            else if(temp=="XC")
                ans+=90;
            else if(temp=="CD")
                ans+=400;
            else if(temp=="CM")
                ans+=900;
            else
            {
                ans+=findsingles(str[i]);
                i-=1;
            }
            i+=2;
        }
        else
        {
            ans+=findsingles(str[i]);
            i+=1;
        }
    }
    return ans;
}

// Good solution
int findsingles(char ch)
{
    if(ch=='I')
        return 1;
    else if(ch=='V')
        return 5;
    else if(ch=='X')
        return 10;
    else if(ch=='L')
        return 50;
    else if(ch=='C')
        return 100;
    else if(ch=='D')
        return 500;
    else if(ch=='M')
        return 1000;
}
int romanToInt(string str) {
   int ans=0;
    int i=0;
    while(i<str.length())
    {
        int first=findsingles(str[i]);
        if(i<str.length()-1 && first<findsingles(str[i+1]))
         {
            ans+=(findsingles(str[i+1])-first);
            i++;
         }
        else
            ans+=first;
        i++;
    }
    return ans;
}

