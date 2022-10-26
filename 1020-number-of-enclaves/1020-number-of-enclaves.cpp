class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        visited[i][j]=true;
                    }
                }
            }
        }
        
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            vector<int> delRow={-1,0,1,0};
            vector<int> delCol={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                
                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m 
                   and grid[newRow][newCol]==1 and visited[newRow][newCol]==false)
                {
                    q.push({newRow,newCol});
                    visited[newRow][newCol]=true;
                }
            }
        }
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and visited[i][j]==false)
                {
                    // visited[i][j]=true;
                    count++;
                }
            }
        }
        return count;
    }
};