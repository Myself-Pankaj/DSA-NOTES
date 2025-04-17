#include<bits/stdc++.h>
using namespace std;

class MinimumRailwayStation{
    public:
    int minplatform(int n,int arival[],int dept[]){
        int maxi = 0;
        for(int i = 0 ; i<n;i++){
            int ctr = 1;
            for(int j = i+1;j<n;j++){
                if (!(dept[i] < arival[j] || dept[j] < arival[i])){
                    ctr++;
                }
            }
            maxi = max(maxi,ctr);
        }
        return maxi;
    }
    int minplatformOptimal(int n,int arr[],int dep[]){
        int maxi = 0;
        sort(arr , arr+n);
        sort(dep , dep+n);
        int  i = 0 , j = 0;
        int ctr = 0;
        while(i<n){
            if(arr[i]<dep[j]){
                ctr++;
                i++;
            }else{
                ctr--;
                j++;
            }
            maxi = max(ctr,maxi);
        }

        return maxi;
    }
};