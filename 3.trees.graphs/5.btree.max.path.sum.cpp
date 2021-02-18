/**
 * @file 5.btree.max.path.sum
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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

typedef TreeNode t;
#define ld left
#define rd right

int best;
int mx(t *r) {
  if (!r)
    return 0;

  int mxl = max(0, mx(r->ld)), mxr = max(0, mx(r->rd));

  best = max(best, r->val + mxl + mxr);
  return r->val + max(mxl, mxr);
}

class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    best = -1e4;
    mx(root);
    return best;
  }
};