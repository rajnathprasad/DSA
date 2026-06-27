// 14. Find Intersection of Two Arrays: Find the common elements between two arrays.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> s(nums2.begin(),nums2.end());
        unordered_set <int> result;
        for(int i=0;i<nums1.size();i++){
            if(s.count(nums1[i])){
                result.insert(nums1[i]);
            }
        }
        return vector<int>(result.begin(),result.end());
    }
};

TC : O(n+m)
SC : O(m)