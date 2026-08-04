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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> res;
        queue<TreeNode*> q;
        map<int, int> tracker;
        int level = 0;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(!tracker.contains(level)){
                    tracker[level] = node->val;
                }
                
                if(node->right){
                    q.push(node->right);
                }

                if(node->left){
                    q.push(node->left);
                }
            }
            level++;
        }

        for(auto& [level, val] : tracker){
            res.push_back(val);
        }
        return res;
    }
};
