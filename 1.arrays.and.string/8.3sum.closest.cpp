/**
 * @file 8.3sum.closest
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday February 15 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int n    = nums.size(),
        best = INF,
        ans  = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
      for (int l = i + 1, r = n - 1; l < r;) {
        int sum  = nums[i] + nums[l] + nums[r],
            diff = abs(target - sum);

        if (diff < best) best = diff, ans = sum;
        if (sum > target) --r;
        else if (sum < target)
          ++l;
        else
          return target;
      }
    }

    return ans;
  }
};
