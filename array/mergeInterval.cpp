#include<bits/stdc++.h>
using namespace std;

class MergeInterval{
    public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;//1 4
        sort(arr.begin(),arr.end());
        for(auto it : arr){
            if(!ans.empty() && ans.back()[1]>=it[0]){
                if(ans.back()[1]<it[1]){
                    ans.back()[1] = it[1];
                }else{
                    continue;
                }
            }else{
            ans.push_back(it);
            }
        }
        
        return ans;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                k--;i--;
            } else {
                nums1[k] = nums2[j];
                k--;j--;
            }
        }
    }
    
};