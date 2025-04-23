#include "DLLCreation.cpp"
#include <bits/stdc++.h>
using namespace std;

class operationOnDLL{
    public:
    LinkNode * reverseDLL(LinkNode * head){
        LinkNode *temp = head;
        LinkNode *newHead = nullptr;

        while(temp!=NULL){
            LinkNode *newnode = temp->next;
            temp->next = newHead;
            temp->prev = newnode;
            newHead = temp;
            temp= newnode;
        }

        return newHead;
    }
    LinkNode *insertionOperation(LinkNode*head,int ind,int val){
        if(head ==nullptr) return head;
        if(ind == 1 ){
            LinkNode* newHead = head->next;
            if (newHead) newHead->prev = nullptr;
            delete head;
            return newHead;
        };
        
        LinkNode *temp = head;
        int ctr = 1;
        while(temp && ctr<ind){
            ctr++;
            temp= temp->next;
        }
        if(temp == nullptr) return head;
        LinkNode* newnode = new LinkNode(val);
        LinkNode*nextnode = temp->next;

        newnode->next= nextnode;
        newnode->prev = temp;
        temp->next= newnode;

        if(nextnode) nextnode->prev = newnode;
        return head;
    }

    LinkNode *deletionOperation(LinkNode*head,int ind){
        if (head == nullptr || ind < 1) return head;

        if (ind == 1) {
           LinkNode* newHead = head->next;
           if (newHead) newHead->prev = nullptr;
           delete head;
           return newHead;
        }
        LinkNode* temp = head;
        int ctr = 1;
        while(temp && ctr<ind){
            
            ctr++;
            temp= temp->next;
        }
        if(temp == nullptr) return head;
        LinkNode* prevNode = temp->prev;
        LinkNode* nextNode = temp->next;

        if (prevNode) prevNode->next = nextNode;
        if (nextNode) nextNode->prev = prevNode;
        delete(temp);
        return head;
    }
};