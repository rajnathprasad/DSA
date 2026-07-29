/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int level=0;
    vector<Node*> v;
    void f(Node* root,int level){
        if(root==nullptr) return;
        if(level==v.size()) v.push_back(root);
        f(root->left, level+1);
        f(root->right, level+1);
    }
    vector<int> leftView(Node *root) {
        // code here
        f(root,level);
        vector<int> ans;
        for(auto it:v){
            ans.push_back(it->data);
        }
        return ans;
    }
};