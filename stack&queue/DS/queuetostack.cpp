#include "lltoqueue.cpp"
#include <bits/stdc++.h>
using namespace std;

class QTOS{
    
    LLQueue q1;
    public:
    void push(int val){
        
            int n = q1.size();
            q1.push(val);
            for (int  i = 0; i < n; i++)
            {
                /* code */
                q1.push(q1.top());
                q1.pop();
            }  
        
    }
    int pop(){
        if(isEmpty()) throw underflow_error("queue is empty");
        int data = q1.top();
        q1.pop();
        return data;
    }
    int top(){
        if(isEmpty()) throw underflow_error("queue is empty");
        return q1.top();
    }
    int size(){
        return q1.size();
    }
    bool isEmpty(){
        return q1.size() ==0;
    }
};


