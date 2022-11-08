class Solution {
public:
    string makeGood(string s) {
        string ans;
        if(s=="")
            return "";
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            st.push(s[i]);
            while(!st.empty() and (st.top()+32==s[i+1] || st.top()==s[i+1]+32))
            {
                st.pop();
                i++;
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};