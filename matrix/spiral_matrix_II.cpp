#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n,vector<int>(n));
    int r1=0,r2=n-1,c1=0,c2=n-1;
    int val=1;
    while(r1<=r2 and c1<=c2)
    {
        // left to right
        for(int c=c1;c<=c2;c++)
            ans[r1][c]=val++;
        
        //top to bottom
        for(int r=r1+1;r<=r2;r++)
            ans[r][c2]=val++;
        
        //right to left
        for(int c=c2-1;c>=c1;c--)
            ans[r2][c]=val++;
        
        //bottom to top
        for(int r=r2-1;r>r1;r--)
            ans[r][c1]=val++;
        
        //updating values
        r1++;
        r2--;
        c1++;
        c2--;
    }
    return ans;
}    
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> ans=generateMatrix(int n);
    for(auto i:ans)
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    return 0;
}

/*
https://leetcode.com/problems/spiral-matrix-ii/
*/