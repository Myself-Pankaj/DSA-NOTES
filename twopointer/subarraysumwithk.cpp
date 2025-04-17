#include<bits/stdc++.h>
using namespace std;
class SubarraywithSumK{
    public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ctr = 0;
        int i = 0,j=0,sum=0;
        unordered_map<int,int>mpp;
        mpp[0] = 1; 
        for (int i = 0; i < n; i++)
        {
            /* code */
            sum+=nums[i];
            if(mpp.find(sum-goal)!=mpp.end()){
                ctr= ctr+mpp[sum-goal];
            }
            mpp[sum]++;
        }
        
        return ctr;
    }
};