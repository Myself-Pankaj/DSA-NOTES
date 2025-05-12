#ifndef LLQueue_H
#define LLQueue_H
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;


class LLQueue{
    private:
        Node* tail;
        Node* head;
        int curr_size;
    
    public:
    LLQueue() {
            head = nullptr;
            tail = nullptr;
            curr_size = 0;
        }
    
        ~LLQueue() {
            while (!isEmpty()) {
                pop();
            }
        }
    
        void push(int val) {
            Node* newnode = new Node(val);
            if (tail == nullptr) {
                head = tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
            curr_size++;
        }
    
        int pop() {
            if (isEmpty()) {
                throw underflow_error("Queue is empty");
            }
    
            int data = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            curr_size--;
    
            if (head == nullptr) {
                tail = nullptr;
            }
    
            return data;
        }
    
        int top() {
            if (isEmpty()) {
                throw underflow_error("Queue is empty");
            }
            return head->data;
        }
    
        int size() {
            return curr_size;
        }
    
        bool isEmpty() {
            return curr_size == 0;
        }
    };

#endif