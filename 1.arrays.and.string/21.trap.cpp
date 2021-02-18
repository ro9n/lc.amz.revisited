/**
 * @file 21.trap
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
  int trap(vector<int>& h) {
    int ans = 0;
    for (int n = h.size(),
             l = 0,
             r = n - 1,
             L = 0,
             R = n - 1;
         l < r;) {
      if (h[l] < h[r]) {
        ans += max(0, min(h[L], h[R]) - h[l]);
        if (h[++l] > h[L]) L = l;
      } else {
        ans += max(0, min(h[L], h[R]) - h[r]);
        cout << h[R] << ' ' << h[r] << endl;
        if (h[--r] > h[R]) R = r;
      }
    }

    return ans;
  }
};
