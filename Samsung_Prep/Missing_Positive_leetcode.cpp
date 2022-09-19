#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= n || nums[i] <= 0)
                continue;
            else if (nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/first-missing-positive/
// https://youtu.be/aBhla9jSAeg

/*
You are given an unsorted array with both positive and negative elements. You have to find the smallest positive number missing from the array in O(n) time using constant extra space.
Input: First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.
Output: Single line output, print the smallest positive number missing.

Constraints:
1<=T<=100 and 1<=N<=100

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2
*/