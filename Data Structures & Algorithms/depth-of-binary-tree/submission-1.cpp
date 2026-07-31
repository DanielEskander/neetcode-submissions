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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> tracker;
        tracker.push(root);
        int level = 0;
        while(!tracker.empty()){
            int size = tracker.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = tracker.front(); tracker.pop();
                if(node->left) tracker.push(node->left);
                if(node->right) tracker.push(node->right);
            }
            level++;
        }
        return level;
    }
};
