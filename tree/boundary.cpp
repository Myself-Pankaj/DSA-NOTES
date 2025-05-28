#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class boundary
{
private:
    /* data */
    bool isLeaf(TreeNode*node){
    if(node->left || node->right) return false;
    return true;
}
void pickLeaf(TreeNode*root,vector<int>&res){
    if(!root) return ;

    if(isLeaf(root))res.push_back(root->val);
    pickLeaf(root->left,res);
    pickLeaf(root->right,res);

}
public:
    vector <int> boundaryNodes(TreeNode* root){
    	//ans array
        vector<int>res;
        if(!root) return res;
        //leftnode
        TreeNode*curr = root;
        while(curr){
            if(!isLeaf(curr))res.push_back(curr->val);
            if(curr)curr = curr->left;
            else curr = curr->right;
        }
        pickLeaf(root,res);
        curr = root;
        stack<int>st;
        while(curr){
            if(!isLeaf(curr) && curr != root)st.push(curr->val);
            if(curr)curr = curr->right;
            else curr = curr->left;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
