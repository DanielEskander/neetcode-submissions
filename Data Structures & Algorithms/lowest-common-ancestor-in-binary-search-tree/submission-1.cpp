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
        queue<TreeNode*> que;
        TreeNode* res = root;
        que.push(res);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(max(p->val, q->val) < node->val && node->left){
                que.push(node->left);
            }
            else if(min(p->val, q->val) > node->val && node->right){
                que.push(node->right);
            }
            else{
                return node;
            }
        }
        return res;
    }
};
