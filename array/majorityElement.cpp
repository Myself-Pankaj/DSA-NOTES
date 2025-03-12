#include<bits/stdc++.h>
using namespace std;

class MajorityElement{
    public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i = 0 ; i<n;i++){
            mpp[nums[i]]++;
        }
        int count = n/3;
        for(auto it: mpp){
            if(it.second>count){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};