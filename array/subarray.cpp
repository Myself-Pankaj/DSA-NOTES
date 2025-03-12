#include <bits/stdc++.h>
using namespace std;

class subarray{
    public:
    void print_subarray(vector<int>&arr){
        int n = arr.size();

        for(int i = 0 ; i<n;i++){
            for(int j = i;j<n;j++){
               for(int k = i;k<=j;k++){
                cout<<arr[k]<<" ";
               }
               cout<<endl;
            }
        }
    }
    int longestSubarrayBruteFroce(vector<int>& arr, int k) {
        int n = arr.size();
        int longest_ctr = 0;
        for (int i = 0; i < n; i++)
        {
            int len = 0;int curr_sum = 0;
            for (int j = i; j < n; j++)
            {   
                curr_sum+=arr[j];
                if(curr_sum == k){
                    len = j-i+1;
                }

            }
            longest_ctr = max(longest_ctr,len);
            
        }
        return longest_ctr;
    }
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int max_len = 0;
        int n = arr.size();
        unordered_map<int,int>mpp;
        int pre_sum = 0;
        for(int i = 0 ; i<n;i++){
            pre_sum+=arr[i];
            // cout<<"PreSum => "<<pre_sum<<endl;
            int len = i+1;
            if(pre_sum == k){
                max_len = max(max_len,len);
            }
            int toFind = pre_sum - k;
            // cout<<"toFind => "<<toFind<<endl;

            if(mpp.find(toFind)!=mpp.end()){
                len = i-mpp[toFind];
                max_len = max(max_len,len);
            }
            mpp[pre_sum] = i;
        }
       
        return max_len;
    }
    int smallestPair(vector<int>&arr, int s,int e){
        int smallest = INT_MAX,secSmall = INT_MAX;
       
        for(int i = s;i<e;i++){
            // cout<<arr[i]<<endl;
            if(smallest>arr[i]){
                secSmall = smallest;
                smallest = arr[i];
            }else if(arr[i]<secSmall && arr[i]!= smallest){
                secSmall = arr[i];
            }
        }
        if(e-s == 2 && arr[s] == arr[e-1]) return smallest+smallest;
        if(secSmall ==INT_MAX) return -1;
        return smallest+secSmall;
    }
    int pairWithMaxSum(vector<int> &arr) {
        int max_pair = 0;
        int n = arr.size();
        for(int i = 0 ; i<n;i++){
            int ans = 0;
            for(int j = i;j<n;j++){
                int sum = smallestPair(arr,i,j+1);
                ans = max(ans,sum);
            }
            max_pair = max(max_pair,ans);
        }
        return max_pair;
    }
    int pairWithMaxSum1(vector<int> &arr) {
        int max_pair = 0;
        int n = arr.size();
        for(int i = 0 ; i<n-1;i++){
            int ans = arr[i]+arr[i+1];

            max_pair = max(max_pair,ans);
        }
        return max_pair;
    }
    int maxLen(vector<int>& arr) {
        // code here
        int sum = 0;int n = arr.size();
        int max_len = 0;//2
        unordered_map<int,int>mpp;

        for(int i = 0; i<n;i++){
            sum+=arr[i];
            if(sum ==0){
                int len = i+1;
                max_len = max(max_len,len);
            }
            if(mpp.find(sum)!= mpp.end()){
                int len = i-mpp[sum];
                max_len=max(max_len,len);
            }
            if (mpp.find(sum) != mpp.end()) {
                max_len = max(max_len, i - mpp[sum]);
            } else {
                mpp[sum] = i;
            }    
        }
        return max_len;
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_pro = 1; int ans = 0;
        for(int i = 0 ; i<n;i++){
            max_pro*=nums[i];
            // if(max_pro<=0){
            //     max_pro =1;
            // }
            ans = max(max_pro,ans);
        }
        return ans;
    }
    
};