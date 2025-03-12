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
};