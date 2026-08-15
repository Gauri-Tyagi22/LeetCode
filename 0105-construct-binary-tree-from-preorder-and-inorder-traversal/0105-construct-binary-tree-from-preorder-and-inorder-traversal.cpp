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
int pre;
  int find(vector<int>&inorder,int l,int r,int rootval){
      for(int i=l;i<=r;i++){
          if(inorder[i]==rootval) return i;
      }
      return -1;
  }
  TreeNode* build(vector<int>&inorder,vector<int>&preorder,int l,int r){
      if(l>r) return NULL;
      int rootval=preorder[pre++];
      TreeNode* root=new TreeNode(rootval);
      int mid=find(inorder,l,r,rootval);
      root->left=build(inorder,preorder,l,mid-1);
      root->right=build(inorder,preorder,mid+1,r);
      return root;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=inorder.size();
        return build(inorder,preorder,0,n-1);    
    }
};