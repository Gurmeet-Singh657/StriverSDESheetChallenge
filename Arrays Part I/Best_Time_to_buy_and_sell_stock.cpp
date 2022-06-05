#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int minele=INT_MAX;
    int maxprofit=0;
    for(int i=0;i<prices.size();i++)
    {
        minele=min(minele,prices[i]); // it is done first so as to get 0 as the profit instead of negative 
        // since if the stock can give loss then buy it and sell it at same point
        
        maxprofit=max(maxprofit,prices[i]-minele);
    }
    return maxprofit;
}