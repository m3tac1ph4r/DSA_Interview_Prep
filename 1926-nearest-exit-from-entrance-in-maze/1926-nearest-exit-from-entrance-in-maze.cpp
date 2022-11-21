class Solution {
public:
    int solve(vector<vector<char>> &maze,vector<int> &entrance)
    {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<int> delRow={-1,0,1,0};
        vector<int> delCol={0,1,0,-1};
        // if(entrance[0]==0||entrance[0]==n-1||entrance[1]==0||entrance[1]==m-1)
        //     return 0;
        q.push({{entrance[0],entrance[1]},0});
        vector<vector<char>> visited(n,vector<char>(m,false));
        visited[entrance[0]][entrance[1]]=true;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                pair<int,int> temp=q.front().first;
                int i=temp.first;
                int j=temp.second;
                int count=q.front().second;
                q.pop();
                if((i!=entrance[0] || j!=entrance[1]) and (i==0||i==n-1||j==0||j==m-1))
                    return count;

                for(int k=0;k<4;k++)
                {
                    int newRow=i+delRow[k];
                    int newCol=j+delCol[k];

                    if(newRow>=0 and newRow<n and newCol>=0 and newCol<m 
                       and maze[newRow][newCol]=='.' and visited[newRow][newCol]==false)
                    {
                        q.push({{newRow,newCol},count+1});
                        visited[newRow][newCol]=true;
                    }
                }
            }
        }
        return -1;
        
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return solve(maze,entrance);
    }
};