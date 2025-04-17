#include<bits/stdc++.h>
using namespace std;

class MinWindow{
    public:
    string minWindow(string s, string t) {
        int slen = s.length();
        int tlen = t.length();

        vector<int>freqs(128,0), freqt(128,0);

        for(auto it : t) freqt[it]++;

        int i = 0,j = 0,required = tlen,mini = INT_MAX,start = 0;

        while(j<slen){
            if(freqt[s[j]] >0){
                if(freqs[s[j]]< freqt[s[j]]) required--;
                freqs[s[j]]++;
            }
            j++;
            while(required ==0){
                
                    if(j-i<mini){
                        mini = j-i;
                        start = i;
                    }
                
                if(freqt[s[i]] >0){
                    freqs[s[i]]--;
                    if(freqs[s[i]]<freqt[s[i]]) required++;
                }
                i++;
            }
        }
        return mini ==INT_MAX ? "" : s.substr(start,mini);
    }
};