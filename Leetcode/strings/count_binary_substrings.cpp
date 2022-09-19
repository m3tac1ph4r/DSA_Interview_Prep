#include<bits/stdc++.h>
using namespace std;
#define ll long long
int countBinarySubstrings(string s)
{
    int curr=1,prev=0;
    int ans=0;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1])
            curr++;
        else
        {
            ans+=min(prev,curr);
            prev=curr;
            curr=1;
        }
    }
    ans+=min(curr,prev);    //for last
    return ans;
}
int main()
{
    string s = "00110011";
    cout<<countBinarySubstrings(s);
    return 0;
}

/*
https://leetcode.com/problems/count-binary-substrings/

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.

*/