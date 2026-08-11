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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;

        queue<TreeNode*> qp;
        queue<TreeNode*> qq;
        qp.push(p);
        qq.push(q);
        while(!qp.empty() && !qq.empty()){
            TreeNode* pnode = qp.front();
            TreeNode* qnode = qq.front();
            qp.pop(); qq.pop();
            if(!pnode && !qnode) continue;
            if(!pnode || !qnode ||
                (pnode->val != qnode->val)) return false;
            
            qp.push(pnode->left);
            qq.push(qnode->left);
            qp.push(pnode->right);
            qq.push(qnode->right);
        }
        return true;
    }
};
