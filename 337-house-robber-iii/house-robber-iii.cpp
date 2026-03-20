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
    unordered_map<TreeNode*, vector<int>> mpp;
    int solve(TreeNode* root, int take, int sum){
        if(take==1){
            sum += root->val;
        }

        if(mpp.count(root) && mpp[root][take] != -1) return mpp[root][take];

        int right = 0;
        if(root->right!=nullptr){
            if(take==0){
                right = max(solve(root->right, !take, 0), solve(root->right, take, 0));
            }
            else{
                right = solve(root->right, !take, 0);
            }
        }

        int left = 0;
        if(root->left!=nullptr){
            if(take==0){
                left = max(solve(root->left, !take, 0), solve(root->left, take, 0));
            }
            else{
                left = solve(root->left, !take, 0);
            }
        }
        if(!mpp.count(root)) mpp[root] = vector<int>(2, -1);
        return mpp[root][take] = sum + right + left;
    }

    int rob(TreeNode* root) {

        if(root==nullptr) return 0;

        return max(solve(root, 1, 0), solve(root, 0, 0));        
    }
};