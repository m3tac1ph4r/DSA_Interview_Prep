#include<bits/stdc++.h>
using namespace std;
#define ll long long
    
int main()
{
    vector<int> ratings={1,0,2};
    int n=ratings.size();
    vector<int> candy(n,1);
    int total=0;
    if(n==1)
        total=1;
    //left to right
    for(int i=1;i<n;i++)
    {
        if(ratings[i]>ratings[i-1] and candy[i]<=candy[i-1])
            candy[i]=candy[i-1]+1;
    }
    //right to left
    for(int i=n-2;i>=0;i--)
    {
        if(ratings[i]>ratings[i+1] and candy[i]<=candy[i+1])
            candy[i]=candy[i+1]+1;
    }
    for(int i=0;i<n;i++)
        total+=candy[i];
    cout<<total;
    return 0;
}

/*
https://leetcode.com/problems/candy/

Here I also traversed the array from right to left also because 
when we check left to right then rating[i-1] is dependent on rating[i] 
it means rating[i-1] will determine how many candy will rating[i] will have. 
So if we check rating[1] > rating[0] then we wil add rating[1]=rating[0]+1
And then if rating[1]>rating[2] then we have to add 1 to rating[1] and rating[0]
That's why I traverse the array from right to left also
*/