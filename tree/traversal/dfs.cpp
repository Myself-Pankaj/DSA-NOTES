#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class DFSTraversal
{
private:
    /* data */
public:
    void inorder_traversal(TreeNode*root){
        if(root== nullptr){
            return ;
        }
        inorder_traversal(root->left);
        cout<<root->val<<" ";
        inorder_traversal(root->right);
    }

    vector<int> inorder_iterative(TreeNode * root){
      stack<TreeNode*>st;

        vector<int>res;
        TreeNode* node =root;
      
      while(true){
        if(node!=nullptr){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node= st.top();
            st.pop();
            res.push_back(node->val);
            node = node->right;
        }
      }
      return res;
    }

    void preorder_traversal(TreeNode*root){
        if(root== nullptr){
            return ;
        }
        cout<<root->val<<" ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    vector<int> preorder_iterative(TreeNode * root){
        stack<TreeNode*>st;
        vector<int>preorder;
        st.push(root);

        while(st.empty()){
            TreeNode* node = st.top();
            st.pop();
            preorder.push_back(node->val);
            if(node->right!=nullptr){
                st.push(node->right);
            }
            if(node->left !=nullptr){
                st.push(node->left);
            }
        }
        return preorder;
    }
    
    void postorder_traversal(TreeNode*root){
        if(root== nullptr){
            return ;
        }
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout<<root->val<<" ";
    }
    vector<int> postorder_iterative(TreeNode * root){
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;

        vector<int>postorder;
        st1.push(root);

        while(!st1.empty()){
            TreeNode*node = st1.top();
            st1.pop();
            st2.push(node);

            
            if(node->left){
                st1.push(node->left);
            }
            
            if(node->right){
                st1.push(node->right);
            }
        }
        while(!st2.empty()){
            int val = st2.top()->val;
            st2.pop();
            postorder.push_back(val);
        }
        return postorder;   
    }


    //Moris Traversal

    vector<int> morisInorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode*curr = root;
        while(curr){
            if(curr->left == nullptr){
                inorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode*temp = curr->left;

                while(temp->right != nullptr && temp->right != curr ){
                    temp = temp->right;
                }
                if(temp->right == nullptr){
                    temp->right = curr;
                    curr = curr->left;
                }
                if(temp->right == curr){
                    temp->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }

    vector<int> morisPreorderTraversal(TreeNode* root) {
        vector<int>preorder;
        TreeNode*curr = root;
        while(curr){
            if(curr->left == nullptr){
               preorder.push_back(curr->val);
                curr = curr->right;
            }else{
                
                TreeNode*temp = curr->left;

                while(temp->right != nullptr && temp->right != curr ){
                    temp = temp->right;
                }
                if(temp->right == nullptr){
                    preorder.push_back(curr->val);
                    temp->right = curr;
                    
                    curr = curr->left;
                }
                else{
                    temp->right = nullptr;
                   
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};


