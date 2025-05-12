#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }

    Node(int val, Node* nextPtr) {
        data = val;
        next = nextPtr;
    }
};

#endif // NODE_H
