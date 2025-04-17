#include<bits/stdc++.h>
using namespace std;


class Intervals{
    private:
    
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Sort by end time in ascending order
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
    
        int count = 1;
        int limit = intervals[0][1];
    
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= limit) {
                count++;
                limit = intervals[i][1];
            }
        }
    
        return n - count;
    }
    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals,vector<int>newInterval){
        int n = intervals.size();
        vector<vector<int>>res;
        int i = 0;
        while(i<n && intervals[i][1]<newInterval[0]){

            res.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};