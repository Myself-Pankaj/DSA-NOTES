#include "LLCreation.cpp"
#include <bits/stdc++.h>
using namespace std;

class SortLL{
    Node*merge(Node*h1,Node*h2){
        Node*dummy = new Node(-1);
        Node*current = dummy;
        Node*t1 = h1;
        Node*t2 = h2;
        while(t1 && t2){
            if(t1->data <t2->data){
                current->next= t1;
                current = t1;
                t1 =t1->next;
            }else {
                current->next = t2;
                current = t2;
                t2 = t2->next;
            }
            if(t1) current->next = t1;
            else current->next= t2;
        }
        return dummy->next;
    }
    Node*findMiddle(Node*head){
        Node*fast = head;
        Node*slow = head;
        while(fast->next && fast->next->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    public:
    Node*sort(Node*head){
        if(head ==nullptr || head->next ==nullptr) return head;
        Node*mid = findMiddle(head);
        Node*lefthead = head;
        Node*righthead = mid->next;
        mid->next = nullptr;
        lefthead = sort(lefthead);
        righthead = sort(righthead);

        return merge(lefthead,righthead);
    }

    //Sort 0 1 and 2
    Node *sortList(Node *head) {
        Node*temp = head;
        Node*onehead = new Node(-1);
        Node*one = onehead;
        Node*twohead = new Node(-1);
        Node*two = twohead;
        Node*zerohead = new Node(-1);
        Node*zero = zerohead;

        while(temp){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
            }else if(temp->data ==1){
                one->next = temp;
                one = temp;
            }else{
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        zero->next = onehead->next ? onehead->next : twohead->next;
        one->next = twohead->next;
        two->next = nullptr;
       
        delete onehead;
        delete twohead;
        return zerohead->next;
    }};