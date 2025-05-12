#include<bits/stdc++.h>
using namespace std;


    class LFUCache
    {
    private:
        /* data */
    public:
        class Node{
            public:
            int key,val,freq;
            Node*next;
            Node*prev;
            Node(int _key,int _val){
                key = _key;
                val = _val;
                freq=1;
                next = nullptr;
                prev = nullptr;
            }
        };
        int min_freq,capacity;
        unordered_map<int,pair<Node*,Node*>>freq_list;
        unordered_map<int,Node*>mpp;
        
        LFUCache(int cap){
            capacity = cap;
            min_freq = 0;
        };
        
        void addNode(int freq,Node*node){
            if(freq_list.find(freq)== freq_list.end()){
                Node*i_head = new Node(-1,-1);
                Node*i_tail = new Node(-1,-1);
                i_head->next = i_tail;
                i_tail->prev = i_head;
                freq_list[freq] = {i_head, i_tail};

            }
                Node*head = freq_list[freq].first;
                Node*next = head->next;
                head->next = node;
                next->prev = node;
                node->next = next;
                node->prev = head;
        }

        void deleteNode(Node* node){
            Node*prev_node = node->prev;
            Node*next_node = node->next;
            prev_node->next = next_node;
            next_node->prev = prev_node;
        }

        void update_freq(Node*node){
            int curr_freq = node->freq ;
            node->freq = curr_freq+1;
            deleteNode(node);
            if(freq_list[curr_freq].first->next == freq_list[curr_freq].second){
                Node* head = freq_list[curr_freq].first;
                Node* tail = freq_list[curr_freq].second;
                freq_list.erase(curr_freq);
                delete head;
                delete tail;
                if(min_freq == curr_freq){
                    min_freq = curr_freq+1;
                }
            }

            addNode(curr_freq+1,node);
            mpp[node->key] = node; 
        }

        int get(int key) {
            if(mpp.find(key)!=mpp.end()){
                Node*node = mpp[key];
                int value = node->val;
                update_freq(node);
                return value;
            }
            return -1;
        }
        void put(int key, int value) {
            if (capacity == 0) return;
            if(mpp.find(key)!=mpp.end()){
                Node*node = mpp[key];

                node->val = value;
                update_freq(node);
            }else {
                if(mpp.size()== capacity){
                    Node*node_to_remove = freq_list[min_freq].second->prev;
                    mpp.erase(node_to_remove->key);
                    deleteNode(node_to_remove);
                    if (freq_list[min_freq].first->next == freq_list[min_freq].second) {
                    freq_list.erase(min_freq);
                    }
                    delete node_to_remove;
                }
                Node* newnode = new Node(key,value);
                mpp[key] = newnode;
                min_freq = 1;
                addNode(min_freq,newnode);
            }
        }   
    };


