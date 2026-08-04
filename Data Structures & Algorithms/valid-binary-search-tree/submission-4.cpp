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

        stack<tuple<TreeNode*, long, long>> s;
        s.push(make_tuple(root, LONG_MIN, LONG_MAX));
        while(!s.empty()){
            auto [node, left, right] = s.top();
            s.pop();

            if(!(left < node->val && node->val < right)) return false;

            if(node->right) s.push(make_tuple(node->right, node->val, right));
            if(node->left) s.push(make_tuple(node->left, left, node->val));
        }
        return true;   
    }
};
