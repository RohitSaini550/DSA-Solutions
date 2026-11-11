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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int>ds;
        vector<vector<int>> ans;
        queue<TreeNode*>q;

        if(root == NULL) return ans;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                ans.push_back(ds);
                ds.clear();

                if(q.empty()){
                    break;
                    }
                else{ 
                    q.push(nullptr);
                }
            }
            else{
                ds.push_back(curr -> val);
                if(curr -> left != NULL){
                    q.push(curr-> left);
                }
                if(curr -> right != NULL){
                    q.push(curr -> right);
                }
            }
        }
        return ans;
    }
};