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
    Node* removeNthnodefromback(Node*head,int n){
        Node*temp = head;
        int len = 0;
        while(temp){
            len++;
            temp=temp->next;
        }
        int ind = len-n+1;

        if(ind ==1) {
            Node*newhead = head->next;
            delete(head);
            return newhead;
        }
        
        int ctr=1;
        temp= head;
        Node*prev = temp;
        while(temp){
            if(ctr == ind) break;
            ctr++;
            prev = temp;
            temp= temp->next;
        }
      
        if(len ==ind){
            prev->next = nullptr;
            delete(temp);
            return head;
        }
        if(temp && temp->next){
            Node* nextnode = temp->next;
            prev->next = nextnode;
            delete(temp);
        }
        
        return head;
    }
    Node*reverseLL(Node*head){
        if(head == NULL) return head;
            stack<int>st;
            Node*temp = head;
            while(temp){
                st.push(temp->data);
                temp=temp->next;
            }
            Node*newhead = new Node(-1);
            Node*mover = newhead;
            while(!st.empty()){
                int t = st.top();
                st.pop();
            Node*newnode = new Node(t);
            mover->next = newnode;
            mover = newnode;
            }
            
            return newhead->next;

    }
    Node* reversLLoptimal(Node*head){
        Node * temp = head;

        Node* prev = NULL;

        while(temp != NULL){
            Node* nextNode = temp->next;
            temp->next = prev;
            prev =temp;
            temp = nextNode;
        }
       return prev;
    }
    Node* reverseLLRecursive(Node*head){
        if(head == nullptr && head->next == nullptr){
            return head;
        }
        Node*newhead = reverseLLRecursive(head->next);
        Node*front = head->next;
        front->next = head;
        head->next = nullptr;

        return newhead;
    }
    Node* deleteMiddle(Node* head) {
        if(head == nullptr) return head;
        if(head->next ==nullptr){
            delete head;
            return nullptr;
        }
        Node*slow = head;
        Node*fast = head;

        Node*prev = nullptr;

        cout<<slow->data<<endl;
        while(fast->next && fast->next->next){
            prev = slow;
            slow = slow->next;
            fast= fast->next->next;
        }
        if(fast->next == nullptr){
            Node*nextnode = slow->next;
            prev->next = nextnode;
            delete slow;
        }else{
            Node*nextnode = slow->next->next;
            Node*nodetobedeleted = slow->next;
            slow->next = nextnode;
            delete nodetobedeleted;
        }
        return head;
    }
};