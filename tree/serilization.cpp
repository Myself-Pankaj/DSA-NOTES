#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class Codec {
    private:
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();
            if(!node){
                res+="#,";
            }else{
                res+= to_string(node->val)+ ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.empty()){
            return nullptr;
        }
        stringstream iss(data);
        string token;

        getline(iss,token,',');

        TreeNode*root = new TreeNode(stoi(token));

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(iss,token,',');

            if(token !="#"){
                TreeNode *leftnode = new TreeNode( stoi(token));
                node->left= leftnode;
                q.push(leftnode);
            }

            getline(iss,token,',');

            if(token !="#"){
                TreeNode *rightnode = new TreeNode( stoi(token));
                node->right= rightnode;
                q.push(rightnode);
            }

        }
        return root;
    }
};