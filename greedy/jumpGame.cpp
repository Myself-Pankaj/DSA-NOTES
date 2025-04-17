#include<bits/stdc++.h>
using namespace std;

class JumpGame{
    private:
    int helper(int n,int index,int jump,vector<int>& arr){
        if(index >=n-1) return jump;
        int mini = INT_MAX;
        for(int i = 1;i<=arr[index] ;i++){
            mini = min(mini,helper(n,index+i,jump+1,arr));
        }
        return mini;
    }
    public:
    //can reach to end by jumping 
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int reach = 0;
        for(int i = 0 ; i<n;i++){
            if(i>reach ) return false;
            reach  = max(reach,i+nums[i]);
        }
        return true;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
 
       return helper(n,0,0,nums);
    }
    int jumpOptimal(vector<int>& nums) {
        int n = nums.size();
 
       int l = 0,r = 0;
       int jump  = 0;
       while(r<n-1){
        int farthest = 0;
        for(int i = l;i<r;i++){
            farthest = max(farthest,i+nums[i]);
        }
        l = r+1;
        r = farthest;
        jump++;
       }
       return jump;
    }
};