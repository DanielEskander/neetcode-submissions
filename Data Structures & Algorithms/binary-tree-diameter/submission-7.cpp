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
        if(!root) return 0;

        unordered_map<TreeNode*, pair<int, int>> tracker;
        tracker[nullptr] = {0,0};
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            if(node->left && !tracker.contains(node->left)){
                s.push(node->left);
            }
            else if(node->right && !tracker.contains(node->right)){
                s.push(node->right);
            }
            else{
                s.pop();
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
