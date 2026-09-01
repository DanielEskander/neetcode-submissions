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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        stack<pair<TreeNode*, int>> s;
        s.push({root, -1});
        while(!s.empty()){
            auto [node, val] = s.top();
            s.pop();

            if(val != -1 && node->val <= val) return false;

            if(node->right) s.push({node->right, max(val, node->val)});
        }

        s.push({root, -1});
        while(!s.empty()){
            auto [node, val] = s.top();
            s.pop();

            if(val != -1 && node->val >= val) return false;
            if(val == -1) val = node->val;

            if(node->left) s.push({node->left, min(val, node->val)});
        }
        return true;   
    }
};
