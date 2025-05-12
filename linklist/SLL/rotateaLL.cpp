#include<bits/stdc++.h>
using namespace std;
#include "LLCreation.cpp"

class Rotate{
    public:
    Node*rotateLL(Node*head,int k){
        if(head == nullptr || head->next == nullptr || k==0) return head;

        Node*temp = head;

        int size = 1;

        while(temp->next!=nullptr){
            size++;
            temp = temp->next;
        }
       k = k%size;
       if(k == 0) return head;
       int stopper = size-k;

       Node*current = head;
       int ctr = 1;//2
       while(current){
        if(ctr == stopper)break;
        ctr++;
        current = current->next;
       }
       Node*newhead = current->next;
       temp->next = head;
       current->next= nullptr;

        return newhead;
    }
};
