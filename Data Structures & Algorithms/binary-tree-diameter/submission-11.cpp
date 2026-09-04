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

        stack<TreeNode*> s;
        unordered_map<TreeNode*, pair<int, int>> nodeHeights;
        nodeHeights[nullptr] = {0, 0};
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            if(node->left && nodeHeights.find(node->left) == nodeHeights.end()){
                s.push(node->left);
            }
            else if(node->right && nodeHeights.find(node->right) == nodeHeights.end()){
                s.push(node->right);
            }
            else{
                s.pop();

                auto [leftHeight, leftDiameter] = nodeHeights[node->left];
                auto [rightHeight, rightDiameter] = nodeHeights[node->right];

                int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
                int height = 1 + max(leftHeight, rightHeight);
                nodeHeights[node] = {height, diameter};
            }
        }
        return nodeHeights[root].second;
    }
};
