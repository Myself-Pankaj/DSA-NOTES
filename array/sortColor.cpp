#include<bits/stdc++.h>
using namespace std;

class sortColor{
    public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = n-1 , ptr = 0;
        while(ptr<=j){
            if(nums[ptr]==0){
                swap(nums[i],nums[ptr]);
                i++;
                ptr++;
            }else if(nums[ptr] ==1){
                ptr++;
            }else{
                swap(nums[ptr],nums[j]);
                j--;
            }
        }
        
    }
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int>ans;
        for(int i = arr.size()-1;i>=0;i--){
            if(ans.empty() || ans.back()<=arr[i]){
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};