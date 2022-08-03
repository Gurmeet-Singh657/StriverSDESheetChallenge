#include<bits/stdc++.h>
using namespace std;
string longestPalinSubstring(string str)
{
    string longest=str.substr(0,1);
    int maxlen=1;
    int minindex=0;
    for(int i=0;i<str.length();i++)
    {
        // Checking odd lengths
        int start=i,end=i;
        while(start>=0 && end<str.length())
        {
            if(str[start]!=str[end])
              break;
            if(end-start+1>maxlen)
            {
                longest=str.substr(start,end-start+1);
                maxlen=end-start+1;
                minindex=start;
            }
            else if(end-start+1==maxlen && minindex>start)
            {
                longest=str.substr(start,end-start+1);
                minindex=start;
            }
            start--;
            end++;
        }
        // Checking for Even lengths
         start=i,end=i+1;
        while(start>=0 && end<str.length())
        {
            if(str[start]!=str[end])
              break;
            if(end-start+1>maxlen)
            {
                longest=str.substr(start,end-start+1);
                maxlen=end-start+1;
                minindex=start;
            }
            else if(end-start+1==maxlen && minindex>start)
            {
                longest=str.substr(start,end-start+1);
                minindex=start;
            }
            start--;
            end++;
        }
    }
    return longest;
}