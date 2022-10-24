//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        map<string,int> mp;
        vector<alphanumeric> ans;
        for(string s:A)
        {
            mp[s]++;
        }
        
        for(auto it:mp)
        {
            alphanumeric obj;
            obj.name=it.first;
            obj.count=it.second;
            ans.push_back(obj);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends