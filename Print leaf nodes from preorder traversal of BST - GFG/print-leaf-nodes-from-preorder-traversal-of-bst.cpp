//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        if(N==0)
            return {};
        else if(N==1)
            return {arr[0]};
        stack<int> st;
        vector<int> ans;
        st.push(arr[0]);
        
        for(int i=1;i<N;i++)
        {
            if(!st.empty() and st.top()>arr[i])
                st.push(arr[i]);
            else
            {
                int removedCount=0;
                int temp=st.top();
                while(!st.empty() and st.top()<arr[i])
                {
                    st.pop();
                    removedCount++;
                }
                
                st.push(arr[i]);
                if(removedCount>=2)
                    ans.push_back(temp);
            }
        }
        ans.push_back(st.top());
        st.pop();
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends