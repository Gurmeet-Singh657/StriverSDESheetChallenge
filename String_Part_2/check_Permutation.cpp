#include<bits/stdc++.h>
using namespace std;
bool areAnagram(string &str1, string &str2){
    int freq1[26]={0};
    int freq2[26]={0};
    for(int i=0;i<str1.length();i++)
        freq1[str1[i]-'a']++;
    for(int i=0;i<str2.length();i++)
        freq2[str2[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(freq1[i]!=freq2[i])
            return false;
    }
    return true;
}