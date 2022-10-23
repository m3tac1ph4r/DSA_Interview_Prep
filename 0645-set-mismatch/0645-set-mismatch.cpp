class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int totalSum=0;
        int distinctSum=0;
        int n=0;
        
        totalSum=nums[0];
        distinctSum=nums[0];
        n=nums.size();
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                distinctSum+=nums[i];
            }
            totalSum+=nums[i];
        }
        
        int duplicate=totalSum-distinctSum;
        
        int totalNaturalSum=(n*(n+1))/2;
        
        int missing=totalNaturalSum-distinctSum;
        
        return {duplicate,missing};
        
        
    }
};