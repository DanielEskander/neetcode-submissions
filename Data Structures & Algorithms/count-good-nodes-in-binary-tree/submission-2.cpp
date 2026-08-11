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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty()){
            auto [node, m] = q.front();
            q.pop();
            if(node->val >= m) res++;
            if(node->left) q.push({node->left, max(node->val,m)});
            if(node->right) q.push({node->right, max(node->val,m)});
        }
        return res;
    }
};
