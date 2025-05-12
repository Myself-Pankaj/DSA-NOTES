#include<bits/stdc++.h>
using namespace std;

class InfixToPrefix{
    string reverse(string s){
        int len = s.length();
        for(int i = 0 ; i<len/2;i++){
            int  k = (len-1) -i;
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
    
            if (s[k] == '(') s[k] = ')';
            else if (s[k] == ')') s[k] = '(';
            swap(s[i],s[k]);

        }
        return s;
    }
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
    string infixtoprefix(string s){
        string rs = reverse(s);
        string res = "";stack<char>st;
        for (char it : rs) {
            if (isOperand(it)) {
                res += it;
            } else if (it == '(') {
                st.push(it);
            } else if (it == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop '('
            } else {
                while (!st.empty() && ((value(it) < value(st.top())) || 
                       (value(it) == value(st.top()) && it != '^'))) {
                    res += st.top();
                    st.pop();
                }
                st.push(it);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        res = reverse(res);
        return res;
    }
    string reversePublic(string s){
        int len = s.length();
        for(int i = 0 ; i<len/2;i++){
            int  k = (len-1) -i;
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
    
            if (s[k] == '(') s[k] = ')';
            else if (s[k] == ')') s[k] = '(';
            swap(s[i],s[k]);

        }
        return s;
    }
};