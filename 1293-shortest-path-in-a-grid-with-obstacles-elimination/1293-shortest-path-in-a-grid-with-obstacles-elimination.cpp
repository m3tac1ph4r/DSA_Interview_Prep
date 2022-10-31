class Solution {
public:
    vector<int> delRow={-1,0,1,0};
    vector<int> delCol={0,1,0,-1};
    int solve(int n,int m,int k,vector<vector<int>>& grid)
    {
        vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        queue<vector<int>> q;
        q.push({0,0,k});
        visited[0][0][k]=true;
        int res=0;
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int row=q.front()[0];
                int col=q.front()[1];
                int kk=q.front()[2];
                
                q.pop();
                
                if(row==n-1 and col==m-1)
                    return res;
                
                for(int i=0;i<4;i++)
                {
                    int newRow=row+delRow[i];
                    int newCol=col+delCol[i];
                    
                    if(newRow>=0 and newRow<n and newCol>=0 and newCol<m)
                    {
                        if(grid[newRow][newCol]==1 and kk>0 
                           and visited[newRow][newCol][kk-1]==false)
                        {
                            q.push({newRow,newCol,kk-1});
                            visited[newRow][newCol][kk-1]=true;
                        }
                        if(grid[newRow][newCol]==0 
                                and visited[newRow][newCol][kk]==false)
                        {
                            q.push({newRow,newCol,kk});
                            visited[newRow][newCol][kk]=true;
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        return solve(n,m,k,grid);
        
    }
};