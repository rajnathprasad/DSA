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
    int level=0;
    vector<TreeNode*> v;
    void f(TreeNode* root,int level){
        if(root==nullptr) return;
        if(level==v.size()) v.push_back(root);
        f(root->right, level+1);
        f(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        f(root,level);
        vector<int> ans;
        for(auto it:v){
            ans.push_back(it->val);
        }
        return ans;
    }
};