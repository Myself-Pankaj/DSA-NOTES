#include<bits/stdc++.h>
using namespace std;

class all_permutation{
    private:
    void permutation_helper(int n,int ind,vector<bool>& flag,vector<vector<int>> & res,vector<int>ds,  vector<int> & arr){
        if(ind == n){
            res.push_back(ds);
            return ;
        }

        for(int i = 0; i<n;i++){
            if(!flag[i]){
                flag[i] = true;
                ds.push_back(arr[i]);
                permutation_helper(n,ind+1,flag,res,ds,arr);
                ds.pop_back();
                flag[i] = false;
            }

        }
    }
    void per_optimal_helper(int n,int ind,vector<int>& arr,vector<vector<int>> & res){
        if(ind ==n){
            res.push_back(arr);
        }
        for (int i = ind; i < n; i++)
        {
            /* code */
            swap(arr[ind],arr[i]);
            per_optimal_helper(n,ind+1,arr,res);
            swap(arr[ind],arr[i]);
        }
        
    }
    public:
    vector<vector<int>> all_perm(vector<int>&arr){
        vector<int>ds;
        int n =  arr.size();
        vector<bool>flag(n,false);
        vector<vector<int>> res;
        // permutation_helper(n,0,flag,res,ds,arr);
        per_optimal_helper(n,0,arr,res);
        return res;
    }
};