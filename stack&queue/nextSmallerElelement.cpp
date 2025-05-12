#include<bits/stdc++.h>
using namespace std;

class NextSmallerElement{
    public:
    vector<int> nse(vector<int>&arr){
        int n = arr.size();
        stack<int>st;vector<int>nse(n);
        for (int i = n-1; i >=0; i--)
        {
            /* code */
            while(!st.empty() && st.top()> arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = arr[i];
            }else{
                nse[i] = st.top();
            }
            st.push(arr[i]);
        }
        return nse;
    }
    vector<int> pse(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>res(n,-1);
        for (int i = 0; i<n; i++)
        {
            /* code */
            while(!st.empty() && arr[st.top()]> arr[i]){
                st.pop();
            }
            if(!st.empty()){
              
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
};