/**
 * @file 14.product.except.self
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday February 16 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int         n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 0, pfx = 1; i < n; ++i)
      ans[i] *= pfx, pfx *= nums[i];
    for (int i = n - 1, sfx = 1; i >= 0; --i)
      ans[i] *= sfx, sfx *= nums[i];

    return ans;
  }
};