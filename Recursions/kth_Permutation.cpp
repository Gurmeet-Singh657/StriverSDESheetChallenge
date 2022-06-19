#include<bits/stdc++.h>
using namespace std;
string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int> answer;
    int fact=1;
    for(int i=1;i<n;i++)
    {
        fact=fact*i;
        answer.push_back(i);
    }
    answer.push_back(n);
    k=k-1; // for 0 base indexing
    string res="";
    while(true)
    {
        res+=to_string(answer[k/fact]);
        answer.erase(answer.begin()+k/fact);
        if(answer.size()==0)
            break;
        k=k%fact;
        fact=fact/answer.size();
    }
    return res;
}
