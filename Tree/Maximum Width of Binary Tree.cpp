class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        unsigned long long maxWidth=0;
        q.push({root,0});
        while(!q.empty()){
            unsigned long long l=q.front().second;
            unsigned long long r=q.back().second;
            maxWidth = max(maxWidth,r-l+1);
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front().first;
                unsigned long long idx=q.front().second;
                q.pop();
                if(curr->left) q.push({curr->left,2*idx+1});
                if(curr->right) q.push({curr->right,2*idx+2});
            }
        }
        return (int)maxWidth;
    }
};