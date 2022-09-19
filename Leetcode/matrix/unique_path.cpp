#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int i, int j, int m, int n)
{
    if (i == n - 1 and j == m - 1)
        return 1;
    else if (i >= n or j >= m)
        return 0;
    else
        return solve(i + 1, j,m,n) + solve(i, j + 1,m,n);
}
int main()
{
    int m = 3, n = 7;
    cout << solve(0, 0, m, n);
    return 0;
}

/*
https://leetcode.com/problems/unique-paths/

Bruteforce Approach

*/