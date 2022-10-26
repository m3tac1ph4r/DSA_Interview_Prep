class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int n=nums.size();
        mp[0]=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            if(mp.find(sum%k)!=mp.end())
            {
                if(mp[sum%k]<i)
                    return true;
            }
            else
                mp[sum%k]=i+1;
        }
        return false;
    }
};