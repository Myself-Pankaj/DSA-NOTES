#include<bits/stdc++.h>
using namespace std;
#include "flattenall.cpp"

class AtoFLL{
    public:
    ListNode* convertArraytoFLL(vector<pair<int, vector<int>>>& arr) {
        if (arr.empty()) return nullptr;

        // Initialize head node (it can be dummy)
        ListNode* head = new ListNode(-1);  // Dummy head
        ListNode* current = head;

        // Iterate through each pair
        for (int i = 0; i < arr.size(); i++) {
            // Create new node for the current element
            ListNode* newNode = new ListNode(arr[i].first);
            current->next = newNode; // Link it to the list
            current = newNode;  // Move to the new node

            // Now handle the child nodes
            ListNode* childCurrent = nullptr;
            for (int j = 0; j < arr[i].second.size(); j++) {
                ListNode* newChild = new ListNode(arr[i].second[j]);
                if (!childCurrent) {
                    newNode->child = newChild; // First child
                } else {
                    childCurrent->next = newChild;  // Link child nodes
                }
                childCurrent = newChild; // Move child pointer forward
            }
        }

        return head->next;  // Return actual head (not the dummy head)
    }

    void printMultilevelLL(ListNode* head) {
        vector<ListNode*> topNodes;
    
        // First, collect all top-level nodes
        ListNode* temp = head;
        while (temp) {
            topNodes.push_back(temp);
            temp = temp->next;
        }
    
        // Print the top-level values
        for (auto node : topNodes) {
            if (node)
                cout << node->data << "\t";
            else
                cout << "\t";
        }
        cout << endl;
    
        // Now print children level by level
        bool hasChild = true;
        while (hasChild) {
            hasChild = false;
            for (auto &node : topNodes) {
                if (node && node->child) {
                    cout << node->child->data << "\t";
                    node->child = node->child->next; // Move child pointer
                    hasChild = true;
                } else {
                    cout << "\t";
                }
            }
            cout << endl;
        }
    }
    ListNode* flattenLL(ListNode*head){
        vector<int>arr;
        ListNode*temp = head;
        while(temp){
            ListNode*t2 = temp;
            while(t2){
                arr.push_back(t2->data);
                t2 = t2->child;
            }
            temp = temp->next;
        }
        sort(arr.begin(),arr.end());
        if (arr.empty()) return nullptr;
        int n = arr.size();
        ListNode*newhead = new ListNode(arr[0]);
        ListNode*current = newhead;
        for(int i = 1;i<n;i++){
            ListNode*newnode = new ListNode(arr[i]);
            current->next = newnode;
            current->child = nullptr;
            current = newnode;
        }
        current->child = nullptr;
        return newhead;
    }
};

class mainFun{
    public:
    void intmain(int n,vector<pair<int,vector<int>>> & list){
        for(int i = 0 ; i<n;i++){
            int firstele;
            cin>>firstele;
            int m;
            cin>>m;
            vector<int>arr;
            for(int j =0;j<m;j++ ){
                int arrele;
                cin>>arrele;
                arr.push_back(arrele);
            }
            list.push_back({firstele,arr});
        }
    }
};