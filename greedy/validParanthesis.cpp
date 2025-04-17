#include<bits/stdc++.h>
using namespace std;

class validP{
    bool helper(int ind,int ctr,string &s){
        if(ind ==s.length()){
            if(ctr ==0){
                return true;
            }
            return false;
        }
        if(ctr<0) return false;

        if(s[ind] =='('){
            return helper(ind+1,ctr+1,s);
        }else if(s[ind] ==')'){
            return helper(ind+1,ctr-1,s);
        }else{
        return helper(ind+1,ctr+1,s) || helper(ind+1,ctr,s) || helper(ind+1,ctr-1,s);
        }
    }
    public:
    bool isvalid(string &s){
        return helper(0,0,s);
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
};