#include<bits/stdc++.h>
using namespace std;

class Stocks{
    public:
    int maxProfit(vector<int>& p) {
        int low = INT_MAX;
        int max_profit = 0;
        for(int i = 0 ; i<p.size();i++){
            if(low>p[i]){
                low = p[i];
            }
            int profit = p[i]-low;
            max_profit = max(max_profit,profit);
        }
        return max_profit;
    }
};