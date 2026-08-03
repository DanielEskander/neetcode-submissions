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

        unordered_map<TreeNode*, pair<int, int>> m;
        m[nullptr] = {0, 0};
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            
            if(node->left && !m.contains(node->left)){
                s.push(node->left);
            }
            else if(node->right && !m.contains(node->right)){
                s.push(node->right);
            }
            else{
                s.pop();
                auto [leftHeight, leftDiameter] = m[node->left];
                auto [rightHeight, rightDiameter] = m[node->right];
                int height = 1 + max(leftHeight, rightHeight);
                int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
                m[node] = {height, diameter};
            }
        }
        return m[root].second;
    }
};
