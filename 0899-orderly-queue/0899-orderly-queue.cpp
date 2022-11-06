class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        else
        {
            string ans=s;
            int sz=s.size();
            s+=s;
            int newsz=s.size();
            // cba cba
            
            for(int i=1;i+sz<newsz;i++)
            {
                ans=min(ans,s.substr(i,sz));
            }
            return ans;
        }
    }
};