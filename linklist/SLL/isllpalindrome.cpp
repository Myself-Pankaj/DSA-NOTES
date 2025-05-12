#include "LLCreation.cpp"
#include<bits/stdc++.h>
using namespace std;

class isListPalindrome{
    private:
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
    public:
    bool isPalindrome(Node*head){
        Node*temp = head;
        stack<int>st;
        while(temp){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            int val = st.top();
            st.pop();
            if(temp->data != val){
                return false;
            } 
            temp= temp->next;
        }
        return true;
    }
    bool isPalindromeOptimal(Node*head){
        Node*temp = head;
        Node*slow = temp;
        Node*fast = temp;

        while(fast->next != NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
       
        Node*newhead = reversLLoptimal(slow->next);

        Node*first = head;
        Node*second = newhead;
        bool palindrome = true;
        while(second){
            if(first->data !=second->data){
                palindrome = false;
                break;
            }
            first = first->next;
            second= second->next;
        }
        slow->next = reversLLoptimal(newhead);

        return palindrome;
    }

};