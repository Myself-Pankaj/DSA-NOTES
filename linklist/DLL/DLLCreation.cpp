#ifndef LINKNODE_H
#define LINKNODE_H


class LinkNode{
    public:
    int val;
    LinkNode *  prev;
    LinkNode * next;

    LinkNode(int data,LinkNode*prevptr,LinkNode*nextptr){
        val = data;
        prev = prevptr;
        next = nextptr;
    }
    LinkNode(int data){
        val = data;
        next=nullptr;
        prev=nullptr;
    }
};

#endif 