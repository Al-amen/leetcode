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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
       unordered_map<int, TreeNode*> mp;
       unordered_map<int,int>child, parent;

       for(auto d : descriptions) {
         if(mp.find(d[0]) == mp.end()) {
            TreeNode* create = new TreeNode(d[0]);
            mp[d[0]] = create;
         }
         if(mp.find(d[1]) == mp.end()) {
            TreeNode* create = new TreeNode(d[1]);
            mp[d[1]] = create;
         }
         if((d[2])) {
            
            mp[d[0]]->left =  mp[d[1]];
         }
         else {
             mp[d[0]]->right =  mp[d[1]];
         }
         parent[d[0]]++;
         child[d[1]]++;

       } 
       TreeNode* ans;
      for(auto it:mp)
        {
            if(parent.find(it.first)!=parent.end() && child.find(it.first)==child.end())
            {
                ans=it.second;
                break;
            }
        }
       return ans;
    }
};