// Check if Two Arrays Are Equal: if two arrays contain the same elements

class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map <int, int> mpp;
        for(int i=0;i<a.size();i++){
            mpp[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            mpp[b[i]]--;
        }
        for(auto it : mpp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
        
    }
};

// TC : O(n)
// SC : O(n)