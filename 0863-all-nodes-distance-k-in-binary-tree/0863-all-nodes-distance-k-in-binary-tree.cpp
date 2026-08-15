/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void makeparent(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,TreeNode*>&mp){
    if(root==NULL) return;
    mp[root]=parent;
    makeparent(root->left,root,mp);
    makeparent(root->right,root,mp);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        makeparent(root,NULL,parent);
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited.insert(target);
        int dist=0;
        while(!q.empty()){
            int size=q.size();
          if(dist==k){
            vector<int>ans;
            while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
          }
          while(size--){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && !visited.count(node->left)){
                q.push(node->left);
                visited.insert(node->left);
            }
             if(node->right && !visited.count(node->right)){
                q.push(node->right);
                visited.insert(node->right);
            }
             if(parent[node] && !visited.count(parent[node])){
                q.push(parent[node]);
                visited.insert(parent[node]);
            }
          }
          dist++;
        }
        return {};
    }
};