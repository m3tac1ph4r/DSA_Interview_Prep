class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        return (a.second>b.second);
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n=plantTime.size();
        
        vector<pair<int,int>> vec;
        
        for(int i=0;i<n;i++)
        {
            vec.push_back({plantTime[i],growTime[i]});
        }
        
        sort(vec.begin(),vec.end(),comp); // sort acc to growTime
        int ans=0,sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=vec[i].first;
            ans=max(ans,sum+vec[i].second);
        }
        
        return ans;
    }
};

/*
1 2
4 3
3 1

4 3
1 2
3 1
*/