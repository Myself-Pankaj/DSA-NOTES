#include "treenode.cpp"
#include<bits/stdc++.h>
using namespace std;

class timeToBurnTree
{
private:
    /* data */
    TreeNode* marking_parent(TreeNode*root,int target,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(!root) return root;
        TreeNode* targetnode = nullptr;
        queue<TreeNode*>q;
        q.push(root);
        mpp[root] = root;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i<n;i++){
                TreeNode*node = q.front();
                q.pop();
                if(node->val == target) targetnode = node;
                if(node->left){
                    mpp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    mpp[node->right] = node;
                    q.push(node->right);
                }
            }           
        }
        return targetnode;
    }
public:
    int timeToBurnATree(TreeNode* root, int start){
            //your code goes here
        int time = 0;
        if(!root) return time;
        unordered_map<TreeNode*,TreeNode*>mpp;
        unordered_map<TreeNode*,bool>visited;
        TreeNode*targetnode = marking_parent(root,start,mpp);

        queue<TreeNode*>q;
        q.push(targetnode);
        visited[targetnode] = true;
        while(!q.empty()){
            int n = q.size();
            time++;
            for (int i = 0; i < n; i++)
            {
                /* code */
                TreeNode*node = q.front();
                visited[node] = true;
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    
                }
                if(node->right &&!visited[node->right]){
                    q.push(node->right);
                    
                }
                if(mpp[node] && !visited[mpp[node]]){
                    q.push(mpp[node]);
                }
            }
            
        }
        return time-1;
	}
};


