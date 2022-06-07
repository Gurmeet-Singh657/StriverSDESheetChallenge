#include <bits/stdc++.h> 
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int currxor=0;
    for(int i=0;i<arr.size();i++)
        currxor=currxor^arr[i];
    for(int i=1;i<=n;i++)
        currxor=currxor^i;
    int checker=currxor & ~(currxor-1);
    int xor1=0;
    int xor2=0;
    for(int i=0;i<arr.size();i++)
    {
        if(checker & arr[i])
            xor1=xor1^arr[i];
        else
            xor2=xor2^arr[i];
    }
    for(int i=1;i<=n;i++)
    {
         if(checker & i)
            xor1=xor1^i;
        else
            xor2=xor2^i;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==xor1)
            return {xor2,xor1};
        if(arr[i]==xor2)
            return {xor1,xor2};
    }       
}
