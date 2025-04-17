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
#include "recurssion/subsequence.cpp"
// {class Recurssion}
#include "recurssion/combinationSum.cpp"
// {class combinationsum}
#include "recurssion/subset.cpp"
// {class Subsets}
#include "recurssion/permutation.cpp"
// {class all_permutation}
#include "recurssion/nqueen.cpp"
// {class nqueen}
#include "recurssion/sudoko.cpp"
// {class Sudoko}
#include "recurssion/pratice.cpp"
//{ class Pratice}
#include "string/basicString.cpp"
//{class StringBasic}
#include "string/substr.cpp"
//{ class Substr}
#include "string/hashingpb.cpp"
//{ class StringHashing}
#include "twopointer/longestString.cpp"
//{ class lenoflongstring}
#include "twopointer/longsubWithkdistinct.cpp"
//{ class longestSubarrayWithkdiffele}
#include "twopointer/niceSubarray.cpp"
// { class NiceSubarray}
#include "twopointer/maxCard.cpp"
//{ class MaxCard}
#include "twopointer/minwindowSubstr.cpp"
//{class MinWindow}
#include "greedy/assignCookie.cpp"
//{class CookieAssigning}
#include "greedy/lemonadeChange.cpp"
//{class LemonadeChnage}
#include "greedy/sjf.cpp"
//{class SJF}
#include "greedy/jumpGame.cpp"
//{class JumpGame}
#include "greedy/meetingRooms.cpp"
//{class MeetingRoomProblem}
#include "greedy/intervals.cpp"
//{ class Intervals}
#include "greedy/minPlatform.cpp"
//{ class MinimumRailwayStation}
#include "greedy/validParanthesis.cpp"
// { class validP}
#include "greedy/candy.cpp"
//{class DistributeCandy}


vector<vector<int>> merge(vector<vector<int>>& arr) {
     int n = arr.size();  
     vector<vector<int>> res;
     sort(arr.begin(),arr.end(),[](const vector<int>& a, const vector<int>& b){
        return a[1]< b[1];
     });
    res.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        /* code */
        if(res.back()[1]> arr[i][0]){
            if(arr[i][0]<res.back()[0]){
                res.back()[0] = arr[i][0];
            }
            if(res.back()[1]<arr[i][1]){
                res.back()[1] = arr[i][1];
            }
        }else{
            res.push_back(arr[i]);
        }
    }
    
     return res;
   
    
}
    int main() {
        
        vector<vector<int>> intervals = {{2,3},
    {4,5},{6,7},{8,9},{1,10}};
      
        vector<vector<int>> ans = merge(intervals);
        for(auto it: ans){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return 0;
    }