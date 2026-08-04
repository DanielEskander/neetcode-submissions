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
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});
        while(!s.empty()){
            pair<TreeNode*, int> node = s.top();
            s.pop();

            
            if(node.first->val >= node.second) res++;

            if(node.first->left) s.push({node.first->left, max(node.first->val, node.second)});
            if(node.first->right) s.push({node.first->right, max(node.first->val, node.second)});
        }
        return res;
    }
};
