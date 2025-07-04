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
    void changetree(TreeNode* root)
    {
        if(!root) return ;
        if(!root->left and !root->right)
            return;
        TreeNode * temp=root->left;
        root->left=root->right;
        root->right=temp;
        changetree(root->left);
        changetree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        changetree(root);
        return root;
    }
};