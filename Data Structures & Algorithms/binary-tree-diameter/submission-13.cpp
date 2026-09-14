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
        unordered_map<TreeNode*, pair<int, int>> m;
        m[nullptr] = {0, 0};
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            if(node->left && m.find(node->left) == m.end()){
                s.push(node->left);
            }
            else if(node->right && m.find(node->right) == m.end()){
                s.push(node->right);
            }
            else{
                s.pop();

                auto [leftHeight, leftDia] = m[node->left];
                auto [rightHeight, rightDia] = m[node->right];

                int height = 1 + max(leftHeight, rightHeight);
                int dia = max(leftHeight + rightHeight, max(leftDia, rightDia));
                m[node] = {height, dia};
            }
        }
        return m[root].second;
    }
};
