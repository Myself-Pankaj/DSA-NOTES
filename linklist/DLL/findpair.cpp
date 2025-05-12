#include "DLLCreation.cpp"
#include <bits/stdc++.h>
using namespace std;

class FindPair{
    public:
    vector<pair<int,int>> findingPairs(LinkNode*head,int target){
        LinkNode* start = head;
        LinkNode* end = head;

        
        vector<pair<int,int>>validPairs;
        while(end->next != nullptr){
            end = end->next;
        }
       
        while (start->val<=end->val && start != nullptr && end != nullptr)
        {
            /* code */
            int sum = start->val +end->val;
            if(sum > target){
                end= end->prev;
            }else if(sum< target){
                start = start->next;
            }else{
                validPairs.push_back({start->val,end->val});
                end = end->prev;
                start = start->next;
            }
        }
        return validPairs;
    }
};