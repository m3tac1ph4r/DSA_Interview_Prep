#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int maxArea(vector<int> &height)
{
    int ans=0;
    int left=0,right=height.size()-1;
    while(left<=right)
    {
        ans=max(ans,(min(height[left],height[right])*(right-left)));
        if(height[left]<height[right])
            left++;
        else
            right--;
    }
    return ans;
}    
int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    return 0;
}

/*
https://leetcode.com/problems/container-with-most-water/

This is a two pointer approach
*/