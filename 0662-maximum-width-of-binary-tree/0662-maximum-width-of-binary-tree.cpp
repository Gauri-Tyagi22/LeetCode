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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        unsigned long long ans=0;
        while(!q.empty()){
            int size=q.size();
            unsigned long long start=q.front().second;
            unsigned long long last=start;
            for(int i=0;i<size;i++){
                TreeNode* node= q.front().first;
                unsigned long long idx=q.front().second;
                q.pop();
                idx-=start;
                last=idx;
                if(node->left) q.push({node->left,2*idx+1});
                if(node->right) q.push({node->right,2*idx+2});
                ans=max(ans,last+1);
            }
        }
        return ans;
    }
};