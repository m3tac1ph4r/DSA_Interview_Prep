class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        if(n==3)
            return "21";
        
        string s="21";
        for(int i=4;i<=n;i++)
        {
            string t="";
            s=s+"$";
            int c=1;
            for(int j=1;j<s.length();j++)
            {
                if(s[j]!=s[j-1])
                {
                    t+=to_string(c)+s[j-1];
                    c=1;
                }
                else
                    c++;
            }
            s=t;
        }
        return s;
    }
};