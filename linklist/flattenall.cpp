#include<bits/stdc++.h>
using namespace std;
#ifndef LISTNODE_H
#define LISTNODE_H
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode* child;

    ListNode(int val,ListNode*nextnode,ListNode*childnode){
        data = val;
        next=nextnode;
        child = childnode;
    }
    ListNode(int val){
        data =val;
        next =nullptr;
        child =nullptr;
    }
    ListNode(int val,string s,ListNode*node){
        data = val;
        if(s == "child"){
            child = node;
        }else{
            next = node;
        }
    }
};
#endif
