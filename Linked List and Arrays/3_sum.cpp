#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-2;i++)
    {
        if(i!=0 && arr[i]==arr[i-1]) continue;
        int start=i+1,end=arr.size()-1;
        while(start<end)
        {
            int sum=arr[start]+arr[end]+arr[i];
            if(sum==K)
            {
                ans.push_back({arr[i],arr[start],arr[end]});
                while(start<end && arr[start]==arr[start+1]) start++;
                while(start<end && arr[end]==arr[end-1]) end--;
                start++;
                end--;
            }     
            else if(sum>K)
                end--;
            else
                start++;
        }
    }
    return ans;
}