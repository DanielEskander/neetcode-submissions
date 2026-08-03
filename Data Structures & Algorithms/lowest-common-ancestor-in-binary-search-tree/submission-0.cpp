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
        TreeNode* res = root;
        queue<TreeNode*> qu;
        qu.push(res);

        while(!qu.empty()){
            TreeNode* node = qu.front();
            qu.pop();
            if(max(p->val, q->val) < node->val && node->left){
                qu.push(node->left);
            }
            else if(min(p->val, q->val) > node->val && node->right){
                qu.push(node->right);
            }
            else if(node == p || node == q){
                return node;
            }
            else{
                res = node;
                // if(node->left) qu.push(node->left);
                // if(node->right) qu.push(node->right);
            }
        }
        return res;
    }
};
