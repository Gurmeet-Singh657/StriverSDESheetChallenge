#include<bits/stdc++.h>
using namespace std;
const int base=31;
const int primeno=29;
// Submission on Coding Ninjas
#include<bits/stdc++.h>
const int BASE = 1000000;
vector<int> stringMatch(string& source, string& target) {
    vector<int> ans;
     if(source == "" or target == "") return ans;
        int m = target.size();
        int power = 1;
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0;
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == target)
                    ans.push_back(i-m+1);
            }
        }
        return ans;
}

