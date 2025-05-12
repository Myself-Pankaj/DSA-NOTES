#include <bits/stdc++.h>
using namespace std;

class InfixToPostfix{
    int value(char c){
        if (c == '^')
        return 3;
      else if (c == '/' || c == '*')
        return 2;
      else if (c == '+' || c == '-')
        return 1;
      else
        return -1;    
    }
    bool isOperand(char c){
        if((c >='a' && c<='z') || (c>='A' && c<='Z') || (c >='0' && c<='9')) return true;
        return false;
    }
    public:
    string InToPost(string s){
        int len = s.length();
        stack<char>st;
        string res = "";
        int i = 0;
        while(i < len){
            if(isOperand(s[i])){
                res+=s[i];
            }else if(s[i] =='('){
                st.push(s[i]);
            }else if(s[i] ==')'){
                while(!st.empty()&& st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while (!st.empty() && value(s[i]) <= value(st.top())){
                    res+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};