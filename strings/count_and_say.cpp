#include<bits/stdc++.h>
using namespace std;
#define ll long long
    
int main()
{
    int n=4;
    if(n==1)
        cout<<"1"<<endl;
    else if(n==2)
        cout<<"11"<<endl;
    string s="11";
    for(int i=3;i<=n;i++)
    {
        s=s+'$';
        string t="";
        int c=1;
        int len=s.length();
        for(int j=1;j<len;j++)
        {
            if(s[j]!=s[j-1])
            {
                t = t + to_string(c) + s[j - 1];
                c=1;
            }
            else
                c++;
        }
        s=t;
    }
    cout<<s<<endl;
    return 0;
}

/*
https://leetcode.com/problems/count-and-say/

*/