class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode* rightChild=root->right;
        TreeNode* lastRight=findLastRight(root->left);

        lastRight->right=rightChild;

        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root) {
        if (!root->right)
            return root;

        return findLastRight(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val==key)
            return helper(root);
        if (key<root->val)
            root->left=deleteNode(root->left, key);
        else
            root->right=deleteNode(root->right, key);
        return root;
    }
};