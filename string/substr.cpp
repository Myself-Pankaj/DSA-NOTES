#include<bits/stdc++.h>
using namespace std;

class Substr{
    private:
    int countSubstrhelper(string &s,int k){
        int n = s.length();
        int ctr = 0;
        unordered_map<char,int>mpp;
        int i = 0; int j = 0;
        while(j<n &&i<n){
            mpp[s[j]]++; 
            while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            
                ctr= ctr+(j-i)+1;
            
            j++;
        }
        return ctr;
    }
    bool isPalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;end--;
        }
        return true;
    }
    bool isPalindrome1(string &s){
        int start = 0; int end = s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;end--;
        }
        return true;
    }
    public:
    //How can we find substr in nay given string 
    bool rotateString(string s, string goal) {
        if(s.length()!= goal.length()) return false;
        string res = "";
        res = s+s;
        if(res.find(goal)!= std::string::npos){
            return true;
        }
        return false;
    }
    //Optimal 
    int countSubstr(string& s, int k) {
        return countSubstrhelper(s,k)-countSubstrhelper(s,k-1);
    }
    //Brute
    int countSubstrBrute(string &s,int k){
        int n = s.length();
        int ctr = 0;
        vector<string>res;
        for(int i = 0 ; i<n;i++){
            for(int j = i; j<n;j++){
                string temp = s.substr(i,j-i+1);
                res.push_back(temp);
            }
        }
        for(auto it: res)
        {
            unordered_map<char,int>mpp;
            for(auto i:it){
                mpp[i]++;
            }
            if(mpp.size()==k) ctr++;
          
        }
        
    }
    string longestPalindrome(string s) {
        string res;int maxi = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            /* code */
            for (int j = i; j < len; j++)
            {
                /* code */
                if(isPalindrome(s,i,j)){
                    if((j-i)>res.length()){
                        res= s.substr(i,j-i+1);
                    }
                }

            }
            
        }
        return res;
    }
   
    int findMatching(string text, string pat) {
        int n = text.length();
        int len = pat.length();
        for (int i = 0; i < n; i++)
        {
            /* code */
            for (int j = i; j < n; j++)
            {
                /* code */
                string temp = text.substr(i,j-i+1);
                if(temp == pat){
                    return i;
                }
            }
            
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        int len = haystack.length();
        int n = needle.length();
        if(haystack == needle) return 0;
       
    
        for(int i = 0 ; i<len; i++){
            string temp = haystack.substr(i,n);
            // cout<<temp<<endl;
            if(needle == temp){
               return i;
            }
        }

        return -1;
    }
    
    string shortestPalindrome(string s) {
      string res = s;
      reverse(res.begin(),res.end());
      int len = s.length();
      string temp="";
      for(int i = 0;i<len;i++){

        temp+=res[i];
        string temp2 = temp+s;
        // cout<<temp2<<endl;
        if(isPalindrome1(temp2)){
           return temp2;
        }
      }
    return "-1";
    }
};