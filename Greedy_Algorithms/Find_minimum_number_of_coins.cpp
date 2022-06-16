#include<bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount) 
{
    // Write your code here
    int denominations[]={1,2,5,10,20,50,100,500,1000};
    int val=0;
    for(int i=8;i>=0;i--)
    {
        if(amount>=denominations[i])
        {
            val+=(amount/denominations[i]);
            amount=amount%denominations[i];
        }
    }
    return val;
}
