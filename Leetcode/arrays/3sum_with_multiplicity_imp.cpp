#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int threeSumWithMulti(vector<int> height,int target)
{
    unordered_map<int, long> hash_map;
    int mod = 1e9 + 7;
    long res=0;
    for(int i:A)
        hash_map[i]++;
    for(auto it1:hash_map)
    {
        for(auto it2:hash_map)
        {
            int i=it1.first,j=it2.first,k=target-i-j;
            if(!hash_map.count(k))
                continue;
            if(i==j and j==k)
                res+=hash_map[i]*(hash_map[i]-1)*(hash_map[i]-2)/6;
                // res += hash_map[i] * (hash_map[i] - 1) * (hash_map[i] - 2) / 6;
            else if(i==j and j!=k)
                res += (hash_map[i] * (hash_map[i] - 1) * hash_map[k])/2;
            else if(i<j and j<k)
                res+=hash_map[i]*hash_map[j]*hash_map[k];
        }
    }
    return res % mod;
}
int main()
{
    int n,target;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>target;
    cout<<threeSumWithMulti(arr,target);
    return 0;
}

/*
https://leetcode.com/problems/3sum-with-multiplicity/

Two Pointer Approach using Hashing
*/

/*
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

*/
