#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkInMap; // key= id , values={starting_station,starting_time}
    unordered_map<string,pair<int,int>> path; // key= startingstation-endingstation, values={timetaken,count}
    UndergroundSystem() 
    {}
    
    void checkIn(int id, string stationName, int t)
    {
        checkInMap[id]={stationName,t};   
    }

    void checkOut(int id, string stationName, int t) 
    {
        auto checkIn=checkInMap[id];
        checkInMap.erase(id);

        string path_name= checkIn.first + "_" + stationName;
        path[path_name].first += t-checkIn.second;
        path[path_name].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string path_name=startStation + "_" + endStation;
        auto& route=path[path_name];
        return (double)((double)route.first/(double)route.second);
    }
};   
int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/design-underground-system/
*/