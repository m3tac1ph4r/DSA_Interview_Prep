#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq; //min heap
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
}
    }
    int add(int val) {
        pq.push(val);
        if(pq.size()>size)
            pq.pop();
        return pq.top();
    }
};

int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

/*
We will be using min heap for finding kth largest element
*/