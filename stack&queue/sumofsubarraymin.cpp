#include<bits/stdc++.h>
using namespace std;

class sumofsubarraymin
{
private:
    /* data */
    vector<int> nse(vector<int>&arr){
        int n = arr.size();
        stack<int>st;vector<int>nse(n);
        for (int i = n-1; i >=0; i--)
        {
            /* code */
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> pse(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>res(n);
        for (int i = 0; i<n; i++)
        {
            /* code */
            while(!st.empty() && arr[st.top()]> arr[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
public:
    int minSum(vector<int>&arr){
        int mini_sum = 0;
        int n = arr.size();

        for(int i = 0 ; i<n;i++){
            for(int j = i;j<n;j++){
                int curr_min = INT_MAX;
                for(int k = i;k<=j;k++){
                    curr_min = min(curr_min,arr[k]);
                }
                mini_sum+=curr_min;
            }
        }

        return mini_sum;
    }
    int minSumOptimal(vector<int>&arr){
        int mini_sum = 0;
        int n = arr.size();

        vector<int>nsearr = nse(arr);
        vector<int>psearr = pse(arr);
        int mod = (int)(1e9+7);
        for (int i = 0; i < n; i++)
        {
            /* code */
            int left = i-psearr[i];
           
            int right = nsearr[i]-i;
          
        }
        

        return mini_sum;
    }
};

