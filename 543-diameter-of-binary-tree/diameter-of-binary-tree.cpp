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
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = height(root ->left);
        int rightHeight = height(root -> right);

        int totalHeight = max(leftHeight,  rightHeight) + 1;

        return totalHeight;
    }

    int diameter(TreeNode * root){
        if(root == nullptr) return 0;

        int diam1 = diameter(root -> left);
        int diam2 = diameter(root -> right);
        int diam3 = height(root -> left) + height(root -> right);

        int total = max(max(diam1 , diam2),diam3);
        return total;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        return diameter(root);
    }
};