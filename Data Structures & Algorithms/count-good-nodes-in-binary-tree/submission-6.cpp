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
        int res = 0;
        if(!root)
            return res;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty()){
            auto [node, m] = q.front();
            q.pop();
            if(node->val >= m)
                res++;
            if(node->left)
                q.push({node->left, max(m, node->val)});
            if(node->right)
                q.push({node->right, max(m, node->val)});
        }
        return res;
    }
};
