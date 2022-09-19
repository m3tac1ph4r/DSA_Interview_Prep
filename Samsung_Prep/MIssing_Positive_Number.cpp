#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int abs(int x)
{
    if (x >= 0)
        return x;
    else
        return -1 * x;
}
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();

    // checking if all elements are negative
    bool allNegative = true;
    for (int i : nums)
    {
        if (nums[i] > 0)
        {
            allNegative = true;
            break;
        }
    }
    if (!allNegative)
        return 1;

    // moving all negative elements to left
    // 1 2 5 -1 -3
    // -3 -1 5 2 1
    int i = 0, j = n - 1;
    while (i < n and j >= 0)
    {
        if (nums[i] < 0)
            i++;
        else if (nums[j] >= 0)
            j--;
        else if (nums[i] >= 0 and nums[j] < 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }

    // find index of first positive element in array
    int firstPositive;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
        {
            firstPositive = i;
            break;
        }
    }

    // now if first Positive element is at index 2  and n=5 then maximum positive            element will be 5-2 => 3

    int maxPositive = n - firstPositive;

    // now changing the element to negative
    for (int i = firstPositive; i < n; i++)
    {
        if (abs(nums[i]) > maxPositive)
            continue;
        int index = firstPositive + abs(nums[i]) - 1;
        nums[index] = -1 * abs(nums[index]);
        if (nums[index] == 0)
            nums[index] = -1e7;
    }

    for (int i = firstPositive; i < n; i++)
    {
        if (nums[i] >= 0)
            return i - firstPositive + 1;
    }

    return maxPositive + 1;
}
int main()
{
    vector<int> arr = {1, 3, 0};
    int ans = firstMissingPositive(arr);
    cout << ans << endl;
    return 0;
}