#include<bits/stdc++.h>
using namespace std;

class lenoflongstring{
    public:
    // TC:- O(len) SC:- O(len)
    int lengthOfLongestSubstring1(string s) {
        int len = s.length();
        int i = 0, j = 0;
        unordered_map<char,int>mpp;
        int max_len = 0;
        while (j<len)
        {
            /* code */
            if(mpp.find(s[j]) != mpp.end()){
                i = mpp[s[j]]+1;
            }
            max_len = max(max_len,j-i+1);
            mpp[s[j]] = j;

           j++;
        }
        return max_len;
    }
    int lengthOfLongestSubstring2(string s) {
        int len = s.length();
        int i = 0, j = 0;
        vector<int>hasharr(256,-1);
        int max_len = 0;
        while (j<len)
        {
            /* code */
            if(hasharr[s[j]] != -1 && hasharr[s[j]]>=i ){
                i = hasharr[s[j]]+1;
            }
            max_len = max(max_len,j-i+1);
            hasharr[s[j]] = j;

           j++;
        }
        return max_len;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0 , j = 0;
        int max_freq = 0,max_len = 0;
        vector<int>hsarr(26,0);
        while (j<n)
        {
            /* code */
            hsarr[s[j]-'A']++;
            max_freq = max(max_freq,hsarr[s[j]-'A']);

            int len = j-i+1;
            if(len-max_freq >k){
                hsarr[s[i]-'A']--;
                i++;
            }
            if(len-max_freq<=k){
                max_len =max(max_len,len);
            }
            j++;
        }
        return max_len;
    }

    int numberOfSubstrings(string s) {
        int n = s.length();
        int ctr = 0;
        vector<int>hsh(3,-1);
        for(int i = 0 ; i<n;i++){
            hsh[s[i]-'a'] = i;
            if(hsh[1]!=-1 && hsh[0]!=-1&& hsh[2]!=-1 ){
                int mini = INT_MAX;
                for(int j = 0 ;j<3;j++){
                    if(hsh[j]<mini){
                        mini = hsh[j];
                    }
                }

                ctr+=mini+1;
            }
        }
        return ctr;
    }
};