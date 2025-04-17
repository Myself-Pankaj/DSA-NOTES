#include<bits/stdc++.h>
using namespace std;

class Recurssion{
    public:
    void subseqhelper(int n,int ind,vector<vector<int>>& arr,vector<int> & ogarr,vector<int>&ds){
        if(ind>=n){
            if(ds.size()>0){
            arr.push_back(ds);
            }
            return ;
        }
        ds.push_back(ogarr[ind]);
        subseqhelper(n,ind+1,arr,ogarr,ds); //2
        ds.pop_back();//
        subseqhelper(n,ind+1,arr,ogarr,ds);

    }
    void subseqKsum(int n,int ind,vector<vector<int>>& arr,vector<int> & ogarr,vector<int>&ds,int k,int sum){
        if(ind>=n){
            if(sum ==k){
            arr.push_back(ds);
            } 

            return ;
        }
        
        ds.push_back(ogarr[ind]);
        sum+=ogarr[ind];
        subseqKsum(n,ind,arr,ogarr,ds,k,sum);
        ds.pop_back();
        sum-=ogarr[ind];
        subseqKsum(n,ind+1,arr,ogarr,ds,k,sum);

    }
    bool printOneSubSeq(int n , int ind,vector<vector<int>> &arr,vector<int>&ogarr,vector<int>& ds,int k,int sum){
        if(ind == n){
            if(sum ==k){
                arr.push_back(ds);
                return true;
            }
            return false;
        }
        ds.push_back(ogarr[ind]);
        sum+=ogarr[ind];
        if(printOneSubSeq(n,ind+1,arr,ogarr,ds,k,sum)== true){
            return true;
        }
        sum-=ogarr[ind];
        ds.pop_back();
        if(printOneSubSeq(n,ind+1,arr,ogarr,ds,k,sum) ==true) return true;
        return false;
    }

    int countSubSeq(int n, int ind,vector<int>& ogarr,int k,int sum){
        if(ind == n){
            if(sum ==k ){
                return 1;
            }
            return 0;
        }
        sum+=ogarr[ind];
        int l = countSubSeq(n,ind+1,ogarr,k,sum);
        sum-=ogarr[ind];
        int r = countSubSeq(n,ind+1,ogarr,k,sum);

        return l+r;
    }
    
    vector<vector<int>>subseq(vector<int>& arr){
        vector<vector<int>>ans;
        vector<int>ds; int k = 7;
        subseqKsum(arr.size(),0,ans,arr,ds,k,0);
        return ans;
    }
    
};