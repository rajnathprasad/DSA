class Solution {
  public:
    int minValue(Node* root) {
        // code here
        while(root!=nullptr){
            if(root->left==nullptr) break;
            root=root->left;
        }
        return root->data;
    }
};