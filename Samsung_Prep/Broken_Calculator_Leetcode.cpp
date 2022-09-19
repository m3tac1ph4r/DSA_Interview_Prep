#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        if (startValue >= target)
            return startValue - target;
        else if (target % 2 == 0)
            return 1 + brokenCalc(startValue, target / 2);
        else
            return 1 + brokenCalc(startValue, target + 1);
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/broken-calculator/