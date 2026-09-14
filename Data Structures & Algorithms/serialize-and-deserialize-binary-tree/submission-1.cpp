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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "N#";
        return to_string(root->val) + '#' + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return dfs(data, i);
    }

    TreeNode* dfs(string& data, int& i){
        if(data[i] == 'N'){
            i += 2;
            return nullptr;
        }

        int j = i;
        while(data[j] != '#') j++;
        TreeNode* root = new TreeNode(stoi(data.substr(i, j - i)));
        j++;
        i = j;
        root->left = dfs(data, i);
        root->right = dfs(data, i);
        return root;
    }
};
