#include<bits/stdc++.h>
using namespace std;

class LargestRectangle
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
    vector<int>pse(vector<int>&arr){
        int n = arr.size();
        vector<int>res(n,-1);stack<int>st;
        for (int i = 0; i <n; i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()) res[i] = st.top();
            st.push(i); 
        }
        return res;
    }
public:
   int largestrectangleBrute(vector<int>&arr){
        int n = arr.size();
        int largest_area = 0;

        for(int i = 0 ; i<n;i++){
            int area = 0;int curr_min = INT_MAX;
            for (int j = i; j < n; j++)
            {
                /* code */
                curr_min = min(curr_min,arr[j]);
                area = max(curr_min*(j-i+1),area);
            }
            largest_area = max(area,largest_area);
        }
        return largest_area;
   }
   int largestrectangleOptimal(vector<int>&arr){
    int n = arr.size();
    int largest_area = 0;
    vector<int>front = nse(arr);
    vector<int>back = pse(arr);
    for(int i = 0 ; i<n;i++){
        int f_range = front[i]-i;
        int b_range = i-back[i];
        int t_range = (f_range+b_range)-1;
        largest_area = max(largest_area,arr[i]*t_range);
    }

    
    return largest_area;
}
};


