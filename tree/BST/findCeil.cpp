#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class findCeil
{
private:
    /* data */
    
public:
    TreeNode*findingCeil(TreeNode*root,int k){
       
        TreeNode*curr = root;TreeNode*ceil = new TreeNode(INT_MAX);
        while(curr){
            if(curr->val >k){
                if(curr->val<ceil->val){
                    ceil = curr;
                }
                curr= curr->left;
            }
            else if(curr->val<k){
                curr=curr->right;
            }
            else{
                ceil = curr;
                break;
            }
        }
        return ceil;
    }
TreeNode* findingFloor(TreeNode* root, int k) {
    TreeNode* curr = root;
    TreeNode* floor = nullptr;

    while (curr) {
        if (curr->val == k) {
            return curr;
        }
        if (curr->val < k) {
            floor = curr; 
            curr = curr->right;
        } else {
            curr = curr->left; 
        }
    }

    return floor;
}
   
    
};

