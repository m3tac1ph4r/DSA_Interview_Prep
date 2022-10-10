//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>> &graph,int n,int m)
    {
        graph[i][j]=2;
        if(i+1<n and j<m and graph[i+1][j]==1)
            dfs(i+1,j,graph,n,m);
        if(i-1>=0 and j<m and graph[i-1][j]==1)
            dfs(i-1,j,graph,n,m);
        if(i<n and j+1<m and graph[i][j+1]==1)
            dfs(i,j+1,graph,n,m);
        if(i<n and j-1>=0 and graph[i][j-1]==1)
            dfs(i,j-1,graph,n,m);
    }
    int findIsland(int n,int m,vector<vector<int>> &graph)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(graph[i][j]==1)
                {
                    ans++;
                    dfs(i,j,graph,n,m);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(graph[i][j]==2)
                    graph[i][j]=1;
            }
        }
        return ans;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> graph(n,vector<int>(m,0));
        
        vector<int> ans;
        for(int i=0;i<operators.size();i++)
        {
            graph[operators[i][0]][operators[i][1]]=1;
            int num=findIsland(n,m,graph);
            ans.push_back(num);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends