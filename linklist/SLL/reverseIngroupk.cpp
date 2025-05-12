#include "LLCreation.cpp"
#include<bits/stdc++.h>
using namespace std;

class ReversingInKGroup{
    Node*reverse(Node*head){
        Node*temp = head;
        Node*newhead = nullptr;
        while(temp){
            Node*nextnode = temp->next;
            temp->next = newhead;
            newhead = temp;
            temp = nextnode;
        }
        return newhead;
    }
    
    public:
    Node* reversingink(Node*head,int k){
        Node*temp = head;
        Node*h1 = temp;
        int ctr = 1;
        while (temp)
        {
            /* code */
            if(ctr==k){
                Node*nextnode = temp->next;
                temp->next = nullptr;
                Node*newhead = reverse(h1);
                h1->next = nextnode;
                h1 = nextnode;ctr =1;
            }
            ctr++;
            temp = temp->next;
        }
        return head;
    }
};