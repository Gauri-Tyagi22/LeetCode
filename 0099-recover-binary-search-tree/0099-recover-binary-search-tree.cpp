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
TreeNode* prev;
TreeNode * start;
TreeNode* mid;
TreeNode* last;
void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    if(prev!=NULL &&(root->val<prev->val)){
        if(start==NULL){
        start=prev;
        mid=root;
        }
    
    else last=root;
    }
    prev=root;
    inorder(root->right);
}
    void recoverTree(TreeNode* root) {
        start=mid=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(start && last) swap(start->val,last->val);
        else if(start && mid) swap(start->val,mid->val);
    }
};