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
  TreeNode* build(vector<int>&inorder,vector<int>&postorder,int l,int r){
      if(l>r) return NULL;
      int rootval=postorder[pre--];
      TreeNode* root=new TreeNode(rootval);
      int mid=find(inorder,l,r,rootval);
       root->right=build(inorder,postorder,mid+1,r);
      root->left=build(inorder,postorder,l,mid-1);
     
      return root;
  }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int m=postorder.size();
      pre=m-1;
return build(inorder,postorder,0,inorder.size()-1);
    }
};