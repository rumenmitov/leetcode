#include <algorithm>
#include <cassert>


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};


class Solution {
private:
  void traverse(TreeNode *root) {
    assert(root != nullptr);

    int current_val = root->val, children_val = 0;

    if (root->left) {
      TreeNode* left = root->left;

      traverse(left);
      
      children_val += left->val;

      if (left->left) current_val += left->left->val;
      if (left->right) current_val += left->right->val;
    }

    if (root->right) {
      TreeNode* right = root->right;

      traverse(right);
      
      children_val += right->val;

      if (right->left) current_val += right->left->val;
      if (right->right) current_val += right->right->val;
    }

    root->val = std::max(current_val, children_val);
    return;
  }
    
  
public:
  int rob(TreeNode *root) {
    if (!root) return 0;

    traverse(root);
    return root->val;
  }
};
