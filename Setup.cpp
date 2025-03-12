#include <bits/stdc++.h>
using namespace std;
#include "basicMaths/digitCounting.cpp"
// {count_digit}
#include "basicMaths/reverseNumber.cpp"
// {reverse_number}
#include "basicMaths/isNumPalindrome.cpp"
// {is_palindrome}
#include "basicMaths/gcd.cpp"
// {euclidean_algo,gcd}
#include "basicMaths/lcm.cpp"
// {my_lcm}
#include "basicMaths/amstrong.cpp"
// {isArmstrong}
#include "basicMaths/checkPrime.cpp"
// {isPrime,isPrime_optimal}
#include"recurssion/basicRecurssion.cpp"
// {class basicRecurssion}
#include "array/basicArr.cpp"
// {class:basicArr}
#include"array/union.cpp"
// {class Union}
#include"array/missingNumber.cpp"
//{class:MissingNumber}
#include "array/maxConOne.cpp"
//{class:maxConOne}
#include "array/sortColor.cpp"
// {class sortColor}
#include "array/subarray.cpp"
// {class subarray}
#include "array/printSpiral.cpp"
// {class spiralMatrix}
#include "array/pascalTriangle.cpp"
// {class pascalTriangle}
#include "array/majorityElement.cpp"
// {class MajorityElement}
#include "array/mergeInterval.cpp"
// {class MergeInterval}
#include "array/threesum.cpp"
// {class ThreeSum}


    int main() {
      
        // int n,m;
        // cin>>n>>m;
        // vector<vector<int>> mat(n);
        // for(int i = 0 ; i<n;i++){
        //     for(int j = 0 ; j<m;j++){
        //         int ele;
        //         cin>>ele;
        //         mat[i].push_back(ele);
        //     }
        // }
        int n ;
        cin>>n;
        vector<int>arr;
        for(int i = 0  ; i<n;i++){
            int ele;
            cin>>ele;
            arr.push_back(ele);
        }
        


        // MergeInterval m1;
            ThreeSum t1;
        vector<vector<int>> ans = t1.threesum(arr);

        for(auto it: ans){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        // for(auto it: arr){
        //     cout<<it<<" ";
        // }

        return 0;

    }