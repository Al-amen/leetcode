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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        dfsDiameter(root,maxDiameter);
        return maxDiameter;
    }

    int dfsDiameter(TreeNode* root, int &maxDiameter) {
        if(root == nullptr)return 0;
        int lh = dfsDiameter(root->left,maxDiameter);
        int rh = dfsDiameter(root->right,maxDiameter);
        maxDiameter = max(maxDiameter, lh+rh);

        return 1 + max(lh,rh);
    }
};