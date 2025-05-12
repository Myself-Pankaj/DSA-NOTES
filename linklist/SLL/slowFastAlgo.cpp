#include "LLCreation.cpp"
#include <bits/stdc++.h>
using namespace std;

class SlowFast{
    public:
    Node* middleOfLL(Node*head){
        Node*slow = head;
        Node*fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next)return slow->next;
        return slow;
    }
    bool detectCycle(Node*head){
        if(head == nullptr)return false;

        Node*slow = head;
        Node*fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
    int detectCycleI(Node*head){
        Node*temp = head;
        unordered_map<Node*,int>mpp;
        int ctr = 0;
        while(temp){
            if(mpp.find(temp)!=mpp.end()){
                return mpp[temp];
            }
            mpp[temp] = ctr;
            ctr++;
            temp=temp->next;
        }
        return -1;
    }
    Node* detectCycleIOptimal(Node*head){
        Node*slow = head;
        Node*fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow= slow->next;
                    fast= fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
    int lengthOfLoop(Node*head){
        Node*slow = head;
        Node*fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = slow->next;
                int ctr =1;
                while(slow!=fast){
                    ctr++;
                    slow= slow->next;
                }
                return ctr;
            }
        }
        return -1;
    }

    
};