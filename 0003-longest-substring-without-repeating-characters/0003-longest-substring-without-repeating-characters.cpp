class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set<char> st;
    int l=0,max_len=0;
    for(int i=0;i<s.length();i++)
    {
        if(st.find(s[i])!=st.end())
        {
            while(l<i and st.find(s[i])!=st.end())
            {
                st.erase(s[l]);
                l++;
            }
        }
            st.insert(s[i]);
            max_len=max(max_len,i-l+1);
    }
    return max_len;   
    }
};