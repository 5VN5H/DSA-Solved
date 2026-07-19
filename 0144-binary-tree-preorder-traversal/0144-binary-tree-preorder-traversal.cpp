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
    // void preorder(TreeNode *root, vector<int>&arr){
    //     if(root==nullptr){
    //         return;
    //     }

    //     arr.push_back(root->val);

    //     preorder(root->left,arr);

    //     preorder(root->right,arr);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     preorder(root,ans);
    //     return ans;
    // }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> st;
        if(root==nullptr){
            return {};
        }

        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);
            
            if(node->right){
                st.push(node->right);
            }
            if(node->left){
                st.push(node->left);
            }
        }
        return ans;
    }

};