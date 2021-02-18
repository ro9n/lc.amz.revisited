/**
 * @file 12.min.window.substr
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday February 16 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

const int INF = 1e6 + 7;

class Solution {
 public:
  string minWindow(string text, string pattern) {
    int n = text.size(),
        m = pattern.size(),
        c = 0,
        L = -1,
        R = n,
        frq[60];

    memset(frq, 0x0, sizeof(int) * 52);

    for (int i = 0; i < m; ++i) ++frq[pattern[i] - 65];

    for (int l = 0, r = 0; r < n; ++r) {
      int k = text[r] - 65;
      if (--frq[k] >= 0) {  // required character
        ++c;                // inc char count in window
      }
      while (c == m) {
        // consider window for best
        if (r - l < R - L) L = l, R = r;
        int k2 = text[l++] - 65;
        if (++frq[k2] > 0) --c;  // required char now outside window
      }
    }

    return ~L ? text.substr(L, R - L + 1)
              : "";
  }
};
