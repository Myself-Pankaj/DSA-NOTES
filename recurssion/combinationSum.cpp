#include<bits/stdc++.h>
using namespace std;

class combinationsum{
    public:
    void cshelper(int n,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int target,int ind){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            cshelper(n,arr,ans,ds,target-arr[ind],ind+1);
            ds.pop_back();
        }
        cshelper(n,arr,ans,ds,target,ind+1);
    }
    void cshelper1(int n,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int target,int ind){
    
        if(target ==0){
            ans.push_back(ds);
            return;
        }

       for(int i = ind ; i<n;i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        cshelper1(n,arr,ans,ds,target-arr[i],i+1);
        ds.pop_back();
       }
    }
    //Duplicate element allowed
    vector<vector<int>>combinationSum1(vector<int>&arr,int target){
        vector<vector<int>>ans;
        vector<int>ds;
        int n = arr.size();
        cshelper(n,arr,ans,ds,target,0);
        return ans;
    }
    //Only unique element is allowed
    vector<vector<int>>combinationSum2(vector<int>&arr,int target){
        vector<vector<int>>ans;
        vector<int>ds;
        sort(arr.begin(),arr.end());
        cshelper1(arr.size(),arr,ans,ds,target,0);
        return ans;
    }
};