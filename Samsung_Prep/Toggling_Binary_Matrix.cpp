#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int findMax(vector<vector<int>> &mat, int n, int m, int k)
{
    unordered_map<string, int> mp;

    // storing the frq of every row in map
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = 0; j < m; j++)
            temp = temp + to_string(mat[i][j]);
        mp[temp]++;
    }

    int ans = INT_MIN;
    for (auto it : mp)
    {
        int num_zeros = 0;
        string s = it.first;
        int frq = it.second;

        // count number of zeroes
        for (char ch : s)
        {
            if (ch == '0')
                num_zeros++;
        }

        if (num_zeros <= k and (k - num_zeros) % 2 == 0)
            ans = max(ans, frq);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> nums[i][j];
    }
    int k;
    cin >> k;
    cout << findMax(nums, n, m, k);
    return 0;
}

// https://youtu.be/Kc43BLd3JJM?list=PLVjKfYZRuZ-KXsO2dprGDi-g9lF0m3yhm

/*
A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum number of rows having all 1’s.

for eg, n=3, m=3,

1 0 0

1 0 1

1 0 0
if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so answer is 2 as there are 2 rows with all 1’s.

if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there is 1 row with all 1’s.
Constraints :

N ≤ 20 and M ≤ 10^5
*/