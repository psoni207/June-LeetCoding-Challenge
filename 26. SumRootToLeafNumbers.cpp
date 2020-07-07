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
    private:
    int res = 0;
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        helperSum(root, 0);
        return res;
    }
    
    void helperSum(TreeNode *root, int sum){
        if(!root->left && !root->right){
            res += sum*10 + root->val;
            return;
        }
        
        if(root->left){
            helperSum(root->left, sum*10 + root->val);
        }
        if(root->right){
            helperSum(root->right, sum*10 + root->val);
        }
    }
};