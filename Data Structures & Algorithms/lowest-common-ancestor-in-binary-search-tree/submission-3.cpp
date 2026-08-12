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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return root;

        if(root->left && (p->val < root->val && q->val < root->val)){
            return dfs(root->left, p, q);
        }

        if(root->right && (p->val > root->val && q->val > root->val)){
            return dfs(root->right, p, q);
        }

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
