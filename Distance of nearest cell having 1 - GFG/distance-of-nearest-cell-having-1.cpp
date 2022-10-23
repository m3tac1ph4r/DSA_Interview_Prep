//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    queue<pair<pair<int,int>,int>> q;
	    
	    vector<vector<bool>> visited(n,vector<bool>(m,false));
	    vector<vector<int>> distance(n,vector<int>(m,0));
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                visited[i][j]=true;
	            }
	        }
	    }
	    
	    int delRow[]={-1,0,+1,0};
	    int delCol[]={0,+1,0,-1};
	    while(!q.empty())
	    {
	        auto it=q.front();
	        q.pop();
	        
	        int row=it.first.first;
	        int col=it.first.second;
	        int dist=it.second;
	        
	        distance[row][col]=dist;
	        visited[row][col]=true;
	        
	        for(int i=0;i<4;i++)
	        {
	            int newRow=row+delRow[i];
	            int newCol=col+delCol[i];
	            
	            if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and visited[newRow][newCol]==false)
	            {
	                visited[newRow][newCol]=true;
	                q.push({{newRow,newCol},dist+1});
	            }
	        }
	    }
	    
	    return distance;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends