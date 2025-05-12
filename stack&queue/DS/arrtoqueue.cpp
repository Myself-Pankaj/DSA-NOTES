#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int max_size,start,end,curr_size;
    public:
    Queue(int size){
        this->max_size = size;
        start = -1;
        end = -1;
        curr_size = 0;
        arr = new int[max_size];
    }
    void push(int val){

        if(curr_size >= max_size){
            cout << "Queue is full unable to push { " << val << " } Exit...\n";
            return;
        }
        if(end ==-1){
        start = 0;
        end = 0;
        }else end = (end+1)%max_size;
        
        
            curr_size++;
            arr[end] = val;
        
    }
    int pop(){
        if(curr_size ==0){
            start = -1;
            end = -1;
            cout<<"Queue is empty unable to pop  Exit code ";
        }else{
            int ele = arr[start];
            start = (start+1)%max_size;
            curr_size--;
            return ele;
        }
        return -1;
    }
    int top(){
        // cout<<start<<endl;
        if(curr_size ==0){
            cout<<"Queue is empty Exit code ";
            return -1;
        }
        int element = arr[start];
        return element;
    }
    int size(){
        return curr_size;
    }
    bool isEmpty(){
        if(curr_size ==0) return true;
        return false;
    }

};