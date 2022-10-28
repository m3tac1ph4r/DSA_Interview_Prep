//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  private:
    void dfs(int i,int j,int n,int m,vector<vector<bool>> &visited,vector<pair<int,int>> &vec,
    vector<vector<int>> &grid,int basei,int basej)
    {
        visited[i][j]=true;
        vec.push_back({i-basei,j-basej});
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        
        for(int k=0;k<4;k++)
        {
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            
            if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and visited[newRow][newCol]==false
            and grid[newRow][newCol]==1)
                dfs(newRow,newCol,n,m,visited,vec,grid,basei,basej);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // https://youtu.be/7zmgQSJghpo?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> st;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false and grid[i][j]==1)
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,n,m,visited,vec,grid,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends