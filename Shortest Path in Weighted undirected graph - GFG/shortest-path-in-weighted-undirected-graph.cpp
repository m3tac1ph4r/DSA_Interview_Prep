//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> distance(n+1,INT_MAX);
        vector<int> parent(n+1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        distance[1]=0;
        unordered_map<int,list<pair<int,int>>> adj;
        
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        for(int i=1;i<=n;i++)
            parent[i]=i;
            
        pq.push({0,1});
        while(!pq.empty())
        {
            auto frontNode=pq.top();
            pq.pop();
            int u=frontNode.second;
            int wt=frontNode.first;
            
            for(auto it:adj[u])
            {
                int v=it.first;
                int weight=it.second;
                if(weight+wt<distance[v])
                {
                    distance[v]=weight+wt;
                    pq.push({distance[v],v});
                    parent[v]=u;
                }
            }
        }
        
        if(distance[n]==INT_MAX)
            return {-1};
        
        int node=n;
        while(parent[node]!=node)
        {
            ans.push_back(node);
            node=parent[node];
        }
        
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends