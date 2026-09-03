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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        if(!root)
            return res;
        queue<TreeNode*> q;
        priority_queue<int, vector<int>, greater<int>> minQue;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            minQue.push(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        while(k > 0){
            res = minQue.top();
            minQue.pop();
            k--;
        }
        return res;
    }
};
