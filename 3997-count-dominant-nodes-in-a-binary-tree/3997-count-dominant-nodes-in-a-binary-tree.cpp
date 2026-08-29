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

    pair<int,int> solve(TreeNode* root) {

        if (root == nullptr)
            return {INT_MIN,0};

        auto left = solve(root->left);
        auto right  =solve(root->right);

        int maxv = max(root->val
        
        
        ,max(left.first,right.first));

        int cnt  = left.second + right.second;

        if(root->val==maxv){
            cnt++;
        }

        return {maxv,cnt};
    }

    int countDominantNodes(TreeNode* root) {

        return solve(root).second;
    }
};