class Solution {
public:
    int longestPalindrome(vector<string>& words) {
            // https://youtu.be/HmEqS_aYt40
        map<string,int> mp;
        for(string word:words)
            mp[word]++;
        
        int len=0,ans=0;
        bool flag=false;
        for(auto i:mp)
        {
            if(i.first[0]==i.first[1]) // means aa,bb,cc like this
            {
                if(i.second%2==1) // means count of string is odd
                {
                    len+=i.second-1;
                    flag=true;
                }
                else
                    len+=i.second;
                mp.erase(i.first);
            }
            else
            {
                string str=i.first;
                reverse(str.begin(),str.end());
                ans+=min(i.second,mp[str])*4;
                mp.erase(str);
                mp.erase(i.first);
            }
        }
        
        if(flag)
        {
            return (ans+len*2+2); // if any aa,bb,cc like string is having count odd
        }
        else
            return ans+len*2;
    }
};