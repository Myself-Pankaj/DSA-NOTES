#include <bits/stdc++.h>
using namespace std;

class StringHashing{
    public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>mpp;
        for(int i = 0 ;i<s.length();i++){
            mpp[s[i]] ++;
        }
        for(auto it: t){
            if(mpp.find(it)!= mpp.end()){
                mpp[it]--;
            }
        }
        for(auto it:mpp){
            if(it.second!=0) return false;
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
        //tommay //paper 
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int>mpp;
        unordered_map<char,int>mpp2;
        for(int i = 0 ; i<s.length();i++){
            mpp[s[i]]++;
            mpp2[t[i]]++;
        }
        int sum1=0;int sum2= 0;
        for(auto it:mpp){
            cout<<it.first<<" "<<it.second;
        }
        return sum1 == sum2;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
    
      
        for (char c : s) {
            mpp[c]++;
        }
    
        priority_queue<pair<int, char>> maxHeap;

        for (auto& it : mpp) {
            maxHeap.push({it.second, it.first});
        }
        
        string res = "";
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            res.append(count, ch);
        }
        
    
        return res;
    }
};