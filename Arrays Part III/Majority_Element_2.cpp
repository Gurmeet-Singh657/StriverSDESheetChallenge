#include <bits/stdc++.h> 
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    // for n/3 we can have only 2 elements as majority
    int num1=-1;
    int num2=-1;
    int count1=0;
    int count2=0;
    for(int i=0;i<arr.size();i++)
    {
        if(num1==arr[i]) // if num1 already exists
        {
            count1++;
        }
        else if(num2==arr[i]) // if num2 already exists
        {
            count2++;
        }
        else if(count1==0) // if num1 is not yet assigned
        {
            num1=arr[i];
            count1=1;
        }
        else if(count2==0) // if num2 is not assigned
        {
            num2=arr[i];
            count2=1;
        }
        else // if this element does not exist
        {
            count1--;
            count2--;
        }
    }
    // Verify
    count1=0,count2=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==num1)
            count1++;
        if(arr[i]==num2)
            count2++;
    }
    vector<int> ans;
    if(count1>arr.size()/3)
        ans.push_back(num1);
    if(count2>arr.size()/3)
        ans.push_back(num2);
    return ans;
}