#include "LLCreation.cpp"
#include<bits/stdc++.h>
using namespace std;

class AtoLL{
    public:
    //Convert array to LinkList
    Node * convertAtoLL(vector<int>&arr){
        int n = arr.size();
        if(n < 0) return nullptr;
        Node* head = new Node(arr[0]);
        Node * mover = head;
    
        for(int i = 1 ; i<n;i++){
            Node*temp = new Node(arr[i]);
            mover->next= temp;
            mover = temp;
        }
        return head;
    }
    //Traverse Linklist and print it
    void PintLL(Node *head){
        Node *temp = head;
        while (temp)
        {
            /* code */
            cout<<temp->data<<" ";
            temp = temp->next;
        }     
    }
    // Length of Linklist
    int length(Node *head){
        Node*temp = head;
        int ctr = 0 ;
        while (temp)
        {
            /* code */
            ctr++;
            temp = temp->next;
        }
        cout<<"\nLength of this LL is : ";
        return ctr;
    }
    int searchInLL(Node* head, int element) {
        if (head == nullptr) {
            cout << "\nEmpty List";
            return -1;
        }
    
        Node* temp = head;
        int ctr = 1;
    
        while (temp) {
            if (temp->data == element) {
                cout << "\nElement placed at position ";
                return ctr;
            }
            temp = temp->next;
            ctr++;
        }
    
        cout << "\n404 Element Not Found ";
        return -1;
    }
    
};