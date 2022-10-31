//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        map<int,pair<int,int>> mp;
        vector<int> ans(4,INT_MAX);
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                int sum=A[i]+A[j];
                if(mp.find(sum)==mp.end())
                    mp[sum]={i,j};
                else
                {
                    pair<int,int> pp=mp[sum];
                    if(pp.first!=i and pp.second!=j and pp.first!=j and pp.second!=i)
                    {
                        vector<int> curr(4);
                        curr[0]=pp.first;
                        curr[1]=pp.second;
                        curr[2]=i;
                        curr[3]=j;
                        
                        int replace=false;
                        if(ans[0]==INT_MAX)
                            replace=true;
                        else
                        {
                            for(int k=0;k<4;k++)
                            {
                                if(ans[k]>curr[k])
                                {
                                    replace=true;
                                    break;
                                }
                                else if(ans[k]<curr[k])
                                    break;
                            }
                        }
                        if(replace)
                        {
                            for(int index=0;index<4;index++)
                                ans[index]=curr[index];
                        }
                    }
                }
            }
        }
        if(ans[0]==INT_MAX)
            return {-1,-1,-1,-1};
        else
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends