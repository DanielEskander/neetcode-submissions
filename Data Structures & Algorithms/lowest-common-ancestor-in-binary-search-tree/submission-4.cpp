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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();

            if(node->left && (p->val < node->val && q->val < node->val))
                que.push(node->left);
            else if(node->right && (p->val > node->val && q->val > node->val))
                que.push(node->right);
            else
                return node;
        }
        return root;
    }
};
