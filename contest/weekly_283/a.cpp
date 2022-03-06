#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
vector<string> cellsInRange(string s)
{
    vector<string> ans;
    string col=s.substr(0,2);
    string row=s.substr(3,4);
    char start=col[1];
    while(col[0]<=row[0])
    {
        ans.push_back(col);
        while(col[1]<row[1])
        {
            col[1]=col[1]+1;
            ans.push_back(col);
        }
        col[0]=col[0]+1;
        col[1]=start;
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}    
int main()
{
    string s;
    cin>>s;
    vector<string> ans=cellsInRange(s);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}