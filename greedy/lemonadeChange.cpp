#include<bits/stdc++.h>
using namespace std;

class LemonadeChange{
    public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five=0,ten = 0,twenty = 0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            if(bills[i]== 5){
                five++;
            }else if(bills[i] == 10){
               if(five>=1){
                five--;
               }else{
                return false;
               }
               ten++;
            }else if (bills[i] == 20 ){
                if(five>=1 && ten>=1){
                    five--;
                    ten--;
                }else if(ten <1 && five>=3){
                    five = five-3;
                }else{
                    return false;
                }
                twenty++;
            }else{
                return false;
            }
        }
        return true;
    }
};