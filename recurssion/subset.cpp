#include<bits/stdc++.h>
using namespace std;
class Subsets{
    void subsetHelper1(int n, int ind,int sum,vector<int>&res,vector<int>&arr){
        if(ind ==n){
            res.push_back(sum);
            return;
        }
        sum+=arr[ind];
        subsetHelper1(n,ind+1,sum,res,arr);
        sum-=arr[ind];
        subsetHelper1(n,ind+1,sum,res,arr);

    }
    //brute force way 
    void  subsetHelper2(int n, int ind,set<vector<int>>&st,vector<vector<int>>&res,vector<int>&ds,vector<int>&arr){
        if(ind ==n){
            if(st.find(ds)==st.end()){
                st.insert(ds);
                res.push_back(ds);
            }
            return;
        }
        ds.push_back(arr[ind]);
        subsetHelper2(n,ind+1,st,res,ds,arr);
        ds.pop_back();
        subsetHelper2(n,ind+1,st,res,ds,arr);
        

    }
    //optimized wau to find a unque subset 
    void subsetHelper3(int n, int ind,vector<vector<int>>&res,vector<int>&ds,vector<int>&arr){
        
        res.push_back(ds);
        for(int i = ind; i<n;i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            subsetHelper3(n,i+1,res,ds,arr);
            ds.pop_back();
        }

    }
    public:
    vector<int>subset(vector<int>& arr){
        vector<int>res;
        int n = arr.size();

        subsetHelper1(n,0,0,res,arr);
        sort(res.begin(),res.end());
        return res;
    }
    vector<vector<int>>unique_subset(vector<int>& arr){
        vector<int>ds;
        vector<vector<int>>res;
        set<vector<int>>st;
        int n = arr.size();

        // subsetHelper2(n,0,st,res,ds,arr);
        subsetHelper3(n,0,res,ds,arr);
        return res;
    }
};