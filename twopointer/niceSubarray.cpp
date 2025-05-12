#include <bits/stdc++.h>
using namespace std;

class NiceSubarray{
    int helper(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount = 0;int ctr = 0;
        int i = 0,j=0;
        while(j<n){
            if(k<0) return 0;
            if((nums[j] & 1) == 1)oddCount++;

            while(oddCount>k){
                if((nums[i] & 1 )== 1) oddCount--;
                i++;
            }
            if(oddCount <=k){
               ctr+=j-i+1;
            }
            j++;
        }
        return ctr;
    }
    public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};