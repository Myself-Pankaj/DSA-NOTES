#include<bits/stdc++.h>
using namespace std;

class NGE{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();


        vector<int>nge(m,-1);
        vector<int>ans;

        for(int i = 0;i<m;i++){
            int element = nums2[i];
            int ele  = 0;
            for(int j = i+1 ; j<m;j++){
                if(nums2[j]>element){
                    ele= nums2[j];
                    break;
                }
            }
            if(ele !=0){
                nge[i] = ele;
            }
        }
        for(int i = 0; i<n;i++){
            int ele = nums1[i]; int res;
            for(int j=0;j<m;j++){
                if(ele == nums2[j]){
                    res = nge[j];
                }
            }
            ans.push_back(res);
        }
        return ans;
    }

    vector<int> nextGreaterElementBetter(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int>st;

        vector<int>nge(m,-1);
        vector<int>ans;

        for(int i = m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i] = -1;
            }else nge[i] = st.top();
            
            st.push(nums2[i]);
        }
        for(int i = 0; i<n;i++){
            int ele = nums1[i]; int res;
            for(int j=0;j<m;j++){
                if(ele == nums2[j]){
                    res = nge[j];
                }
            }
            ans.push_back(res);
        }
        return ans;
    }

    vector<int> nextGreaterElementOptimal(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int>st;

        unordered_map<int,int>mpp;
        vector<int>ans;

        for(int i = m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]] = -1;
            }else {
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i = 0; i<n;i++){
            ans.push_back(mpp[nums1[i]]);
        }
        
        return ans;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>res(n,-1);
        for (int i = 2*n-1; i >=0; i--)
        {
            /* code */
            int index = i%n;
            while(!st.empty() && st.top()<=nums[index]){
                st.pop();
            }
            
          
            if(!st.empty()){
                res[index]=st.top();
            }
            st.push(nums[index]);
        }
     
        return res;
    }
};