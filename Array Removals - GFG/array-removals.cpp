//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int start=0,end=0,minLen=0;
        while(end<n)
        {
            if(arr[end]-arr[start]<=k)
            {
                minLen=max(minLen,end-start+1);
                end++;
            }
            else
                start++;
        }
        return arr.size()-minLen;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends