#include<bits/stdc++.h>
using namespace std;
#define ll long long
    
int main()
{
    vector<int> nums = {3, 0, 1};
    sort(nums.begin(), nums.end());
    int next = nums[0] + 1;
    if (nums.size() == 1 and nums[0] != 0)
    {
        return nums[0] - 1;
    }
    else if (nums.size() == 1 and nums[0] == 0)
        return nums[0] + 1;
    else if (nums[0] == 0)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == next)
                next++;
        }
    }
    else
        next = 0;
    return 0;
}

/*
https://leetcode.com/problems/missing-number/


Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, 
so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums.

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 
1 is the missing number in the range since it does not appear in nums.
*/