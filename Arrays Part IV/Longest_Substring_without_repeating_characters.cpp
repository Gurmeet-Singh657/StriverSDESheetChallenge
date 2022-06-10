#include <bits/stdc++.h> 
using namespace std;
int uniqueSubstrings(string input)
{
    //Write your code here
    map<char,int> mp;
    int maxlen=0;
    int left=0;
    for(int right=0;right<input.length();right++)
    {
        if(mp.find(input[right])!=mp.end())
        {
            if(left<=mp[input[right]])
            {
                left=mp[input[right]]+1;
            }
        }
        mp[input[right]]=right;
        maxlen=max(maxlen,right-left+1);
    }
    return maxlen;
}