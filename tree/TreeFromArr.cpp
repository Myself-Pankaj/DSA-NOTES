#include <bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class TreeFromArr
{
private:
    /* data */
   TreeNode* arrayToTree(vector<int>& arr, int n) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
  }
public:
   
  TreeNode* buildtree(vector<int> &arr){
    int n = arr.size();
    return arrayToTree(arr,n);
  }
};


