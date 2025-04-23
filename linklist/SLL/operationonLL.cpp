#include "LLCreation.cpp"
#include <bits/stdc++.h>
using namespace std;

class operationOnLL{
    public:
    Node* deleteOperation(Node* head, int ind) {
        if (head == nullptr || head->next == nullptr) return head;
    
        // If we're deleting the first node (index 1)
        if (ind == 1) {
            Node* del = head;
            head = head->next;
            delete del;
            return head;
        }
    
        Node* temp = head;
        int ctr = 1;
        while (temp && temp->next) {
            if (ctr == ind - 1) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                break; // stop after deleting
            }
            temp = temp->next;
            ctr++;
        }
    
        return head;
    }
    Node * insertOperation(int ind,int val,Node*head){
        if (ind == 1) {
            Node* newNode = new Node(val);
            newNode->next = head;
            return newNode;
        }

        int ctr  =1;

        Node*temp = head;
        while(temp!=NULL){
            if(ctr ==ind-1){
                Node * nextNode = temp->next;
                Node*newNode = new Node(val);
                temp->next = newNode;
                newNode ->next = nextNode;
                break;
            }
            ctr++;
            temp = temp->next;
        }
        return head;
    }
    
};