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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> tracker;
        stack<TreeNode*> dfs;
        tracker[nullptr] = {0, 0};

        dfs.push(root);
        while(!dfs.empty()){
            TreeNode* node = dfs.top();

            if(node->left && !tracker.contains(node->left)){
                dfs.push(node->left);
            }
            else if(node->right && !tracker.contains(node->right)){
                dfs.push(node->right);
            }
            else{
                dfs.pop();

                auto [leftHeight, leftDiameter] = tracker[node->left];
                auto [rightHeight, rightDiameter] = tracker[node->right];
                int height = 1 + max(leftHeight, rightHeight);
                int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
                tracker[node] = {height, diameter};
            }
        }
        return tracker[root].second;
    }
};
