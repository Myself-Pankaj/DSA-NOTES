#include "lltostack.cpp"
#include "bits/stdc++.h"
using namespace std;

class STOQ{
    LLStack s1,s2;

    public:
    void push(int val){
        if(s1.isEmpty()){

            s1.push(val);
        }else{
            while(!s1.isEmpty()){
                s2.push(s1.peek());
                s1.pop();                
            }
            s1.push(val);
            while (!s2.isEmpty())
            {
                /* code */
                s1.push(s2.peek());
                s2.pop();
            } 
        }
    }
    int pop(){
        if(s1.isEmpty()){
            throw underflow_error("queue is empty");
        }
        int data = s1.peek();
        s1.pop();
        return data;
    }
    int peak(){
        if(s1.isEmpty()){
            throw underflow_error("queue is empty");
        }
        return s1.peek();
    }
    int Size(){
        if(s1.isEmpty()){
            throw underflow_error("queue is empty");
        }
        return s1.size();
    }
    bool empty(){
        return s1.isEmpty();
    }
};