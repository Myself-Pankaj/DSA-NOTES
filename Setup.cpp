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
#include "linklist/SLL/arraytoLL.cpp"
//{class AtoLL}
#include "linklist/DLL/arraytoDLL.cpp"
//{class AtoDLL}
#include "linklist/DLL/operationonDLL.cpp"
//{class operationOnLL}
#include "linklist/SLL/operationonLL.cpp"
//{class operationOnLL}
#include "linklist/SLL/addtwoll.cpp"
//{class addTwoLL}




    int main() {
        
        
        vector<int>arr;
        int n;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            /* code */
            int ele;
            cin>>ele;
            arr.push_back(ele);
        }
        vector<int>arr1;
        int m;
        cin>>m;
        for (int i = 0; i < m; i++)
        {
            /* code */
            int ele;
            cin>>ele;
            arr1.push_back(ele);
        }
        AtoLL l1;
        Node*h1= l1.convertAtoLL(arr);
        Node*h2= l1.convertAtoLL(arr1);

        addTwoLL l2;
        
        Node*newhead = l2.add2ll(h1,h2);
        l1.PintLL(newhead);
    

        return 0;
    }