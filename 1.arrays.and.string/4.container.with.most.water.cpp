/**
 * @file 4.container.with.most.water
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday February 15 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& h) {
    int n = h.size(),
        l = 0, r = n - 1,
        best = 0;

    while (l < r) {
      best = max(best, min(h[l], h[r]) * (r - l));
      if (h[l] < h[r]) ++l;
      else --r;
    }

    return best;
  }
};
