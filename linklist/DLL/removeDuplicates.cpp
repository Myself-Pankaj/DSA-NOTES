#include "DLLCreation.cpp"
#include <bits/stdc++.h>
using namespace std;

class RemoveDuplicate{
    public:
    LinkNode* removeDuplicate(LinkNode*head){
        LinkNode*temp = head;
            unordered_map<int,int>mpp;
    
            while(temp){
                LinkNode * mover = temp->next;
                if(mpp.find(temp->val)!=mpp.end()){
                    if (temp->prev) temp->prev->next = temp->next;
                    if (temp->next) temp->next->prev = temp->prev;
    
                    // If temp is head node
                    if (temp == head) {
                        head = temp->next;
                    }
    
                    delete temp;
                }
                else {
                    mpp[temp->val]++;
                }
              
                temp = mover;
            }
            return head;
    }
    LinkNode* removeDuplicateOptimal(LinkNode*head){
        LinkNode*temp = head;
        int currVal = -1;
        while(temp){
            LinkNode* mover = temp->next;
            if(currVal == temp->val){
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;

                // If temp is head node
                if (temp == head) {
                    head = temp->next;
                }

                delete temp;
            }else{
                currVal = temp->val;
            }
            temp = mover;
        }
        return head;
    }
    
};