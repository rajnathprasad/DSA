class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        for(int i=0;i<n;i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        m=nums1.size();
        if(m%2){
            return nums1[m/2];
        }else{
            return (nums1[m/2-1]+nums1[m/2])/2.0;
        }
    }
};