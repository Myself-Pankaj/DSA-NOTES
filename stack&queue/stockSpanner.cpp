#include<bits/stdc++.h>
using namespace std;

class StockSpanner
{
private:
    /* data */
    stack<pair<int,int>>st;
    int span;
public:
   
    int next(int price){
        span = 1;
        while(!st.empty() && st.top().first<=price ){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};


