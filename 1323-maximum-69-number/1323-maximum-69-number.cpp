class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int ans=num;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(s[i]=='6')
                s[i]='9';
            else
                s[i]='6';
            
            int temp=stoi(s);
            ans=max(ans,temp);
            s[i]=ch;
        }
        return ans;
    }
};