class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
        TreeNode* target=root;
        while(true){
            if(target->val<val){
                if(target->right!=nullptr)
                    target=target->right;
                else{
                    target->right= new TreeNode(val);
                    break;}
            }
            else{
                if(target->left!=nullptr)
                    target=target->left;
                else{
                    target->left=new TreeNode(val);
                    break;}
            }
        }
        return root;
    }
};