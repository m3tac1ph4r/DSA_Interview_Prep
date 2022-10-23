class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> distance(n,vector<int>(m,0));
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    visited[i][j]=true;
                    q.push({{i,j},0});
                }
            }
        }
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first.first;
            int col=it.first.second;
            int dist=it.second;
            
            distance[row][col]=dist;
            
            for(int i=0;i<4;i++)
            {
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                
                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m 
                   and visited[newRow][newCol]==false)
                {
                   visited[newRow][newCol]=true;
                    q.push({{newRow,newCol},dist+1});
                }
            }
        }
        return distance;
    }
};