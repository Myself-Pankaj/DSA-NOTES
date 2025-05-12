#include<bits/stdc++.h>
using namespace std;

class MaximalRectangle
{
private:
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
        for (int i = 0; i<n; i++)
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
    int largestRectangle(vector<int>&arr){
        int n = arr.size();int max_area = 0;
        vector<int> nsearr = nse(arr);
        vector<int> psearr = pse(arr);
        for(int i = 0;i<n;i++){
            int front_s = nsearr[i] - i;
            int rare_s = i - psearr[i];

            int area = (front_s +rare_s)-1;
            max_area = max(max_area,area*arr[i]);
        }
        return max_area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>mat(n,vector<int>(m));
     
        for(int j = 0;j<m;j++){
            int sum = 0;
            for(int i = 0 ; i<n;i++){
                if(matrix[i][j] == '1'){
                    sum+=1;
                }
                if(matrix[i][j] == '0') sum = 0;
                mat[i][j] = sum;
            }
        }
        int overall_max_area = 0;
        for(int i = 0 ; i<n;i++){
            int max_area = largestRectangle(mat[i]);
            overall_max_area = max(overall_max_area,max_area);
        }
        return overall_max_area;
    }
};


