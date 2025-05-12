#include "LLCreation.cpp"
#include<bits/stdc++.h>
using namespace std;

class OddEvenLL{
    public:
    Node* oddevengrouping(Node*head){
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;
        Node*temp = head;

        Node*t1 = new Node(-1);
        Node*h1 = t1;
        Node*t2 = new Node(-1);
        Node*h2 = t2;
        int ctr = 1;
        while(temp){
            if(ctr %2 !=0){
                Node*newnode = new Node(temp->data);
                t1->next = newnode;
                t1 = newnode;
            }else{
                Node*newnode = new Node(temp->data);
                t2->next = newnode;
                t2 = newnode;
            }
            ctr++;
            temp = temp->next;
        }
        t1->next = h2->next;

        return h1->next;
    }
    Node* oddevengroupingOptimal(Node*head){
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;
        Node*temp = head;
        int ctr =1;
        Node*h1 = new Node(-1);
        Node*mid = h1;
        while(temp &&  temp->next){
            Node*nextnode = temp->next->next;
            Node*tnode = temp->next;
            if(ctr%2 !=0){
                temp->next = nextnode;
                
            }else{
                h1->next = temp;
                temp->next = nextnode;
                h1 = temp;
            }
            ctr++;
            temp = tnode;
        }
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = mid->next;
        return head;      
    }
};