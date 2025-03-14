class Solution {
public:
    int find(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp)
    {
        if(i>=nums1.size() || j>=nums2.size())  
            return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if(nums1[i]==nums2[j]) 
            return dp[i][j]=1+find(i+1,j+1,nums1,nums2,dp);
        return dp[i][j]=max(find(i+1,j,nums1,nums2,dp),find(i,j+1,nums1,nums2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        return find(0,0,nums1,nums2,dp);
    }
};