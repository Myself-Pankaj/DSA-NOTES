#include<bits/stdc++.h>
using namespace std;

class ThreeSum{
    public:
    vector<vector<int>>threesum(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i<n;i++){
            int j = i+1,k = n-1;
            if(i>0 && arr[i] == arr[i-1]) continue;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    ans.push_back({arr[i],arr[j],arr[k]});
                    j++;k--;
                    while(j<k && arr[j]== arr[j+1]){
                        j++;
                    }
                }
            }
        }
        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = INT_MAX; int ans = INT_MAX;
        for(int i = 0 ; i<n;i++){
    
            int j = i+1,k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if (sum == target) return sum; 
                if (abs(sum - target) < abs(mini)) {
                    mini = sum - target;
                    ans = sum;
                }
    
                if (sum < target) 
                    j++;  
                else 
                    k--; 
            }
        }
        return ans;
    }

};