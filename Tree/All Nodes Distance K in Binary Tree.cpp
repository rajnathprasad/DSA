class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parents;
    vector<int> ans;
    unordered_set<TreeNode*> visited;
    void inOrder(TreeNode* root){
        if(root==nullptr) return;
        if(root->left!=nullptr)
        parents[root->left]=root;
        if(root->right!=nullptr)
        parents[root->right]=root;
        inOrder(root->left);
        inOrder(root->right);
    }
    void findK(TreeNode* target, int k){
        if(target==nullptr || k<0 || visited.count(target)) return;
        visited.insert(target);
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        auto it = parents.find(target);
        if(it != parents.end())
        findK(it->second, k-1);
        findK(target->left,k-1);
        findK(target->right,k-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inOrder(root);
        findK(target, k);
        return ans;
    }
};