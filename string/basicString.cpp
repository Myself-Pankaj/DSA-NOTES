#include<bits/stdc++.h>
using namespace std;

class StringBasic{
    public:
    string reverseWords(string s) {
        int i = s.length()-1;
        string res = ""; string temp = "";
        int j = 0;
        while(s[j]==' '){
            j++;
        }
        while(i>=j){
            if(s[i] ==' '){
                reverse(temp.begin(),temp.end());
                if(temp.length()!=0){
                res+=temp+" ";
                }
                temp="";
            }else{
                temp+=s[i];
                if(i ==j){
                    reverse(temp.begin(),temp.end());
                    res+=temp;
                    temp="";
                }
            }
            i--;
        }
        return res;
    }
    string largestOddNumber(string s) {
       int len = s.length();
        
        for(int i =len-1;i>=0;i--){
            int num = 0;
            num = num*10+(s[i]-'0');
            if(num%2!=0){
                return (s.substr(0,i+1));
            }
        }
       

        return "";
    }
  
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        sort(strs.begin(),strs.end());
        string res="";
        string first = strs[0];
        string last = strs[len-1];
        if(last== first){
            return first;
        }
        int i = 0;
        while(first[i]== last[i]){
            res+=first[i];
            i++;
        }
        return res;
    }
    int maxDepth(string s) {
        //(((
       stack<char>st; int maxi = 0;
       for(int i = 0 ; i<s.length();i++){
        if(s[i] =='('){
            st.push(s[i]);
        }
        if(s[i] ==')'){
            st.pop();
        }
        int size = st.size();
        maxi = max(size,maxi);
       } 
       return maxi;
    }
  
    int myatoi(string s){
        int sign = 1; int num = 0;
        int i = 0;int n = s.length();
        while(i<n && s[i] == ' '){
            i++;
        }
        if(i<n && (s[i] =='-' || s[i]=='+')){
            if(s[i] =='-') sign = -1;
            else sign = 1;i++;
        }
        while(i<n && s[i]>='0'&& s[i]<='9'){
            num=num*10+(s[i]-'0');
            if (num * sign > INT_MAX) return INT_MAX;
            if (num * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return num*sign;
    }
};