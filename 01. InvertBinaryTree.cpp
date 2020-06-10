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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        
        helperSolve(root,root->left,root->right);
        
        return root;
    }
    
    void helperSolve(TreeNode* root, TreeNode* left, TreeNode* right){
        root->left = right;
        root->right = left;
        
        if(left != NULL){
            helperSolve(left,left->left,left->right);
        }
        if(right != NULL){
            helperSolve(right,right->left,right->right);
        }
    }
};