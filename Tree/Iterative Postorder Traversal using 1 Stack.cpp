#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class solution{
    public:
        vector<int> postOrderTraversal(TreeNode* root){
            vector<int> postOrder;
            if(root==nullptr) return postOrder;
            stack<TreeNode*> st;
            TreeNode* cur = root;
            TreeNode* temp = nullptr;
            while(!st.empty() || cur!=nullptr){
                if(cur!=nullptr){
                    st.push(cur);
                    cur=cur->left;
                }else{
                    temp=st.top()->right;
                    if(temp==nullptr){
                        temp=st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                        while(!st.empty() && temp==st.top()->right){
                            temp=st.top();
                            st.pop();
                            postOrder.push_back(temp->val);
                        }
                    }else{
                        cur=temp;
                    }
                }
            }
            return postOrder;
        }
};