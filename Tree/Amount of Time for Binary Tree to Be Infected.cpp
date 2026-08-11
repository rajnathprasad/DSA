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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visited;
    TreeNode* startNode;
    void preorder(TreeNode* root,int start){
        if(root==nullptr) return;
        if(root->val==start) startNode=root;
        if (root->left){
            parent[root->left]=root;
            preorder(root->left, start);
            }
        if (root->right){
            parent[root->right]=root;
            preorder(root->right, start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==nullptr) return 0;
        preorder(root, start);
        int mins=0;
        queue<TreeNode*> q;
        q.push(startNode);
        visited.insert(startNode);
        while(!q.empty()){
            int levelSize = q.size();
            while(levelSize--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent[node] && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            if (!q.empty()) mins++;
        }
        return mins;
    }
};