#include <bits/stdc++.h>
using namespace std;
class basicArr{
    private:
    void rotateHelper(vector<int>& arr,int i,int n){
        while(i<=n){
            swap(arr[i],arr[n]);
            i++;n--;
        }
    }
    public:
    
    int secondLargest(vector<int>&arr){
    
        int secondLargest = INT_MIN,largest = INT_MIN;
        int n = arr.size();
        // sort(arr.begin(),arr.end());
        // for(int i = n-1;i>=0;i--){
        //     if(arr[i]!= arr[i-1]){
        //         secondLargest = arr[i-1];
        //         break;
        //     }
        // }
        for(int i = 0;i<n;i++){
            if(largest<arr[i]){
                secondLargest = largest;
                largest = arr[i];
            }else if(largest != arr[i] && arr[i]>secondLargest){
                secondLargest = arr[i];
            }
        }
        if(secondLargest == INT_MIN) return -1;
        return secondLargest;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            
            if(nums[i]>nums[(i+1)%n]){
                index++;
            }
        }
        

        return index<=1;
        
    }

    int removeDuplicates(vector<int>& nums) {
        int n =  nums.size();
        int j = 0;

        for(int i = 0 ; i<n;i++){
            if(nums[j]!=nums[i]){
                swap(nums[i],nums[j+1]);
                j++;
            }
        }
        return j;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
            rotateHelper(nums,0,(n-k)-1);
            rotateHelper(nums,n-k,n-1);
            rotateHelper(nums,0,n-1);
        
    }
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        for(int j = 0 ;j<n;j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }

    bool searchInSorted(vector<int>& arr, int k) {
        int n = arr.size();
        // Your code here
        int index = -1;
        for(int i = 0 ; i<n;i++){
            if(arr[i] == k){
                index = i;
            }
        }
        return index !=-1;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>posArr;// 3 1 2
        vector<int>negArr;//-2,-5,-4
        for(int i = 0 ;i<n;i++){
            if(nums[i]<0){
                negArr.push_back(nums[i]);
            }else{
                posArr.push_back(nums[i]);
            }
        }
        vector<int>ans;
        int i = 0; int size = nums.size()/2;
        while(i<size){
            ans.push_back(posArr[i]);
            ans.push_back(negArr[i]);
            i++;
        }
        return ans;
    }
    vector<int> rearrangeArray1(vector<int>& arr) {
        // 3 1 -2 -5 2 -4
        int n = arr.size();

        vector<int>ans(n,0);
        int pos =0,neg =1;
        for(int i = 0 ; i<n;i++){
            if(arr[i]>0){
                ans[pos] = arr[i];
                pos=pos+2;
            }else{
                ans[neg] = arr[i];
                neg+=2;
            }
        }

        return ans;
    }
};