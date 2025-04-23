#include <bits/stdc++.h>
using namespace std;

class DistributeCandy{
    public:
    int minCandyDistribution(vector<int>&child){
    
        int n = child.size();
        vector<int>temp1;
        int ctr = 1;
        temp1.push_back(ctr);
        for(int i = 1 ; i<n;i++){
            if( child[i-1]<child[i]){
                ctr++;
            }else{
                ctr =1;
            }
            temp1.push_back(ctr);
        }
        vector<int>temp2;
        int candy = 1;
        temp2.push_back(candy);
        for(int i = n-2 ; i>=0;i--){
            if( child[i+1]<child[i]){
                candy++;
            }else {
                candy =1;
            }
            temp2.push_back(candy);
        }
        reverse(temp2.begin(), temp2.end());
        int tCandy = 0;
        for(int i = 0 ; i<n;i++){
            tCandy = tCandy+ max(temp1[i],temp2[i]);

        }
        return tCandy;
    }
    int minCandyDistributionSlope(vector<int>& arr) {
        int n = arr.size();
        int total_candy = 1;
    
        int i = 1;
        while (i < n) {
            if (arr[i] == arr[i - 1]) {
                total_candy++;
                i++;
                continue;
            }
    
            int peak = 1;
            while (i < n && arr[i] > arr[i - 1]) {
                peak++;
                total_candy += peak;
                i++;
            }
    
            int down = 1;
            while (i < n && arr[i] < arr[i - 1]) {
                down++;
                total_candy += down;
                i++;
            }
    
            if (down > peak) {
                total_candy += (down - peak);
            }
        }
    
        return total_candy;
    }
    

};