class Solution {
public:
    int dfs(TreeNode* root, int curr){
        if(root==nullptr) return 0;
        curr=curr*10+root->val;
        if(root->left==nullptr && root->right==nullptr) return curr;
        return dfs(root->left, curr) + dfs(root->right, curr); 
    }
    int sumNumbers(TreeNode* root){
        return dfs(root,0);
    }
};