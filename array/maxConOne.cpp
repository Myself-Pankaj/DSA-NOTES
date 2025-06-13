#include<bits/stdc++.h>
using namespace std;

class maxConOne{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxOne = 0;//2
        int ctr= 0;
        for(int i = 0 ; i<n;i++){
            if(nums[i] ==1){
                ctr++;
            }else{
                ctr = 0;
            }
            maxOne = max(maxOne,ctr);
        }
        return maxOne;
        
    }
};