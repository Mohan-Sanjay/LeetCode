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
    void vot(TreeNode* root ,map<int,map<int,vector<int>>>& m,int hd,int l)
    {
        if(root ==NULL) return ;
        m[hd][l].push_back(root->val);
        vot(root->left,m,hd-1,l++);
        vot(root->right,m,hd+1,l++);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>m;
        vot(root,m,0,0);
        vector<vector<int>>res;
        for(auto i:m)
        {
            vector<int>v;
            for(auto j:i.second)
            {
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second) 
                   v.push_back(k);
            }
            res.push_back(v);
        }
        return res;
        
    }
};