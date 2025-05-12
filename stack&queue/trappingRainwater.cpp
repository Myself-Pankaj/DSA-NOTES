#include<bits/stdc++.h>
using namespace std;

class TrapRainwater{
    public:
    int trapbrute(vector<int>& height) {
        int n = height.size();
        vector<int>premax(n);
        vector<int>suffmax(n);
        premax[0] = height[0];
        for(int i = 1;i<n;i++){
            premax[i] = max(premax[i-1],height[i]);
        }
        suffmax[n-2] = height[n-2];
        for (int i = n-2; i >=0; i--)
        {
            /* code */
            suffmax[i] = max(suffmax[i+1],height[i]);
        }
        int totalWater = 0;
        for(int i = 0; i<n;i++){
            int lm = premax[i],rm = suffmax[i];

            if(height[i]<lm && height[i]<rm){
                totalWater+= min(lm,rm)-height[i];
            }
        }
        return totalWater;

    }
    int trapOptimal(vector<int>&arr){
        int n = arr.size();int total = 0;

        int left_max = 0,right_max = 0;
        int left = 0,right = n-1;

        while(left<right){
            if(arr[left]<=arr[right]){
                if(left_max >arr[left]){
                    total+=left_max-arr[left];
                }else{
                    left_max = arr[left];
                }
                left++;
            }else{
                if(right_max>arr[right]){
                    total+=right_max-arr[right];
                }else{
                    right_max= arr[right];
                }
                right--;
            }
        }
        return total;
    }
};