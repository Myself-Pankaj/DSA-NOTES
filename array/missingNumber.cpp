#include<bits/stdc++.h>
using namespace std;

class MissingNumber{
    public:
    int missingNumber1(vector<int>& nums) {
        int xorSum = 0, n = nums.size();
        
        for (int i = 0; i <= n; i++) {
            xorSum ^= i;  // XOR with all numbers from 0 to n
        }
    
        for (int num : nums) {
            xorSum ^= num;  // XOR with all elements in the array
        }
    
        return xorSum;  // The missing number
    }
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = (n*(n+1))/2;
        int arrSum = 0;
        for(int i = 0 ; i<n;i++){
            arrSum+=nums[i];
        }
       return sum-arrSum;
    }

    vector<int> findTwoElement1(vector<int>& arr) {
        // code here
        // n(n+1)/2 9-6 =3
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int rn = -1;int mn = -1;
        int i = 0; int j =1;
        while(i<n){
            if( i < (n-1) && arr[i] == arr[i+1]){
                rn = arr[i];
            }else{
                if(arr[i]!=j){
                    mn = j;
                    j++;
                }
                j++;
            }
            i++;

        }
        if(mn == -1) return {rn,n};
        return {rn,mn};


    }


    vector<int> findTwoElement2(vector<int>& arr) {
        // code here
        // n(n+1)/2 9-6 =3
        
        unordered_map<int,int>mpp;
        for(int i = 0 ; i<arr.size();i++){
            mpp[arr[i]]++;
        }
        int repeatedNo = 0;
        for(auto it:mpp){
            if(it.second>1){
                repeatedNo = it.first;
            }
        }
        int n =arr.size();
        int summision = (n*(n+1))/2;
        cout<<summision<<endl;
        int sum = 0;
        for(int i = 0 ; i<n;i++){
            sum+=arr[i];
        }
        cout<<sum<<endl;
        sum = sum-repeatedNo;
        int missigNo = summision-sum;
        return {missigNo,repeatedNo};
    }

    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        // n(n+1)/2 9-6 =3

        int n = arr.size();
        long long sumN = (n * (n + 1)) / 2;
        cout<<"Total SUm : "<<sumN<<endl;
        long long sumNSq = (n * (n + 1) * (2 * n + 1)) / 6;
        cout<<"Total sq sum : "<<sumNSq<<endl;
    
        long long sumArr = 0, sumSqArr = 0;
        
        for (int i = 0; i < n; i++) {
            sumArr += arr[i];
            sumSqArr += (long long)arr[i] * arr[i];
        }
        cout<<"Total arrSum : "<<sumArr<<endl;
        cout<<"Total arrsqSum : "<<sumSqArr<<endl;
    
    
        // Equations:
        // sumN - sumArr = Missing - Repeating (x - y)1
        // sumNSq - sumSqArr = Missing^2 - Repeating^2  (x^2 - y^2) = (x - y)(x + y)
    
        long long diff = sumN - sumArr;        
        cout<<"Diff of total sum - arrsum: "<<diff<<endl;
    
        long long sumDiff = sumNSq - sumSqArr;  
    
        cout<<"Diff of total sq sum - arrsqsum: "<<sumDiff<<endl;
    
        long long sumXY = sumDiff / diff;    
      
    
    
        int missing = (diff + sumXY) / 2;
        int repeating = sumXY - missing;
    
        return {repeating, missing};

    }

};