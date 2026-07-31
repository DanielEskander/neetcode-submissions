/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        queue<TreeNode*> tracker;
        tracker.push(root);
        while(!tracker.empty()){
            TreeNode* tmp = tracker.front(); tracker.pop();
            if(tmp->left) tracker.push(tmp->left);
            if(tmp->right) tracker.push(tmp->right);
            swap(tmp->left, tmp->right);
        }
        return root;
    }
};
