#include<bits/stdc++.h>
using namespace std;
class longestConsecutive{
    public:
    int longestConsecutivebruteforce(vector<int>& nums) {
        // //100  4
        unordered_map<int,int>mpp;
        int long_seq = 0;
        int n = nums.size();
        if(n ==0 || n ==1) return n;
        for(int i = 0 ;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        for(int i = 0 ; i<nums.size();i++){
            int curr_num = nums[i];
            
            int curr_seq = 0;
            while(mpp.find(curr_num+1)!=mpp.end()){
                curr_seq++;
                curr_num++;
            }
            long_seq = max(curr_seq,long_seq);
        }
        return long_seq+1;
        
    }
    int longestConsecutiveOptimal(vector<int>& nums) {

        int long_seq = 0;
        int n = nums.size();
        if(n ==0 || n ==1) return n;
       
        sort(nums.begin(),nums.end());
        
        int curr_seq = 1;
        for(int i =1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i] == nums[i-1]+1){ 
                    curr_seq++;
                }else {
                    curr_seq = 1;
                }
            }
            long_seq = max(curr_seq,long_seq);
        }
        return long_seq;
    }

};