/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fh(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l = fh(root->left);
        int r =fh(root->right);
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {

        if(root==nullptr)return true;
        int left = fh(root->left);
        int right =fh(root->right);
        if(abs(right-left)>1){
            return false;
        }
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};