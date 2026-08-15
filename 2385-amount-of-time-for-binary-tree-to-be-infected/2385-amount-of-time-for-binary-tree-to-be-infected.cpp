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
int mxiinfec(map<TreeNode*,TreeNode*>mp,TreeNode* target){
    queue<TreeNode*>q;
    q.push(target);
    map<TreeNode*,int>vis;
    vis[target]=1;
    int mx=0;
    while(!q.empty()){
        int size=q.size();
        int fl=0;
        for(int i=0;i<size;i++){
            auto node=q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                vis[node->left]=1;
                fl=1;
               q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                vis[node->right]=1;
                fl=1;
               q.push(node->right);
            }
            if(mp[node] && !vis[mp[node]]){
                vis[mp[node]]=1;
                fl=1;
               q.push(mp[node]);
            }
        }
        if(fl) mx++;
    }
    return mx;
}
TreeNode* find(TreeNode* root,int start,map<TreeNode*,TreeNode*>&mp){
    queue<TreeNode*>q;
    q.push(root);
    TreeNode* res;
    while(!q.empty()){
        TreeNode* node=q.front();
        if(node->val==start) res=node;
        q.pop();
        if(node->left){
            mp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right]=node;
            q.push(node->right);
        }
    }
    return res;
}
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mp;
        TreeNode* target=find(root,start,mp);
        int mxi=mxiinfec(mp,target);
        return mxi;
    }
};