#include "LLCreation.cpp"
#include<bits/stdc++.h>
using namespace std;

class FindIntersection{
    private:
    Node*collisionPoint(Node*shead,Node*lhead,int d){
        Node*t1 = shead;
        Node*t2 = lhead;

        while(d){
            t2 = t2->next;
            d--;
        }
        while(t1->next && t2->next){
            if(t1 == t2){
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return nullptr;
    }
    public:
    Node *getIntersectionNodeBrute(Node *headA, Node *headB) {
        Node*t1 = headA;
        Node*t2 = headB;

        unordered_map<Node*,int>mpp;
        while(t1){
            mpp[t1]++;
            t1 = t1->next;
        }

        while (t2)
        {
            /* code */
            if(mpp.find(t2)!=mpp.end()){
                return t2;
            }
            t2 = t2->next;
        }
        return nullptr;
    }
    Node *getIntersectionNodeBetter(Node *headA, Node *headB) {
        Node*t1 = headA;
        Node*t2 = headB;
        int len1=0; int len2=0;
        while (t1)
        {
            /* code */
            len1++;
            t1=t1->next;
        }
        while (t2)
        {
            /* code */
            len2++;
            t2=t2->next;
        }
        if(len1<len2){
            return collisionPoint(headA,headB,len2-len1);
        }
        return collisionPoint(headB,headA,len1-len2);
    }
    
    Node *getIntersectionNodeOptimal(Node *headA, Node *headB) {
        Node*t1 = headA;
        Node*t2 = headB;
        while (t1 != t2) {
            t1 = (t1 != nullptr) ? t1->next : headB;
            t2 = (t2 != nullptr) ? t2->next : headA;
        }
    //If the lists intersect, the pointers will eventually meet at the intersection point.

    //If they don’t intersect, both will reach nullptr at the same time and exit.
        return t1;
    }
};