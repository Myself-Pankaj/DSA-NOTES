#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class kthsmallest
{
private:
    /* data */
public:
//take inorder array and return k-1 index value 
     int kthSmallest(TreeNode* root, int k) {
   
       TreeNode* curr = root;
        int count = 0;

    while (curr) {
        if (!curr->left) {
            count++;
            if (count == k-1) return curr->val;
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if (!pred->right) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = nullptr;
                curr = curr->right;
                count++;
                if (count == k-1) return curr->val;
            }
        }
    }

    return -1;
    }
};


