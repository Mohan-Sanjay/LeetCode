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
    void pretraversal(TreeNode* root,TreeNode* &tail,TreeNode* &temp)
    {
        if(!root) return ;
        pretraversal(root->left,tail,temp);
        TreeNode* now=new TreeNode(root->val,NULL,NULL);
        if(!tail) 
            temp=tail=now;
        else
        {
            tail->right=now;
            tail=now;
        }
        pretraversal(root->right,tail,temp);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        TreeNode* tail=NULL,*temp=NULL;
        pretraversal(root,tail,temp);
        return temp;
    }
};