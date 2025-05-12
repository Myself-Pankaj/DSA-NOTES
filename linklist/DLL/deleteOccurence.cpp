#include "DLLCreation.cpp"
#include <bits/stdc++.h>
using namespace std;

class  DeleteOccurence{
    public:
    LinkNode*deleteOccurence(LinkNode*head,int data){
        LinkNode*temp = head;
        if(temp == nullptr) return nullptr;
      
        while (temp) {
            LinkNode* mover = temp->next;
    
            if (temp->val == data) {
                // Case 1: head node
                if (temp->prev == nullptr) {
                    head = temp->next;
                    if (head) head->prev = nullptr;
                    delete temp;
                }
                // Case 2: tail node
                else if (temp->next == nullptr) {
                    temp->prev->next = nullptr;
                    delete temp;
                }
                // Case 3: middle node
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
            }
    
            temp = mover;
        }
        return head;
    }
};