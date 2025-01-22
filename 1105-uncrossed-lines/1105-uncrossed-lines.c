int find(int i,int j,int n1,int n2,int *nums1,int *nums2,int dp[][n2])
{
    if(i>=n1 || j>=n2) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(nums1[i]==nums2[j]) return dp[i][j]=1+find(i+1,j+1,n1,n2,nums1,nums2,dp);
    return dp[i][j]=fmax(find(i+1,j,n1,n2,nums1,nums2,dp),find(i,j+1,n1,n2,nums1,nums2,dp));
}
int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dp[nums1Size][nums2Size];
    for(int i=0;i<nums1Size;i++)
       for(int j=0;j<nums2Size;j++) dp[i][j]=-1;
    return find(0,0,nums1Size,nums2Size,nums1,nums2,dp);
}