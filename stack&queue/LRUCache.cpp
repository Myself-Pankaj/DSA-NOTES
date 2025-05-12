#include<bits/stdc++.h>

using namespace std;

class LRUCache
{
private:
 
    
public:
    class LinkNode
    {
        public:
        int key,val;
        LinkNode * next;
        LinkNode * prev;

        LinkNode(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
    };
    LinkNode *head = new LinkNode(-1,-1);
    LinkNode *tail = new LinkNode(-1,-1);
    int capacity;
    unordered_map<int,LinkNode*>mpp;

    void insertAfterHead(LinkNode*node){
        LinkNode * curr_node_after_head = head->next;
        node->next = curr_node_after_head;
        node->prev = head;
        head->next = node;
        curr_node_after_head->prev  = node;
    }
    void deleteaNode(LinkNode*node){
        LinkNode*after_node = node->next;
        LinkNode*before_node = node->prev;
        before_node->next = after_node;
        after_node->prev = before_node;

    }
    LRUCache(int cap){
       capacity = cap;
       head->next = tail;
       tail->prev = head;
    };

    int get(int _key) {
        if(mpp.find(_key) != mpp.end()){
            LinkNode * res_node = mpp[_key];
            int value = res_node->val;
            deleteaNode(res_node);
            insertAfterHead(res_node);

            mpp[_key] = res_node;
            return value;
        }
        return -1;
    }
    void put(int _key, int _value) {
        //check key already exist or not 
        if(mpp.find(_key) != mpp.end()){
            LinkNode* node = mpp[_key];
            node->val = _value;
            deleteaNode(node);
            insertAfterHead(node);
            mpp[_key] = node;
        }else {
            if( mpp.size()== capacity){
                LinkNode * node_to_remove = tail->prev;
                deleteaNode(node_to_remove);
                mpp.erase(node_to_remove->key);
                delete node_to_remove;
            }
        LinkNode* newnode =new LinkNode(_key,_value);
        insertAfterHead(newnode);

        mpp[_key] = head->next;
    }
    }
};


