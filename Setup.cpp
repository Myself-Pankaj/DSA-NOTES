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
#include "linklist/SLL/oddevenll.cpp"
//{class OddEvenLL}
#include "linklist/SLL/isllpalindrome.cpp"
//{class isListPalindrome}
#include "linklist/SLL/findintersection.cpp"
//{class FindIntersection}
#include "linklist/SLL/slowFastAlgo.cpp"
//{class SlowFast}
#include "linklist/DLL/deleteOccurence.cpp"
//{class DeleteOccurence}
#include "linklist/DLL/findpair.cpp"
//{class FindPair}
#include "linklist/DLL/removeDuplicates.cpp"
//{class RemoveDuplicate}
#include "linklist/operationonflatenlist.cpp"
// {class AtoFLL,mainFun}
#include "linklist/SLL/rotateaLL.cpp"
//{class Rotate}
#include "linklist/SLL/sortall.cpp"
//{class SortLL}
#include "linklist/SLL/reverseingroupk.cpp"
// {class ReversingInKGroup  //tip Not completed}
#include "stack&queue/DS/arrtostack.cpp"
// {class Stack}
#include "stack&queue/DS/arrtoqueue.cpp"
//{class Queue}
#include "stack&queue/DS/lltostack.cpp"
//{class LLStack}
#include "stack&queue/DS/lltoqueue.cpp"
//{class LLQueue}
#include "stack&queue/DS/stacktoqueue.cpp"
//{class STOQ}
#include "stack&queue/DS/queuetostack.cpp"
//{class QTOS}
#include "stack&queue/ArithmeticOperation/infixtopostfix.cpp"
// {class InfixToPostfix}
#include "stack&queue/ArithmeticOperation/infixtoprefix.cpp"
// {class InfixToPretfix}
#include "stack&queue/validparenthesis.cpp"
// {class CheckValidParenthesis}
#include "stack&queue/nge.cpp"
// {class NGE}
#include "stack&queue/nextSmallerElelement.cpp"
// {class NextSmallerElement}
#include "stack&queue/trappingRainwater.cpp"
// {class TrapRainwater}
#include "stack&queue/sumofsubarraymin.cpp"
// {class sumofsubarraymin}
#include "stack&queue/astoriodCollision.cpp"
// {class astoriodCollision}
#include "stack&queue/sumofsubarrayrange.cpp"
// {class SubarrayRange}
#include "stack&queue/removekdigit.cpp"
// {class RemoveKDigit}
#include "stack&queue/largestRectangleinHistogram.cpp"
// {class LargestRectangle}
#include "stack&queue/maximalRectangle.cpp"
// {class MaximalRectangle}
#include "stack&queue/slidingWindowMaximal.cpp"
// {class SlidingWindowMax}
#include "stack&queue/stockSpanner.cpp"
// {class StockSpanner}
#include "stack&queue/celebrityProblem.cpp"
// {class Celebrity}
#include "stack&queue/LRUCache.cpp"
// {class LRUCache}
#include "stack&queue/LFUCache.cpp"
// {class LFUCache}
    int main() {
        // vector<int>arr;
        // int n;cin>>n;
        // for (int i = 0; i < n; i++)
        // {
        //     /* code */
        //     int ele;
        //     cin>>ele;
        //     arr.push_back(ele);
        // }
        LFUCache l1(2);
        l1.put(1,1);
        l1.put(2,2);
        cout<<l1.get(1)<<endl;
        l1.put(3,3);
        cout<<l1.get(2)<<endl;
        cout<<l1.get(3)<<endl;
        l1.put(4,4);
        l1.put(5,5);
        cout<<l1.get(5)<<endl;
        cout<<l1.get(1)<<endl;
        cout<<l1.get(3)<<endl;
        l1.put(6,6);
        cout<<l1.get(5)<<endl;
        l1.put(7,7);
        cout<<l1.get(4)<<endl;

        


        
        // int n,m;
        // cin>>n>>m;
        // vector<vector<int>> mat(n);
        // for(int i = 0 ;i<n;i++){
        //     for(int j = 0 ; j<m;j++){
        //         int ele;
        //         cin>>ele;
        //         mat[i].push_back(ele);
        //     }
        // }
        
        // Celebrity c1;
        // cout<<c1.celebrityOptimal(mat);
    
        // for(auto it: mat){
        //     for(char ele:it){
        //         cout<<ele<<" ";
        //     }
        //     cout<<endl;
        // }
        return 0;
    }