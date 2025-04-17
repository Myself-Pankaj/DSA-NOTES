#include<bits/stdc++.h>
using namespace std;

class longestSubarrayWithkdiffele{
    private:
    int helper(vector<int>& nums, int k){
        int n = nums.size();
    
        int i = 0 ,j = 0 ,ctr = 0;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            if(mpp.size()<=k){
                ctr+=j-i+1;
            }
            j++;
        }
        return ctr;
    }
    public:
// It is to find the length of longest sub array with k or 2 distinct element 
    int totalElements1(vector<int> &arr) {
        int n = arr.size();
        int i = 0 ,j= 0;
        int max_len = 0;
        unordered_map<int,int>mpp;
        while (j<n)
        {
            /* code */
            mpp[arr[j]]++;
            while(mpp.size()>2){
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0){
                    mpp.erase(arr[i]);
                }
                i++;
            }
            int len = j-i+1;
            max_len = max(max_len,len);
            j++;
        }
        return max_len;
    }
    int totalElements2(vector<int> &arr) {
        int n = arr.size();
        int i = 0 ,j= 0;
        int max_len = 0;
        unordered_map<int,int>mpp;
        while (j<n)
        {
            /* code */
            mpp[arr[j]]++;
            if(mpp.size()>2){
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0){
                    mpp.erase(arr[i]);
                }
                i++;
            }
            int len = j-i+1;
            if(mpp.size()>=2){
                max_len = max(max_len,len);
            }
            j++;
        }
        return max_len;
    }
    // To find all the sub array with k distinct element 
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
    int longestSubstringWithKdistinctCharacter(string s,int k){
        int len = s.length();
        int  i = 0 , j = 0;
        int maxi = 0;
        unordered_map<char,int>mpp;

        while (j<len)
        {
            mpp[s[j]]++;
            while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]] ==0 ){
                    mpp.erase(s[i]);
                }
                i++;
            }
            if(mpp.size() == k){
               maxi = max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};