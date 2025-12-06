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
    bool checkValid(TreeNode* root, long minVal, long maxVal){

        if(root==NULL) return true;

        if(root->val >= maxVal || root->val <= minVal) return false;

        return checkValid(root->left, minVal, root->val) && checkValid(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {

        return checkValid(root, LONG_MIN, LONG_MAX);
    }
};