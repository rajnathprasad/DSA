class Solution {
public:
    int findLeftHeight( TreeNode* root){
        int hgt=0;
        while(root){
            hgt++;
            root=root->left;
        }
        return hgt;
    }
    int findRightHeight( TreeNode* root){
        int hgt=0;
        while(root){
            hgt++;
            root=root->right;
        }
        return hgt;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        if(lh==rh) return (1<<lh)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};