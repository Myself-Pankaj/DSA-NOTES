#include <bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int capacity;
    int top;

    public:
    Stack(int maxSize){
        top = -1;
        arr = new int[maxSize];
        this->capacity = maxSize;
    }

    void push(int val){
       
        if(top>=capacity- 1){
            cout<<"Stack is full unable to push { " <<val<<" } Exit...";  
        }else{
            top++;
            arr[top] = val;
        }
    }
    int pop(){
        if(top<0){
            cout<<"Stack has no element Exit code. ";
            return -1;
        }
        int element = arr[top];
        top--;
        return element;
    }
    int peek(){
        if(top<0){
            cout<<"Stack has no element Exit code. ";
            return -1;
        }
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        if(top == -1) return true;
        return false;
    }
};