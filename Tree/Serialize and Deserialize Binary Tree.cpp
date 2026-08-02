/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* newNode= q.front();
            q.pop();
            if(newNode==nullptr) s.append("#,");
            else s.append(to_string(newNode->val)+",");
            if(newNode!=nullptr){
                q.push(newNode->left);
                q.push(newNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* newNode=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#") newNode->left=nullptr;
            else{
                newNode->left=new TreeNode(stoi(str));
                q.push(newNode->left);
            }
            getline(s,str,',');
            if(str=="#") newNode->right=nullptr;
            else{
                newNode->right=new TreeNode(stoi(str));
                q.push(newNode->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));