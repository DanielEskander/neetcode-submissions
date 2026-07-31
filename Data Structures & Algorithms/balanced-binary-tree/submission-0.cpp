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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        unordered_map<TreeNode*, int> depths;
        depths[nullptr] = 0;
        stack<TreeNode*> dfs;
        dfs.push(root);

        while(!dfs.empty()){
            TreeNode* node = dfs.top();
            if(node->left && !depths.contains(node->left)){
                dfs.push(node->left);
            }
            else if(node->right && !depths.contains(node->right)){
                dfs.push(node->right);
            }
            else{
                dfs.pop();

                int left = depths[node->left];
                int right = depths[node->right];
                if(abs(left - right) > 1) return false;
                depths[node] = 1 + max(left, right);
            }
        }
        return true;
    }
};
