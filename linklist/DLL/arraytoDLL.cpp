#include "DLLCreation.cpp"
#include<bits/stdc++.h>
using namespace std;

class AtoDLL{
    public:
    LinkNode* convertToDll(vector<int>&arr){
        int n = arr.size();
        LinkNode * head = new LinkNode(arr[0]);
        LinkNode *mover = head;
        for(int i =1;i<n;i++){
            LinkNode *temp = new LinkNode(arr[i]);
            temp->prev = mover;
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
    void PintDLL(LinkNode *head){
        LinkNode *temp = head;
        while (temp)
        {
            /* code */
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"NULL\n";     
    }

};