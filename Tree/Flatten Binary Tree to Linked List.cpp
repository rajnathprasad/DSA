class Solution {
public:
    TreeNode* flattenSub(TreeNode* root){
        if(root==nullptr) return nullptr;

        TreeNode* LT=flattenSub(root->left);
        TreeNode* RT=flattenSub(root->right);

        if(root->left){
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=nullptr;
            if(LT!=nullptr)
            LT->right=temp;
        }
        if(RT) return RT;
        if(LT) return LT;
        return root;

    }
    void flatten(TreeNode* root) {
        flattenSub(root);
    }
};