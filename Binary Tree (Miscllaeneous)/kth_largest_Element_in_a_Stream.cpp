#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int count;
    Kthlargest(int k, vector<int> &arr) {
       count=k;
        for(int i=0;i<arr.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push(arr[i]);
            }
            else
            {
                if(arr[i]>pq.top())
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
    }

    void add(int num) {
            if(pq.size()<count)
            {
                pq.push(num);
            }
            else
            {
                if(num>pq.top())
                {
                    pq.pop();
                    pq.push(num);
                }
            }
    }

    int getKthLargest() {
       return pq.size()==count?pq.top():-1;
    }

};