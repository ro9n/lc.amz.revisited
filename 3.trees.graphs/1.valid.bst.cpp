/**
 * @file 1.valid.bst
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday February 06 2021
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

typedef TreeNode t;
#define ld left
#define rd right

bool valid(t* r, t* mx, t* mn) {
  if (!r)
    return 1;
  else if (mx && r->val >= mx->val)
    return 0;
  else if (mn && r->val <= mn->val)
    return 0;
  else
    return valid(r->ld, r, mn) & valid(r->rd, mx, r);
}

class Solution {
 public:
  bool isValidBST(TreeNode* root) { return valid(root, 0, 0); }
};
