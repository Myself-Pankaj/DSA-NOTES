#include <bits/stdc++.h>
using namespace std;

class SubarrayRange
{
private:
    /* data */
    vector<int>nse(vector<int>&arr){
        int n = arr.size();
        vector<int>res(n,n);
        stack<int>st;
        for (int i = n-1; i >=0; i--)
        {
            /* code */
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int>pse(vector<int>&arr){
        int n = arr.size();
        vector<int>res(n,-1);
        stack<int>st;
        for (int i = 0; i < n; i++)
        {
            /* code */
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int>nge(vector<int>&arr){
        int n = arr.size();
        vector<int>res(n,n);
        stack<int>st;
        for (int i = n-1; i >=0; i--)
        {
            /* code */
            while (!st.empty() && arr[st.top()] <arr[i])
            {
                /* code */
                st.pop();
            }
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int>pge(vector<int>&arr){
        int n = arr.size();
        vector<int>res(n,-1);
        stack<int>st;
        for (int i = 0; i <n; i++)
        {
            /* code */
            while (!st.empty() && arr[st.top()] <=arr[i])
            {
                /* code */
                st.pop();
            }
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
    //     vector<int>res = pse(nums);
    //     for(auto it:res){
    //         cout<<it<<" ";
    //     }
    //    cout<<endl;
    vector<int>nsearr = nse(nums);
    vector<int>psearr = pse(nums);

    long long min_sum=0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            long long left = i-psearr[i];
            long long right = nsearr[i]-i;

            min_sum+=left*right*nums[i];

        }
    vector<int>ngearr = nge(nums);
    vector<int>pgearr = pge(nums);
    long long max_sum = 0;
    for (int i = 0; i < n; i++)
        {
            /* code */
            long long left = i-pgearr[i];
            long long right = ngearr[i]-i;

            max_sum+=left*right*nums[i];

        }
        return max_sum-min_sum;
    }
};


