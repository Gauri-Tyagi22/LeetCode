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
TreeNode* build(vector<int>& preorder, int& index, long long lower, long long upper) {
        if(index == preorder.size())
            return NULL;

        int value = preorder[index];

        if(value <= lower || value >= upper)
            return NULL;

        TreeNode* root = new TreeNode(value);
        index++;

        root->left = build(preorder, index, lower, value);
        root->right = build(preorder, index, value, upper);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         int index = 0;
        return build(preorder, index, LLONG_MIN, LLONG_MAX);
    }
};