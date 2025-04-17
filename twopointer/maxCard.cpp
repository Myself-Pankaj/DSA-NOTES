#include<bits/stdc++.h>
using namespace std;

class MaxCard{
    public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int total_sum = 0;
        vector<int>pre_sum(n+1,0);
        int max_sum = 0;
        for(int i = 1 ; i<=n;i++){
            total_sum+=cp[i-1];
            pre_sum[i]= total_sum;
        }
        int i = k,j=n;
        while(i>=0 &&j>=n-k){
            int curr_sum = 0,l_sum = 0,r_sum = 0;
            
            if(i>=0 && i<n){
                l_sum = pre_sum[i];
            }
            if(j<=n && j>=0){
                r_sum= total_sum-pre_sum[j];
            }
            curr_sum = l_sum+r_sum;
            max_sum = max(curr_sum,max_sum);
            i--;j--;
        }
        return max_sum;
    }
};