#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class BSTiterator
{
private:
    /* data */
    stack<TreeNode*>st;
    bool isNext;
public:
    void pushNode(TreeNode* root) {
        while (root) {
            st.push(root);
            root = isNext ? root->left : root->right;
        }
    }
    BSTiterator(TreeNode*root,bool _isNext){
        isNext = _isNext;
        pushNode(root);
    }
    int next(){
        if (!hasNext()) {
            throw std::underflow_error("No next element");
        }
        TreeNode*node = st.top();
        st.pop();
        pushNode(isNext?node->right:node->left);
        return node->val;
    }

    bool hasNext(){
        return !st.empty();
    }
};



class twosum
{
private:
    /* data */
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator l(root,true);
        BSTiterator r(root,false);
        int left = l.next();
        int right = r.next();
        while(left<right){
            if(left+right<k){
                left = l.next();
            }else if(left+right>k){
                right = r.next();
            }else{
                return true;
            }
        }
        return false;
    }
   
};


