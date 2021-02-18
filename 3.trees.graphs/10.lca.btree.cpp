/**
 * @file 10.lca.btree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday February 07 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef TreeNode t;
#define ld left
#define rd right

struct TreeNode {
  int       val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return 0;
    else if (root == p)
      return p;
    else if (root == q)
      return q;

    t *l = lowestCommonAncestor(root->ld, p, q),
      *r = lowestCommonAncestor(root->rd, p, q);

    if (l && r) return root;
    else if (l)
      return l;
    else
      return r;
  }
};
