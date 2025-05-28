#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class deleteNode
{
private:
    /* data */
public:
   TreeNode* deleteaNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode*curr =root;
        TreeNode*prev =nullptr;

        while(curr){
            if(curr->val ==key)break;
            prev = curr;
            
            if(curr->val>key){
                curr = curr->left;
            }else{
                curr = curr->right;
            } 
        }
        if(!curr) return root;
        TreeNode*leftpart = curr->left;
        TreeNode*rightpart = curr->right;
        
        //case where both are  null
        if (!leftpart && !rightpart) {
            if (!prev) {
                delete curr;
                return nullptr;
            }

            if (prev->left == curr) prev->left = nullptr;
            else prev->right = nullptr;

            delete curr;
            return root;
        }
        //case where left is null
        
        if (!leftpart && rightpart) {
            if (!prev) {
                delete curr;
                return rightpart;
            }
        
            if (prev->left == curr) prev->left = rightpart;
            else prev->right = rightpart;
        
            delete curr;
            return root;
        }
        //case where right is null
        if (leftpart && !rightpart) {
            if (!prev) {
                delete curr;
                return leftpart;
            }

            if (prev->left == curr) prev->left = leftpart;
            else prev->right = leftpart;

            delete curr;
            return root;
        }

        //case where both are not null
        TreeNode* succ = curr->right;
        TreeNode* succParent = curr;
        
        while (succ->left) {
            succParent = succ;
            succ = succ->left;
        }
        curr->val = succ->val;
        if (succParent->left == succ) {
            succParent->left = succ->right;
        } else {
            succParent->right = succ->right;
        }
        delete succ;
        return root;
    }
};

