//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<string> wordStack;
        stack<int> numStack;
        
        string currStr="",prevStr="",currNum="";
        int prevNum;
        
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            
            if(isdigit(ch))
                currNum+=ch;
            
            else if(ch=='[')
            {
                numStack.push(stoi(currNum));
                wordStack.push(currStr);
                currNum="";
                currStr="";
            }
            else if(ch==']')
            {
                prevNum=numStack.top();
                prevStr=wordStack.top();
                numStack.pop();
                wordStack.pop();
                
                string temp="";
                while(prevNum!=0)
                {
                    temp+=currStr;
                    prevNum--;
                }
                currStr=prevStr+temp;
            }
            else
                currStr+=ch;
        }
        return currStr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends