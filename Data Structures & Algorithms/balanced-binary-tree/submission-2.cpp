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
    bool res;
    int dfs(TreeNode* root){
        if(!root) return 0;

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if(abs(leftHeight - rightHeight) > 1) res = false;
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        res = true;
        dfs(root);
        return res;
    }
};
