#include "LLCreation.cpp"
#include<bits/stdc++.h>
using namespace std;

class addTwoLL{
    public:
    Node* add2ll(Node*l1,Node*l2){
        Node*t1 = l1;
        Node*t2 = l2;
        Node*temp = new Node(-1);
        Node*head = temp;
        int carry = 0;
        while(t1 && t2){
            int sum = t1->data+t2->data+carry;
            int rem = sum%10;int que = sum/10;
            carry = que;
            Node*newnode = new Node(rem);
            temp->next = newnode;
            temp = newnode;
            t1 = t1->next;
            t2 = t2->next;

        }
        while(t1){
            int sum = t1->data+carry;
            int rem = sum%10;int que = sum/10;
            carry = que;
            Node*newnode = new Node(rem);
            temp->next = newnode;
            temp = newnode;
            t1 = t1->next;
        }
        while(t2){
            int sum = t2->data+carry;
            int rem = sum%10;int que = sum/10;
            carry = que;
            Node*newnode = new Node(rem);
            temp->next = newnode;
            temp = newnode;
            t2 = t2->next;
        }
        if(carry){
            Node* newnode = new Node(carry);
            temp->next = newnode;
        }
        return head->next;
    }

    Node* add2lloptimal(Node* l1, Node* l2) {
        Node* temp = new Node(-1);
        Node* head = temp;
        int carry = 0;
    
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->data; l1 = l1->next; }
            if (l2) { sum += l2->data; l2 = l2->next; }
    
            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }
    
        return head->next;
    }
    
};