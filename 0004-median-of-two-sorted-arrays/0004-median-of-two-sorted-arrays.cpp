class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=0,k=0;
        int f=0,s=0;
        while(k<=(n1+n2)/2 && i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                f=s;
                s=nums1[i++];
            }
            else
            {
                f=s;
                s=nums2[j++];
            }
            k++;
        }
        while(k<=(n1+n2)/2 && i<n1)
        {
            f=s;
            s=nums1[i++];
            k++;
        }
        while(k<=(n1+n2)/2 && j<n2)
        {
            f=s;
            s=nums2[j++];
            k++;
        }    
        double d=1.0*(s);
        if((n1+n2)%2==0)
            d=(d+f)/2;
        return d;
    }
};