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
    int count=0;
    pair<int,int>solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        auto p1=solve(root->left);
        auto p2=solve(root->right);
        int sum=p1.first+ p2.first+root->val;
        int cnt=p1.second + p2.second+1;
        if(sum/cnt==root->val){
            count++;
        }
        return {sum,cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};