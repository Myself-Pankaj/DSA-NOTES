#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class constructATree
{
private:
    /* data */
    TreeNode * makeTree(vector<int>& inorder, vector<int>& postorder,
    int p_start,int i_start,int p_end,int i_end,unordered_map<int,int>&mpp
    ){
        if(p_start>p_end || i_start>i_end) return nullptr;

        int inroot = mpp[postorder[p_end]];
        int l_out = inroot - i_start;
        TreeNode* root = new TreeNode(postorder[p_end]);

        root->left = makeTree(inorder, postorder, p_start, i_start, p_start + l_out - 1, inroot - 1, mpp);

        root->right = makeTree(inorder, postorder, p_start + l_out, inroot + 1, p_end - 1, i_end, mpp);


        return root;
    }

    TreeNode* makeTree1(vector<int>&pre, vector<int>&in,int i_start,int i_end,
        int p_start,int p_end,unordered_map<int,int>&mpp){
            if(i_start > i_end || p_start>p_end) return nullptr;

            TreeNode*root = new TreeNode(pre[p_start]);
            int i_root = mpp[root->val];
            int l_out = i_root-i_start;

            root->left = makeTree1(pre,in,i_start,i_root-1,p_start+1,p_start+l_out,mpp);
            root->right = makeTree1(pre,in,i_root+1,i_end,(p_start+1)+l_out,p_end,mpp);

            return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= inorder.size();
        int m = postorder.size();
        if( n!= m){
            return nullptr;
        }
        unordered_map<int,int>mpp;
        for(int i = 0 ; i<n;i++){
            mpp[inorder[i]] = i;
        }
        return makeTree(inorder,postorder,0,0,n-1,m-1,mpp);
    }
     TreeNode* buildTree1(vector<int>& inorder, vector<int>& preorder) {
        int n = inorder.size();
        int m = preorder.size();
        if(n!=m) return nullptr;

        unordered_map<int,int>mpp;
        for (int i = 0; i < n; i++)
        {
            /* code */
            mpp[inorder[i]] = i;
        }
        return makeTree1(preorder,inorder,0,n-1,0,m-1,mpp);
        
    }
};


