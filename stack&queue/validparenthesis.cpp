#include<bits/stdc++.h>
using namespace std;

class CheckValidParenthesis{
    public:
    bool isValid(string s){
        stack<int>st;
        for(char it : s){
            if(it == '(' || it == '{'|| it =='['){
                st.push(it);
            }else{
                if (!st.empty() &&
                    ((it == ')' && st.top() == '(') || (it == '}' && st.top() == '{') ||
                     (it == ']' && st.top() == '['))) {
                    st.pop();
                }else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};