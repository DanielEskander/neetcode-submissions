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
        int res = 0;
        if(!root) return res;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty()){
            auto [node, ma] = q.front();
            q.pop();
            if(node->val >= ma){
                res++;
                ma = node->val;
            }

            if(node->left) q.push({node->left, ma});
            if(node->right) q.push({node->right, ma});
        }
        return res;
    }
};
