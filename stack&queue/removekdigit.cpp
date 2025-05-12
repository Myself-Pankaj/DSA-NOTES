#include<bits/stdc++.h>
using namespace std;

class RemoveKDigit
{
private:
    /* data */
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        if(k ==len){
            return "0";
        }
        // stack<int>st;
        vector<int>st;
        for (int i = 0; i < len; i++)
        {
            /* code */
            if(!st.empty() && st.back()>num[i] && k!=0){
                st.pop_back();k--;
            }
            st.push_back(num[i]);
        }
        while(k!=0){
            st.pop_back();
            k--;
        }
        string res = "";
        for(auto it:st){
            res+=it;
        }
        return res;
    }
};
