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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZag;
        if(root==nullptr) return zigZag;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* newNode=q.front();
                q.pop();
                if(newNode->left!=nullptr) q.push(newNode->left);
                if(newNode->right!=nullptr) q.push(newNode->right);
                level.push_back(newNode->val);
            }
            zigZag.push_back(level);
        }
        int n=zigZag.size();
        for(int i=0;i<n;i++){
            if(i%2==0) continue;
            else reverse(zigZag[i].begin(),zigZag[i].end());
        }
        return zigZag;
    }
};