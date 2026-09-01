/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    int max_sum;
    int solve(Node *root){
        if(root==nullptr) return INT_MIN;
        
        if (root->left == nullptr && root->right == nullptr)
        return root->data;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if (root->left && root->right) {
            max_sum = max(max_sum, left + right + root->data);
            return max(left, right) + root->data;
        }
        
        if (root->left)
        return left + root->data;
        
        return right + root->data;
    }
    int maxPathSum(Node *root) {
        // code here
        max_sum=INT_MIN;
        solve(root);
        return max_sum;
    }
};