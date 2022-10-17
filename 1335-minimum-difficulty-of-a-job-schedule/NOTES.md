https://youtu.be/mBZEFR3LSNs

### BruteForce Approach (Using DFS) :

![bruteforce_DFS](https://drive.google.com/file/d/14gxPRrreqZCG2K-ZCESn478n79_jwcZi/view?usp=sharing)
1. We will find minimum by taking all the jobs one by one. As in the above image we will take 6 in first day. And in all other task on other day. So excluding 6 we have 5 max on other day.
2. Same when we take 6,5 in first day and others on second day. So 4 will be maximum
3. Like this we will do for every task. And in last all task will be on first day excluding 1. Means 6.5,4,3,2 will be on first day. And 1 on second day. So 6 will be maximum from 1st day and from second 1 will be maximum. So answer will be 6+1=7

```cpp
class Solution {
public:
    int solve(int i,vector<int> &difficulty,int d)
    {
        if(d==1)
        {
            int ans=INT_MIN;
            // int ans=*max_element(begin(difficulty)+i,end(difficulty);
            for(int j=i;j<difficulty.size();j++)
                ans=max(ans,difficulty[j]);
            return ans;
        }
        int ans=INT_MAX;
        int currD=INT_MIN;
        
        for(int j=i;j<=difficulty.size()-d;j++)
        {
            currD=max(currD,difficulty[j]);
            ans=min(ans,currD+solve(j+1,difficulty,d-1));
        }
        return ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d)
            return -1;
        else if(d==0)
            return -1;
        
        return solve(0,jobDifficulty,d);
    }
};
```

### Optimize Approach (Using memoization):
1. We will simply memoize the above solution by creating a 2D array of size 300 and 10. Because 300 is maximum difficulty length and for number of days 10 is maximum.

```C++
class Solution {
public:
    int dp[301][11];
    
    int solve(int i,vector<int> &difficulty,int d)
    {
        if(d==1)
        {
            int ans=INT_MIN;
            // int ans=*max_element(begin(difficulty)+i,end(difficulty);
            for(int j=i;j<difficulty.size();j++)
                ans=max(ans,difficulty[j]);
            return ans;
        }
        else if(dp[i][d]!=-1)
            return dp[i][d];
        int ans=INT_MAX;
        int currD=INT_MIN;
        
        for(int j=i;j<=difficulty.size()-d;j++)
        {
            currD=max(currD,difficulty[j]);
            ans=min(ans,currD+solve(j+1,difficulty,d-1));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d)
            return -1;
        else if(d==0)
            return -1;
        for(int i=0;i<301;i++)
            for(int j=0;j<11;j++)
                dp[i][j]=-1;
        return solve(0,jobDifficulty,d);
    }
};
```
