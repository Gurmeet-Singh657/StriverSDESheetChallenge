// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool mycmp(Item a,Item b)
    {
        return (double)a.value/a.weight>(double)b.value/b.weight;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,mycmp);
        double cap=0.0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<=W)
            {
                cap+=arr[i].value;
                W-=arr[i].weight;
            }
            else
            {
                cap+=(double)arr[i].value*W/arr[i].weight;
                return cap;
            }
        }
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
// codestudio code
#include<bits/stdc++.h>
bool comparator(pair<int,int>& item1,pair<int,int>& item2)
{
    return ((item1.second*1.0)/item1.first)>((item2.second*1.0)/item2.first);
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comparator);
    double val=0.0;
    for(int i=0;i<items.size();i++)
    {
        if(items[i].first<=w)
        {
            val+=(double)items[i].second;
            w-=items[i].first;
        }
        else
        {
            val+=items[i].second*(w*1.0/items[i].first);
            break;
        }
    }
    return val;
}