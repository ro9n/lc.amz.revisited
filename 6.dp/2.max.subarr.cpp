/**
 * @file 2.max.subarr
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday February 06 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = -INF, best = -INF;
    for (auto k : nums) {
      if (sum + k < k) sum = k;
      else sum += k;
      best = max(best, sum);
    }

    return best;
  }
};
