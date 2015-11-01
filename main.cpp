/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root -> right == NULL && root -> left == NULL) return true;
        if((root -> right == NULL && root -> left != NULL) || (root -> left == NULL && root -> right != NULL)) return false;
        //main
        stack<TreeNode*> leftstk, rightstk;
        leftstk.push(root->left);
        rightstk.push(root->right);
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while( !leftstk.empty()){
            if(left != NULL && right != NULL){
                if(left->val != right->val) return false;
                leftstk.push(left);
                rightstk.push(right);
                left = left -> left;
                right = right -> right;
            }else if(left == NULL && right == NULL){
                left = leftstk.top();
                right = rightstk.top();
                if(left->val != right->val) return false;
                left = left -> right;
                right = right -> left;
                leftstk.pop();
                rightstk.pop();
            }else{
                return false;
            }
        }
        return true;
    }
};
