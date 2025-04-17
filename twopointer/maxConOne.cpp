#include<bits/stdc++.h>
using namespace std;

class MaxConsecutiveOne{
    public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,j = 0;
        int zeroctr = 0;int max_one = 0;
        while (j<n)
        {
            /* code */
            if(nums[j] ==0) zeroctr++;
            while(zeroctr>k){
                if(nums[i] == 0){
                    zeroctr--;
                }
                i++;
            }
            int len = j-i+1;
            max_one = max(max_one,len);
            j++;
        }
       return max_one; 
    }
};