#include<bits/stdc++.h>
using namespace std;

class validP{
    bool helper(int n,int ind,int ctr,string &s){
        if(ind ==n){
            if(ctr ==0){
                return true;
            }
            return false;
        }
        if(ctr<0) return false;

        if(s[ind] =='('){
            return helper(n,ind+1,ctr+1,s);
        }else if(s[ind] ==')'){
            return helper(n,ind+1,ctr-1,s);
        }else{
        return helper(n,ind+1,ctr+1,s) || helper(n,ind+1,ctr,s) || helper(n,ind+1,ctr-1,s);
        }
    }
    public:
    bool isvalid(string &s){
        int n = s.length();
        return helper(n,0,0,s);
    }

    bool isvalidOptimal(string &s){
        int len = s.length();
        int mini =0,maxi=0;

        for(int i = 0 ; i<len;i++){
            if(s[i] =='('){
                mini++;
                maxi++;
            }else if(s[i] ==')'){
                mini --;
                maxi--;
            }else{
                mini--;
                maxi++;
            }
            if(mini<0) mini = 0;
            if(maxi<0) return false;
        }
        return mini == 0;
    }
    string removeOuterParentheses(string s) {
        int n = s.length();
        int ctr = 0;string res = "";
        int i = 0,j= 0;
    
        while(j<n){
            if(s[j] == '('){
                ctr++;
            }else{
                ctr--;
            }
            if(ctr ==0){
                cout<<i<<" "<<j<<endl;
                string temp = s.substr(i+1,j-i-1);
                res+=temp;
                i=j+1;
            }
            j++;
        }    
        return res;
    }
    string removeOuterParenthesesOptimal(string s) {
        int count = 0;
        string ans = "";
        for (int i = 0; i<s.length();i++)
        {
            if(s[i]==')') count--;
            if(count!=0) ans.push_back(s[i]);
            if(s[i]=='(') count++;
        }

     return ans;   
    }
};