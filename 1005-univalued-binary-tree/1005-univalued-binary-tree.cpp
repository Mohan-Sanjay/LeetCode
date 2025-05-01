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
    void finduni(TreeNode* root,bool &b,int v)
    {
        if(!root or !b) return ;
        if(root->val != v)
        {
            b=false;
            return;
        }
        finduni(root->left,b,v);
        finduni(root->right,b,v);
    }
    bool isUnivalTree(TreeNode* root) {
        bool b=true;
        finduni(root,b,root->val);
        return b;
    }
};