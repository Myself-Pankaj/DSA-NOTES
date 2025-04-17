#include<bits/stdc++.h>
using namespace std;

class Pratice{
   private:
   void count(int ind,string &s1,string &temp,vector<string> &res){
    res.push_back(temp);
    for (int i = ind; i < s1.length(); i++)
    {
        /* code */
        if(i<ind && s1[i] == s1[i-1])continue;
        string s = temp;
        temp+=s1[i];

        count(ind+1,s1,temp,res);
        temp = s;
    }
    
   }
   void combinationsumhelper(int ind,int k,int reqInd,int target,vector<int>&ds
    ,vector<vector<int>> &res,vector<int>& arr){
        if(ind == arr.size()||reqInd ==k){
            if(target ==0 && reqInd ==k){
                res.push_back(ds);
            }
            return;
        }
        ds.push_back(arr[ind]);
        combinationsumhelper(ind+1,k,reqInd+1,target-arr[ind],ds,res,arr);
        ds.pop_back();
        combinationsumhelper(ind+1,k,reqInd,target,ds,res,arr);

   }
    public:
    string betterString(string s1, string s2) {
        // code here
        vector<string> res1,res2;
        string temp1 = "";
        string temp2 = "";

        count(0,s1,temp1,res1);
        count(0,s2,temp2,res2);

        int len1,len2;
        len1 = res1.size();
        len2 = res2.size();
        if(len1<len2){
            return s2;
        }
        return s1;

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr = {1,2,3,4,5,6,7,8,9};
        vector<int>ds;
        vector<vector<int>>res;
        combinationsumhelper(0,k,0,n,ds,res,arr);
        return res;
    }
};