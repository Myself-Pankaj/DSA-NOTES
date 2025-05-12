#ifndef LLSTACK_H
#define LLSTACK_H
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;


class LLStack{
    Node*top;

    int curr_size;
    public:
    LLStack(){
       this->top = nullptr;
       this->curr_size = 0;
    }
    void push(int val){
        Node* newnode = new Node(val);
        newnode->next = top;
        top = newnode;
        curr_size++;
    }
    int pop(){
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        int data = top->data;
        Node*temp = top;
        
        top = top->next;
        delete temp;
        curr_size--;
        return data;
    }
    int peek(){
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return top->data;
    }
    int size(){
        return curr_size;
    }
    bool isEmpty(){
        if(curr_size ==0) return true;
        return false;
    }
};

#endif