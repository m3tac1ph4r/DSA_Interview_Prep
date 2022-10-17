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
​