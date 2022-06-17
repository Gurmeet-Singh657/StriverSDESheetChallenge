#include <bits/stdc++.h> 
using namespace std;
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++)
    {
        if(i!=0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<arr.size();j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1]) continue;
            int start=j+1,end=arr.size()-1;
            while(start<end)
            {
                int sum=arr[i]+arr[j]+arr[start]+arr[end];
                if(sum>target)
                    end--;
                else if(sum<target)
                    start++;
                else
                    return "Yes";
            }
        }
    }
    return "No";
}
