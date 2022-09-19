#include<bits/stdc++.h>
using namespace std;
#define ll long long
    
int main()
{
    vector<int> nums = {3, 4, -1, 1};
    int ans=1;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0;i<n;i++)
    {

        if(nums[i]==ans)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}

/*

https://leetcode.com/problems/first-missing-positive/

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Input: nums = [3,4,-1,1]
Output: 2

Input: nums = [7,8,9,11,12]
Output: 1

Input: nums = [1,2,0]
Output: 3

*/