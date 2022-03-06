#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

long long minimalKSum(vector<int> &nums, int k)
{
    long long sum=0;
    int c=1;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    {
        while(k>0 and nums[i]>c)
        {
            cout<<c<<" ";
            sum+=c;
            k--;
            c++;
        }
        if(i>0 and nums[i]==nums[i-1])
            continue;
        c++;
    }
    while(k>0)
    {
        sum+=c;
        c++;
        k--;
    }
    return sum;
}
int main()
{
    int n,k=35;
    // cin>>n>>k;
    vector<int> nums = {96, 44, 99, 25, 61, 84, 88, 18, 19, 33, 60, 86, 52, 19, 32, 47, 35, 50, 94, 17, 29, 98, 22, 21, 72, 100, 40, 84};
    cout<< minimalKSum(nums, k);
    return 0;
}

/*
 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 20, 23, 24, 26, 27, 28, 30, 31, 34, 36, 37, 38, 39, 41, 42, 43, 45, 46, 48}
 */