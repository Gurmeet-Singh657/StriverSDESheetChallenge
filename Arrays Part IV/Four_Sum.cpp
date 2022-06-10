#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> v;
        if(nums.size()<4) return v;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int start=j+1;
                int end=nums.size()-1;
                while(start<end){
                    long long int sum=(long)nums[i]+(long)nums[j]+(long)nums[start]+(long)nums[end];
                    if(sum==target) 
                    {
                        v.push_back({nums[i], nums[j], nums[start], nums[end]});
                        while(start<end && nums[end]==nums[end-1]) end--;
                        while(start<end && nums[start]==nums[start+1]) start++;
                        start++;
                        end--;
                    }
                    else if(sum<target) start++;
                    else{
                        end--;
                    }
                }
            }
        }
        return v;
    }
};