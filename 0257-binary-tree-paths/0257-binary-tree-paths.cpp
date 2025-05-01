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
    void makeconnections(TreeNode *root,string c,vector<string>&s)
    {
        if(!root) return;
        if(c=="") c=to_string(root->val);
        else c+="->"+to_string(root->val);
        if(!root->left and !root->right)
            s.push_back(c);
        makeconnections(root->left,c,s);
        makeconnections(root->right,c,s);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {""};
        vector<string>s;
        makeconnections(root,"",s);
        return s;
    }
};