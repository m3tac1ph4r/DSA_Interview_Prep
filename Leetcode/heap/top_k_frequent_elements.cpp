#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<int> topKFrequent(vector<int>& nums, int k) 
{
    vector<int> ans;
    if(nums.size()==1)
    {
        ans.push_back(nums[0]);
     return ans;   
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    unordered_map<int,int> m;
    for(auto i:nums)
        m[i]++;
    for(auto i:m)
    {
        pq.push({i.second,i.first});
        if(pq.size()>k)
            pq.pop();
    }
    while(k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}    
int main()
{
    vector<int> nums={1,1,1,1,2,2,2,3,3,3,4};
    int k=2;
    vector<int> ans=topKFrequent(nums,k);   
    return 0;
}

/*
Using min heap
https://leetcode.com/problems/top-k-frequent-elements/
*/